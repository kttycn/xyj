inherit SKILL;

string *dodge_msg = ({
        "$n一招「鸿雁双飞」，身影微动，避了开去。\n",
	"$n左足一点，一招「边秋飞雁」腾空而起，避了开去。\n",
	"只见$n身影一晃，一式「雁抹金河」，身子轻轻的从$N头顶飞过。\n",
	"$n身影微动，已经藉一招「雁下芦洲」轻轻闪过。\n",
"只听$n长鸣一声，一招「胡雁哀鸣」，趁$N一发呆，身子轻轻飘了开去。\n",
	"$n一招「暮雁南飞」，身子向后纵出数尺，闪了开去。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 20 )
                return
notify_fail("你的内力不够，没有办法练雁行步法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的气或内力不够，不能练雁行步法。\n");
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
