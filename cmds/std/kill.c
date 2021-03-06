// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);

mapping kill=([]);
mapping query_kill() {return kill;}
void remove_list(string me, string obj);

int main(object me, string arg)
{
	object obj, guard_ob;
	string callname;//*killer, 
	int just_issued=0;

	if (userp(me) && !query_heart_beat(me))
	{
		"/cmds/usr/quithy"->main(me);
		return notify_fail("由于你没有心跳，请重新登陆!!\n");
	}

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !wizardp(me) && environment(me)->query("no_kill") )
		return notify_fail(HIR"这里不准杀人\n"NOR);

	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if(userp(obj) && (int)me->query("PKS",1)/2 > me->query("age") - 14 )
 		return notify_fail("你杀的人还不够多吗？\n");
	
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if (userp(obj) && !query_heart_beat(obj))
	{
		write("看清楚一点，那并不是活物。\n");
		return notify_fail("此人无心跳！\n");
	}
	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");
	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("连你的好朋友都杀，你真是。。。\n");

	if((int)me->query_skill("force") <= 150 && userp(obj))
		return notify_fail(HIR"你的内力这么差也想杀人吗? \n"NOR);

	if((int)me->query_skill("spells") <= 150 && userp(obj))
		return notify_fail(HIR"你的法力这么差也想杀人吗? \n"NOR);

	if((int)me->query("combat_exp") <= 200000 && userp(obj))
		return notify_fail(HIR"你的武学这么差也想杀人吗? \n"NOR);

	if((int)me->query("daoxing") <= 200000 && userp(obj))
		return notify_fail(HIR"你的道行这么差也想杀人吗? \n"NOR);

	if(userp(obj)) {
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
	}
	if(obj==me)
		return notify_fail(HIC"用"+HIR" zisha "+HIC"或 "+HIR"suicide -f"+HIC" 指令会比较快些。\n"NOR);

	if(!valid_kill(me,obj,0)) return 0;

	set_to_killer(me,obj);

	callname = RANK_D->query_rude(obj);

	//mon 5/29/99
	if(userp(me)) {
	  string myid=me->query("id");
	  string objid=obj->query("id");

	  if(undefinedp(kill[myid])) {
	    just_issued=0;
	    kill+=([myid:({objid})]);
	    call_out("remove_list",1,myid,objid);
	  } else {
	    string *targs=kill[myid];
	    if(targs && member_array(objid,targs)!=-1) {
		// just issued kill on this target recently.
		just_issued=1;
	    } else {
		// not issue kill recently.
		just_issued=0;
		if(!targs)
		    targs=({objid});
		else
		    targs+=({objid});
		kill[myid]=targs;
		call_out("remove_list",1,myid,objid);
	    }
	  }
	}

	if(just_issued==0) {
	    message_vision(HIR"\n$N对着$n"+HIR"喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n"NOR, me, obj);	
	} else {
	    // avoid too much screen rolling to the target.
	    write("\n你对着"+obj->name()+"喝道：「"
		    + callname + "！今日不是你死就是我活！」\n\n");
		   
	    return 1;
	}

	if( obj->query_temp("protected")
	&& objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
	&& (string)guard_ob->query_temp("protect")==obj->query("id")
	&& guard_ob!=me ) {
		message_vision(HIC"$N对着$n大声说：有我在此，不用担心！\n"NOR,guard_ob,obj);
		message_vision(HIC"$N冲上前去挡住了$n的攻击。\n"NOR, guard_ob, me);
		guard_ob->kill_ob(me);
		me->kill_ob(guard_ob);
	}

	do_kill(me, obj);

	return 1;
}
void do_kill(object me, object obj)
{

	me->kill_ob(obj);
	if( !userp(obj) ){
	
		if(!obj->accept_kill(me) )
		obj->kill_ob(me);

	} else if( !userp(me) ) {
		obj->kill_ob(me);
	} else {
		obj->kill_ob(me);
		tell_object(obj, HIC"如果你要和" + me->name() 
			+ HIC"性命相搏，请你也对这个人下一次"BLINK HIR" kill"+NOR HIC" 指令。\n"NOR);
	}
}

void remove_list(string me, string obj)
{
    string *targs;

    if(undefinedp(kill[me])) return;
    targs=kill[me];
    if(!targs || sizeof(targs)<2) {
	map_delete(kill, me);
    } else {
	targs-=({obj});
	kill[me]=targs;
    }
}

int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在于双方将会真刀实枪地打斗，也就是说，会真的受伤。由于 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对于一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 

