// dengxian-dafa.c 【登仙大法】
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("dengxian-dafa", 1) )
                return
notify_fail("你的法术修为还不够高深，无法学习登仙大法。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/xueshan/dengxian-dafa/" + spell;
}

string type() { return "magic"; }

string query_shuxing()
{
	return "mu";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("你的法力或精神不足，没有办法继续参悟登仙大法。\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("你按着所学参悟登仙大法。\n");
	return 1;
}
