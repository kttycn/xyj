#include <ansi.h>

int main(object me, string arg)
{
	object obj;
	int skill, count;

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想偷袭谁？\n");

	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( obj->is_fighting(me) )
		return notify_fail("你已经在战斗中了，还想偷袭？\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "都已经这样了，你还用得着偷袭吗？\n"); 

	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");

	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("他是你的好朋友呀，你真是薄情寡义！\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("你不能杀这个人。\n");

	if(obj==me)
		return notify_fail("偷袭自己？别这么想不开。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能偷袭。\n");

	if(userp(obj)) {
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
	}

	tell_object(me, RED"你飞身纵起，扑向" + obj->name() +"！\n"NOR);
	tell_object(obj, CYN"\n" + me->name() + "忽然向你扑来！\n\n"NOR);
	message("vision", CYN"\n" + me->name() + "忽然向" + obj->name() +"扑去！\n\n"NOR, environment(me), ({me, obj}) );

	count = me->query_str();

	if( random(me->query("combat_exp")) < (int)obj->query("combat_exp")/2 )
	{
		me->add_temp("str", count*4);
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		me->add_temp("str", - count*4);
	}

	else
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	}

	me->start_busy(3);
	obj->kill_ob(me);

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : touxi <人物>
 
这个指令用来向敌人偷袭。偷袭不成时，则会招至反击。
特别适合于经验低的玩家向经验高的玩家拚命。:)

其他相关指令: fight, kill, hit
HELP
    );
    return 1;
}
