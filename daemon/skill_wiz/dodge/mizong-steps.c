// mizong-steps 【迷踪步】

/*
迷踪步
飘渺无定为特色，瞬刻之间可以消失在天地之间，无影无踪。
*/

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个"HIR"「飘花摆柳」"NOR"，避开了这一招。\n",
	"$N眼一花，$n使出"HIC"「翻云覆海」"NOR"一个筋斗从$N头顶越过。\n",
	"$n一声：好！一招"HIW"「追星赶月」"NOR"连翻几个筋斗，连影子都没了。\n",
	"$n左足一点，一招"HIM"「穿梭天地」"NOR"腾空而起，避了开去。\n",
	"但是$n使一招"HIY"「无影无踪」"NOR"，身子轻轻飘了开去。\n",
	"可是$n胸腹往后一缩，在间不容发之际一个筋斗倒翻而出，好个"HIB"「倒转天地」"NOR"！\n",
	"只见$n一声长啸，卷起一股疾风，身形亦腾风而起，\n$N的攻击早失了准头。正是“迷踪步”中的"HIG"「脚踏三界」"NOR"！\n"
});

int valid_enable(string usage)
{
	return usage=="dodge";
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法练迷踪步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练迷踪步。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60)
		return notify_fail("你现在脚下虚浮，先休息一阵吧。\n");
	if( (int)me->query("sen") < 60)
		return notify_fail("你的精神无法集中了，休息一下再进行参悟吧。\n");
	if((int)me->query("force") < 6 )
		return notify_fail("你现在内力不够，难以继续参悟下去了。\n");
	me->receive_damage("kee", 60);
	me->add("force", -6);
	return 1;
}
