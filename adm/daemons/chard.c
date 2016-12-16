// chard.c

#include <race.h>
#include <skill.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
	string race;
	mapping my;

	if( !stringp(race = ob->query("race")) ) {
		race = "人类";
		ob->set("race", "人类");
	}
		
	switch(race) {
		case "赛亚人":
			SAIYA_RACE->setup_human(ob);
			break;
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;
		case "天神":
			GOD_RACE->setup_human(ob);
			break;
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;
		case "野兽":
			BEAST_RACE->setup_beast(ob);
			break;
		default:
			error("Chard: undefined race " + race + ".\n");
	}

	my = ob->query_entire_dbase();

	if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
	if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
	if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

	if( !ob->query_max_encumbrance() )
//		ob->set_max_encumbrance( my["str"] * 5000 );
		ob->set_max_encumbrance( my["str"]*5000 +
                    (int)ob->query_skill("unarmed",1)*200);
	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}

	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name() + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		}
	}

	return corpse;
}

varargs object make_toulu(object corpse)
{
        object toulu;
        toulu=new("/d/obj/misc/toulu");
        toulu->set("name",(string)corpse->query("oldname")+"的头颅");
        toulu->set("gender",corpse->query("gender"));
        toulu->set("age",corpse->query("age"));
        return toulu;
}
varargs object make_wutoucorpse(object corpse)
{
        object corpse1;
        string oldname;
        corpse1=new("/d/obj/misc/corpse");
        sscanf(corpse->query("name"),"%s的尸体%*s",oldname);
        corpse->set("oldname",oldname);
        corpse1->set("name",(string)corpse->query("oldname")+"的无头尸体");
        corpse1->set("gender",corpse->query("gender"));
        corpse1->set("age",corpse->query("age"));
        return corpse1;
}
