// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;

void do_quit(object, object);

void create() 
{
	seteuid(getuid());
	set("channel_id", "离线指令");
}

int main(object me, string arg)
{
	object link_ob;
	int flag = 0;

	if( !me->query_temp("netdead")) 
		return notify_fail("这个指令只能由系统执行。\n");

	if (me->query_temp("quit"))
		return notify_fail("正在退出过程中，请稍候。\n");
	link_ob = me->query_temp("link_ob");

	if( link_ob ) {
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}

	if( LOGIN_D->get_madlock()) 
		return notify_fail("时空已经封闭，没有人能够退出这个时空了。\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if (interactive(me) && query_idle(me) < 10) {
	} else flag = 1;

	me->set_temp("quit", 1);
        me->set_temp("no_kill", 1);
        me->set_temp("disable_inputs",1);
	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short() + HIR " 准备离开游戏了。");
	if (!flag && !wizardp(me)) {
		write("无心跳，正在退出游戏 ,档案不保存......\n");
		call_out("do_quit", 10, me, link_ob);

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
				DROP_CMD->do_drop(me, inv[i]);
	}
	write("欢迎下次再来！\n");
	message("system", me->name() + "由于无心跳，离开游戏。\n", environment(me), me);

	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short(1) + HIR " 离开游戏了。");

	if (link_ob) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		destruct(link_ob);
	}

	if (me->query("mud_age") == me->query_temp("mud_age"))
		me->add("mud_age", 1);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")离开游戏了。\n");

	me->set_temp("quit", 0);
        me->set_temp("no_kill", 0);
        me->set_temp("disable_inputs",0);
	destruct(me);
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
