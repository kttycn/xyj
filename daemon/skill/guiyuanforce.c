// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// guiyuanforce.c
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("归元神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("xuyi") + "/guiyuanforce/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟归元神功。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟归元神功。\n");
	return 1;
}
