// moonforce.c  【圆月心法】
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("圆月心法只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("moon") + "/moonforce/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟圆月心法。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟圆月心法。\n");
	return 1;
}
