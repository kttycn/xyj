// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;//, old_target;

	if (userp(me) && !query_heart_beat(me))
	{
		"/cmds/usr/quithy"->main(me);
		return notify_fail("由于你没有心跳，请重新登陆!!\n");
	}

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if (userp(obj) && !query_heart_beat(obj))
	{
		write("看清楚一点，那并不是活物。\n");
		return notify_fail("此人无心跳！\n");
	}
	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已经这样了你还要打，过分了点吧？\n"); 

	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");

	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");
	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("他是你的好朋友呀，你真是薄情寡义！\n");

	if( userp(obj) ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
这个指令让你直接向一个人物「进招」。这种形式的战斗是即时的，只要玩家一
敲这个命令，战斗就会开始，直到某一方受伤50% 以上为止。这个指令对那些不
喜欢fight的NPC很有用，因为很多时候你的比武要求会被拒绝。
 
其他相关指令: fight, kill

HELP
    );
    return 1;
}
 
