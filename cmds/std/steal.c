// steal.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, obj, victim;
	int sp, dp;
//2001.06.20 fei add
	if (me->is_busy() || me->query_temp("doing_xiudao") 
	|| me->query_temp("pending/exercising")
	|| me->query_temp("pending/meditating"))
   		return notify_fail("你现在正忙着呢。\n");
	if( !wizardp(me) && environment(me)->query("no_fight")
	||environment(me)->query("no_steal")
	||environment(me)->query("sleep_room") )
		return notify_fail("这里禁止行窃。\n");

	if( me->is_ghost() )
		return notify_fail("做了鬼了，就老实点吧！\n");
	if( me->query_temp("stealing") )
		return notify_fail("你已经在找机会下手了！\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("指令格式：steal <物品> from <人物>\n");

	if( victim = present(who, environment(me))) {
		if( userp(victim)&& userp(me) && victim->query("age")<16 )
			return notify_fail("连小孩子的东西都偷，你太没人性了!\n");
	}

	if((int)me->query("friends/"+victim->query("id")) )
		return notify_fail("他是你的好朋友呀，你真是薄情寡义！\n");

	if (userp(victim) && !query_heart_beat(victim))
	{
		write("看清楚一点，那并不是活物。\n");
		return notify_fail("此人无心跳！\n");
	}
	if( !victim || victim==me) return notify_fail("你想行窃的对象不在这里。\n");
	if(!valid_kill(me,victim,0)) return 0;

	if(me->query("daoxing")<100000 && userp(victim))
  		return notify_fail("你的道行这么差，就想去偷别人的东西吗？\n");

	if(me->query("combat_exp") <= 100000 && userp(victim))
		return notify_fail(HIR"功夫这么差就想学着偷东西吗?\n"NOR);

	set_to_killer(me,victim);

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("玩家不能偷巫师身上的东西。\n");

	if(victim->query("disable_type")=="<睡梦中>")
		return notify_fail("趁人家睡觉的时候下手？嘿嘿，你也太缺德了！\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "身上看起来没有什么值钱的东西好偷。\n");
		ob = inv[random(sizeof(inv))];
	}
	sp = (int)me->query_skill("stealing",1) * 5 +((int)me->query("kar")+(int)me->query("age"))*2
		- (int)me->query("thief") * 20;
	if( sp < 1 ) sp = 1;
	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = ((int)victim->query("sen")+(int)victim->query("age")+(int)victim->query_kar())*2+(int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("你不动声色地慢慢靠近" + victim->name() + "，等待机会下手 ...\n\n");

	me->set_temp("stealing", 1);
	me->add("steal_times",1);
	call_out( "complete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void complete_steal(object me, object victim, object ob, int sp, int dp)
{
    int no_steal;

        if(!me || !victim) return;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "太可惜了，你下手的目标已经走了。\n");
		return;
	}

        if(!ob) {
	  tell_object(me, "你要偷的东西不见了。\n");
	  return;
        }

	no_steal=(ob->query("no_give")) ||
	         (ob->query("no_drop")) ||
	         (ob->query("keep_this",1)) ||
		 (ob->query("no_get"));

	if( (!living(victim) || (random(sp+dp) > dp)) &&
	 !no_steal ) {
		if( !ob->move(me) ) {
			tell_object(me, "你摸到一" + ob->query("unit") + ob->name() 
				+ "，可是对你而言太重了，不得不放弃。\n");
			return;
		}
		tell_object(me, HIW "得手了！\n\n" NOR);
		tell_object(me, "你成功地偷到一" + ob->query("unit") + ob->name() + "！\n");
		message("channel:chat",HIR"【谣言四起】某人："+"我亲眼看到 "HIY+me->query("name")+HIR" 鬼鬼祟祟地从 "
		HIY+victim->query("name")+HIR" 身上偷走了 "HIW"一"+ ob->query("unit")+ ob->name()+" \n"NOR,users());
		me->add("thief", 1);

		if( living(victim) )
			me->improve_skill("stealing", random(me->query("int")));
		if( random(sp) < dp/2 )
			message("vision", "你看到" + me->name() + "鬼鬼祟祟地从"
				+ victim->name() + "身上偷走了一" + ob->query("unit")
				+ ob->name() + "！\n", environment(me), ({ me, victim }) );
	} else {
		if( random(sp) > dp/2 || no_steal ) {
			tell_object(me, victim->name() + "不经意地一转头，你急忙将手缩了回去！\n"
				"还好，没有被发现。\n");
			return;
		}
		tell_object(me, HIR "糟糕！你失手了！\n\n" NOR);
		message_vision("$N一回头，正好发现$n的手正抓着$P身上的" + ob->name() + "！\n\n"
			+ "$N喝道：「干什么！」\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);
		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(5);
		me->add("thief", 1);
	}
}

int help(object me)
{
write(@HELP
指令格式 : steal <某物> from <某人>

这个指令让你有机会偷到他人身上的东西。成功了, 当然你就能获得
该样物品。可是, 马有失蹄, 人总有失风的时候, 当你失败时当然就
得付出代价, 至于是什么代价......靠你自己去发掘罗。
HELP
    );
    return 1;
}
