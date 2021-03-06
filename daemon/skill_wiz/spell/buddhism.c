// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("buddhism") )
		return notify_fail("你的法术修为还不够高深，无法学习大乘佛法。\n");
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("你的杀气太重，无法修炼大乘佛法。\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("bonze") + "/buddhism/" + spell;

	}

string type() { return "magic";}

string query_shuxing()
{
	return "tu";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("你的法力或精神不足，没有办法继续参悟大乘佛法。\n");
	if( (int)me->query("bellicosity") > 0 )
		return notify_fail("你的杀气太重，无法修炼大乘佛法。\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("你按着所学参悟大乘佛法。\n");
	return 1;
}
