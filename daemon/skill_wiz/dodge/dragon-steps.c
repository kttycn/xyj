//【龙神身法】 dragonstep.c
// cglaem...12/19/96.

inherit SKILL;

string *dodge_msg = ({
	"但是$n身形一晃，从$N身边轻轻滑过。\n",
            "只见$n往后一退，隐入一团白雾中，$N这一招顿时没了目标。\n",
            "$n一转身，一团白雾冒起，隔断了$N的攻势。\n",
            "$n左脚轻轻在地上一点，如五爪金龙般腾在半空，避开了$N的攻势。\n",
            "$n似乎有点躲闪不及，眼看就要中招。但是$N眼前金光一闪，不知怎的就扑空了。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if (me->query("class") != "dragon")
		return notify_fail("你非龙族怎能练龙神身法？\n");
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练龙神身法。\n");
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
