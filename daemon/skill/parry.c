// parry.c

inherit SKILL;

string *parry_msg = ({
	"只听见「锵」一声，被$p格开了。\n",
	"结果「当」地一声被$p挡开了。\n",
	"但是被$n用手中兵刃架开。\n",
	"但是$n身子一侧，用手中兵刃格开。\n",
});

string *unarmed_parry_msg = ({
	"但是被$p格开了。\n",
	"结果被$p挡开了。\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟拆招卸力之法。\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("你按着所学参悟拆招卸力之法。\n");
	return 1;
}
