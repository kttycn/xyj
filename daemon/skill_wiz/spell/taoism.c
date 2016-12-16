//Cracked by Roath

inherit SKILL;
string type() { return "spells"; }
int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( me->query("family/family_name") != "蜀山剑派" )
        return notify_fail("天师仙法只有蜀山的人才可以学。\n");

        if( (int)me->query_skill("spells",1) < 20 )
        return notify_fail("你的法术修为还不够高深，无法学习天师仙法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("shushan") + "/taoism/" + spell;
}
string query_shuxing()
{
	return "jin";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("你的法力或精神不足，没有办法继续参悟天师仙法。\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("你按着所学参悟天师仙法。\n");
	return 1;
}
