inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object armor;
	int exp;

	set("gender", "����");
	set("class","phoenix");
	set("family/family_name","�����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("fenghuang-shenfa", j+random(5));
	me->set_skill("wuzu-xinfa", j+random(5));
	me->set_skill("tenglong-finger", j+random(5));
	me->set_skill("yufeng-shu", j+random(5));

	me->map_skill("force", "wuzu-xinfa");
	me->map_skill("parry", "tenglong-finger");
	me->map_skill("spells", "yufeng-shu");
	me->map_skill("dodge", "fenghuang-shenfa");
	me->map_skill("unarmed", "tenglong-finger");

	exp=query("combat_exp");
	
	if(exp>100000){	
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: perform_action,"unarmed.guangqiu" :),
			(: perform_action,"unarmed.fengdao" :),
			(: cast_spell, "tongtie" :),
			(: cast_spell, "powerup" :),
		}) );

		if(exp<1000000){
			armor=new("/d/fenghuang/obj/shield");
			set("armor_","/d/fenghuang/obj/shield");
			armor->move(me);
			command("wear all");
		}else{
			armor=new("/d/fenghuang/obj/jia");
			set("armor_","/d/fenghuang/obj/jia");
			armor->move(me);
			command("wear all");
		}
	} 
}

