// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") < (int)me->query_skill("tonsillit",1) * 10 )
                return notify_fail("你的杀气不够，无法领悟更高深的摄气诀。\n");

/*	if( (int)me->query_skill("tonsillit", 1) >= 250 )
		return notify_fail("你的气量有限，对摄气诀已领悟到了极限。\n");
*/
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("摄气诀只能用学习或应用中提高！\n");
}

string exert_function_file(string func)
{
        return CLASS_D("ghost") + "/tonsillitis/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟摄气诀。\n");
	if( (int)me->query("bellicosity") < (int)me->query_skill("tonsillit",1) * 10 )
                return notify_fail("你的杀气不够，无法参悟更高深的摄气诀。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟摄气诀。\n");
	return 1;
}
