inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的内功心法火候还不够。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("无祖心法只能用学来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("phoenix") + "/wuzu-xinfa/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟无祖心法。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟无祖心法。\n");
	return 1;
}
