// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// fumozhou
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells",1) < 20 )
		return notify_fail("你的法术修为还不够高深，无法学习伏魔咒。\n");
	if( (int)me->query("bellicosity") < 100 )
		return notify_fail("你的杀气太轻，无法领略佛法伏魔的精髓。\n");
	return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("xuyi") + "/fumozhou/" + spell;
}

string query_shuxing()
{
	return "jin";
}
int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("你的法力或精神不足，没有办法继续参悟伏魔咒。\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("你按着所学参悟伏魔咒。\n");
	return 1;
}
