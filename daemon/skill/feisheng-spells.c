// feisheng-spells 【飞升大法】

/*
飞升大法
入思修定，举霞飞升。乃修身之人的目的，此仙法如果修炼有成，可以举霞
飞升，跳出三界外，不在五行中，无生死大限！
*/

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells",1) < 20 )
        return notify_fail("你的法术修为还不够高深，无法学习飞升大法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("wusheng") + "/feisheng-spells/" + spell;
}

string type() { return "magic";} 

string query_shuxing()
{
	return "jin";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("你的法力或精神不足，没有办法继续参悟飞升大法。\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("你按着所学参悟飞升大法。\n");
	return 1;
}
