#include <ansi.h>
//inherit SSERVER;
void select_target(object me, string name);

int cast(object me, object target)
{
	if( (string)me->query("family/family_name") != "凤凰星" 
	&& !me->query("guild") )
		return notify_fail("你并非凤凰城中人，不能运用飞行术。\n");
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用飞行术！\n");
	if( me->query_temp("pending/exercising") 
	|| me->query_temp("doing_xiudao") 
	|| me->query_temp("no_move") 
	|| me->is_busy() )
		return notify_fail("你上一个动作还没有完，不能使用飞行术！\n");
	if( !wizardp(me) && environment(me)->query("no_flying") )
		return notify_fail("这里不准施展飞行术。\n");

	if( (me->query("kee") < me->query("max_kee")/2)
	|| (me->query("gin") < me->query("max_gin")/2)
	|| (me->query("sen") < me->query("max_sen")/2) )
		return notify_fail("你的精神不好，别再乱闯一气了。\n");
	if( me->query("mana") < 150 )
		return notify_fail("你的法力不足！\n");
	if( target )
		return notify_fail("飞行术不能对自己使用！\n");
	write("你要“飞”到哪一个人身边？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{  
	int i=sizeof(name);
	object ob;
	if( !name || name=="" )
	{
		write("中止施法。\n");
		return;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("对不起，输入的NPC名字中不能用空格等无效字符。\n");
			write("中止施法。\n");
			return;
		}
	}
	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
	{
		write("你无法感受到这个人的精力 ....\n");
		write("你要“飞”到哪一个人身边？");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( userp(ob) )
	{
		write("你不可以施展飞行术到其他玩家身边。\n");
		return;
	}
	if( me->is_fighting() )
	{
		write("战斗中无法使用飞行术！\n");
		return;
	}
	else
		if( me->query("mana") < 150 )
		{
			write("你的精力不够！\n");
			return;
		}
	me->add("mana", -150);
	me->receive_damage("sen", 50);
	message_vision( HIW "$N双臂轻挥，运起飞行术，四周顿时猎猎生风，$N衣诀随风舞动……\n" NOR, me);
	if ( random( ob->query("max_mana") + (int)me->query("mana")) < 100 )
	{
		write("对方的精力不够强烈，你感受不出其具体位置。\n");
		return;
	}
	if( random(me->query_skill("spells")) < (int)ob->query("mana") / 50 )
	{
		write("你因为不够熟练而失败了。\n");
		return;
	}
	message( "vision", HIY "\n只见" + me->name()   + 
		"衣诀随风飘舞，片刻间，风停下来，$N却消失得无影无踪！\n\n",    environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n你四周突然狂风大作，一个身影出现在你面前！\n\n" NOR,
		environment(ob), ({ me }) );
}
