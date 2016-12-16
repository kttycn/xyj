inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "����");
	set("class","yaomo");
	set("family/family_name","���ƶ�");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("spear", j+random(5));
	me->set_skill("wuyue-spear", j+random(5));
	me->set_skill("huoyun-qiang",j+random(5));
	me->set_skill("moshenbu", j+random(5));
	me->set_skill("moyun-shou", j+random(5));
	me->set_skill("huomoforce", j+random(5));
	me->set_skill("pingtian-dafa", j+random(5));

	me->map_skill("force", "huomoforce");
	me->map_skill("spells", "pingtian-dafa");
	me->map_skill("dodge", "moshenbu");
	me->map_skill("unarmed", "moyun-shou");

	exp=query("combat_exp");

	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: perform_action, "spear.buhui" :),
			(: perform_action, "spear.fengchan" :),
			(: perform_action, "spear.ji" :),
			(: perform_action, "spear.lihuo" :),
			(: perform_action, "spear.huohun" :),
			(: cast_spell, "sanmei" :),
			(: cast_spell, "zhuang" :),
			(: exert_function, "fire" :),
		}) );
		if(exp<1000000){
			if (random(2)){
					me->map_skill("spear", "wuyue-spear");
					me->map_skill("parry", "wuyue-spear");
			}
			else{
					me->map_skill("spear", "huoyun-qiang");
					me->map_skill("parry", "huoyun-qiang");
			}
			weapon=new("/d/obj/weapon/spear/tieqiang");
			set("weapon_","/d/obj/weapon/spear/tieqiang");
			weapon->move(me);
			command("wield all");		
		}else{
			if (random(2)){
					me->map_skill("spear", "wuyue-spear");
					me->map_skill("parry", "wuyue-spear");
			}
			else{
					me->map_skill("spear", "huoyun-qiang");
					me->map_skill("parry", "huoyun-qiang");
			}
			weapon=new("/d/obj/weapon/spear/yinqiang");
			set("weapon_","/d/obj/weapon/spear/yinqiang");
			weapon->move(me);
			command("wield all");
		}
	}
}
