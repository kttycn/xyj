// jindouyun.c

inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个「踏云步」，避开了这一招。\n",
	"$N眼一花，$n使出「翻云式」一个筋斗从$N头顶越过。\n",
	"$n一声：好！一招「追云式」连翻几个筋斗，连影子都没了。\n",
	"$n左足一点，一招「穿云式」腾空而起，避了开去。\n",
	"但是$n使一招「流云步」，身子轻轻飘了开去。\n",
	"可是$n胸腹往后一缩，在间不容发之际一个筋斗倒翻而出，好个「倒骑云」！\n",
	"只见$n一声长啸，卷起一股疾风，身形亦腾风而起，\n$N的攻击早失了准头。正是“筋斗云”中的「腾云式」！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法练筋斗云。\n");

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
		return notify_fail("你的气或内力不够，不能练筋斗云。\n");
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
