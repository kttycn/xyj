inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "����");
	set("class","dragon");
	set("family/family_name","��������");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("fork", j+random(5));
	me->set_skill("dragon-cha", j+random(5));
	me->set_skill("hammer",j+random(5));
	me->set_skill("huntian-hammer",j+random(5));
	me->set_skill("dragon-steps", j+random(5));
	me->set_skill("dragonfight", j+random(5));
	me->set_skill("dragonforce", j+random(5));
	me->set_skill("seashentong", j+random(5));

	me->map_skill("force", "dragonforce");
	me->map_skill("fork", "dragon-cha");
	me->map_skill("hammer","huntian-hammer");
	me->map_skill("spells", "seashentong");
	me->map_skill("dodge", "dragon-steps");
	me->map_skill("unarmed", "dragonfight");

	exp=me->query("combat_exp");
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "freez" :),
			(: cast_spell, "breathe" :),
			(: exert_function, "roar" :),
			(: exert_function, "shield" :),
		}) );

		if(exp<1000000){
			if (random(2)){
				me->map_skill("parry", "huntian-hammer");
				weapon=new("/d/obj/weapon/hammer/hammer");
				set("weapon_","/d/obj/weapon/hammer/hammer");
			}
			else{
				me->map_skill("parry", "dragon-cha");
				weapon=new("/d/sea/obj/mucha");
				set("weapon_","/d/sea/obj/mucha");
			}
			weapon->move(me);
			command("wield all");
		}else{
			if (random(2)){
				me->map_skill("parry", "huntian-hammer");
				weapon=new("/d/obj/weapon/hammer/kunwu");
				set("weapon_","/d/obj/weapon/hammer/kunwu");
			}
			else{
				me->map_skill("parry", "dragon-cha");
				weapon=new("/d/obj/weapon/fork/gangcha");
				set("weapon_","/d/obj/weapon/fork/gangcha");
			}
			weapon->move(me);
			command("wield all");
		}
	}
}
