inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("class","fighter");
	set("family/family_name","������");
	set("gender", "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("spear", j+random(5));
	me->set_skill("mace", j+random(5));
	me->set_skill("axe", j+random(5));
	me->set_skill("bawang-qiang", j+random(5));
	me->set_skill("wusi-mace",j+random(5));
	me->set_skill("sanban-axe",j+random(5));
	me->set_skill("yanxing-steps", j+random(5));
	me->set_skill("baguazhou", j+random(5));
	me->set_skill("changquan", j+random(5));
	me->set_skill("lengquan-force", j+random(5));

	me->map_skill("force", "lengquan-force");
	me->map_skill("spear", "bawang-qiang");
	me->map_skill("mace","wusi-mace");
	me->map_skill("axe", "sanban-axe");
	me->map_skill("spells", "baguazhou");
	me->map_skill("dodge", "yanxing-steps");
	me->map_skill("unarmed", "changquan");

	exp=query("combat_exp");
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: perform_action, "spear.qiangjian" :),
			(: perform_action, "spear.bugong" :),
			(: perform_action, "spear.meihua" :),
			(: perform_action, "spear.lianhuan" :),
			(: perform_action, "axe.sanban" :),
			(: perform_action, "axe.kai" :),
		}) );

		if(exp<1000000){
			if (random(2)){
				me->map_skill("parry", "bawang-qiang");
				weapon=new("/d/obj/weapon/spear/tieqiang");
				set("weapon_","/d/obj/weapon/spear/tieqiang");
			}
			else{
				me->map_skill("parry", "sanban-axe");
				weapon=new("/d/obj/weapon/axe/ironaxe");
				set("weapon_","/d/obj/weapon/axe/ironaxe");
			}
			weapon->move(me);
			command("wield all");
		}else{
			if (random(2)){
				me->map_skill("parry", "bawang-qiang");
				weapon=new("/d/obj/weapon/spear/yinqiang");
				set("weapon_","/d/obj/weapon/spear/yinqiang");
			}
			else{
				me->map_skill("parry", "sanban-axe");
				weapon=new("/d/obj/weapon/axe/huafu");
				set("weapon_","/d/obj/weapon/axe/huafu");
			}
			weapon->move(me);
			command("wield all");
		}
	}
}
