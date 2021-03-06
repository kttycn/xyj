// quit.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void do_quit(object, object);
int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
	int dx, exp, mana, force;
	object link_ob;
	int flag = 0;

	dx = me->query("daoxing")-me->query_temp("temp/daoxing");
	exp = me->query("combat_exp")-me->query_temp("temp/combat_exp");
	mana = me->query("max_mana")-me->query_temp("temp/max_mana");
	force = me->query("max_force")-me->query_temp("temp/max_force");

	if (me->query_temp("quit"))
		return notify_fail("正在退出过程中，请稍候。\n");
	link_ob = me->query_temp("link_ob");

	if(!force_quit) {
		if ( me->query_temp("no_move") )
			return notify_fail("你被定住了，哪里退得出游戏！\n");

		if(me->query_temp("quit_noway"))
			return notify_fail("你现在不能退出游戏！\n");// xintai 1/29/2001

		if(!me->query_temp("suicide_countdown")) {
			if( me->is_busy() )
				return notify_fail("( 你上一个动作还没有完成，不能退出。)\n");
		} //to allow halt suicide :D by mon 9/9/97

		if( !wizardp(me) && environment(me) && 
		environment(me)->query("no_quit") && link_ob )
			return notify_fail("这里不准退出游戏。\n");
	}

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}
	if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if( me->over_encumbranced() )
		return notify_fail("身上带的东西太多了，离不开游戏了。\n");

	if (interactive(me) && query_idle(me) < 10)
	{
		if( me->is_busy()) return notify_fail("你现在正忙着做其他事，不能退出游戏！\n");
		if( me->is_fighting()) return notify_fail("你现在正在战斗，不能退出游戏！\n");
	} else flag = 1;

	me->set_temp("quit", 1);
	me->set_temp("no_kill", 1);
	me->set_temp("disable_inputs",1);

	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short() + HIR " 准备离开游戏了。");
	if( dx>0 || exp>0 || mana>0 || force>0 )
	{
		CHANNEL_D->do_channel(this_object(), "sys",
			"\n道行增加"+dx+"点,武学经验增加"+exp+"点，法力增加"+mana+"点,内力增加"+force+"点\n");
		write(HIR"\n\n本次连线，你的");
		if(dx>0) write("道行增加"+dx+"点.");
		if(exp>0) write("武学经验增加"+exp+"点.");
		if(mana>0) write("法力增加"+mana+"点.");
		if(force>0) write("内力增加"+force+"点.");
		write("\n"NOR);
		if( (dx > 100000 || dx < -100000) && !wizardp(me))
			log_file("static/adddx",sprintf("%s(%s)增加%d点道行值 %s\n",  
				me->name(),me->query("id"),dx,ctime(time())));
		if( (exp > 100000 || exp < -100000) && !wizardp(me) )
			log_file("static/addexp",sprintf("%s(%s)增加%d点武学经验值 %s\n",  
				me->name(),me->query("id"),exp,ctime(time())));
		if( (mana > 1000 || mana < -100) && !wizardp(me) )
			log_file("static/addmana",sprintf("%s(%s)增加%d点最大法力 %s\n",  
				me->name(),me->query("id"),mana,ctime(time())));   
		if( (force > 1000 || force < -100) && !wizardp(me) )
			log_file("static/addforce",sprintf("%s(%s)增加%d点最大内力 %s\n", 
				me->name(),me->query("id"),force,ctime(time())));
	}		
	if (!flag && !wizardp(me)) {
		write("正在退出游戏 ,档案保存中......\n");
		me->set_temp("no_move", 1);
		call_out("do_quit", 2, me, link_ob);

	} else do_quit(me, link_ob);

	return 1;
}

void do_quit(object me, object link_ob)
{
	int i;
	object *inv;

	if (!me) return;
	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				do_drop(me, inv[i]);
	}

	write(MAG"你历了太多的江湖风风雨雨终于有些累了。江湖人,总是在人老之前心也就老了,
曾经叱咤过的大江南北,现在看过去竟是一片沧茫。你不禁长笑三声：兄弟们我
还会回来的，然后便怅然若失,黯然离去 ......！\n"NOR);
	me->set("lost_quit",time());
	if(!wizardp(me) || !me->query("env/invisibility"))
	tell_room(environment(me), me->query("name") + "离开这个世界。\n",me);

	if (link_ob) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}

	if (me->query("mud_age") == me->query_temp("temp/mud_age"))
		me->add("mud_age", 1);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + capitalize(me->query("id")) + ")离开游戏了。\n");
	me->delete_temp("quit");
	me->delete_temp("no_kill");
	me->delete_temp("disable_inputs");
	me->delete_temp("no_move");
	me->save();
	destruct(me);
}

int do_drop(object me, object obj)
{
    	//if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();
           
        if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
