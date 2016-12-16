inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "����");
	set("class","wusheng");
	set("family/family_name","��ʥ��");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("sword", j+random(5));
	me->set_skill("wuying-sword",j+random(5));
	me->set_skill("fumobashi", j+random(5));
	me->set_skill("mizong-steps", j+random(5));
	me->set_skill("xiantian-force", j+random(5));
	me->set_skill("feisheng-spells", j+random(5));

	me->map_skill("force", "xiantian-force");
	me->map_skill("sword", "wuying-sword");
	me->map_skill("spells", "feisheng-spells");
	me->map_skill("dodge", "mizong-steps");
	me->map_skill("unarmed", "fumobashi");
	me->map_skill("parry", "wuying-sword");

	exp=query("combat_exp");
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "feixian" :),
			(: exert_function, "qiankun" :),
			(: perform_action, "sword.fenge" :),
			(: perform_action, "sword.juechen" :),
			(: perform_action, "unarmed.wanfo" :),
		}) );

		if(exp<1000000){
			weapon=new("/d/obj/weapon/sword/changjian");
			set("weapon_","/d/obj/weapon/sword/changjian");
		}else{
			weapon=new("/d/obj/weapon/sword/qinghong");
			set("weapon_","/d/obj/weapon/sword/qinghong");
		}
		weapon->move(me);
		command("wield all");
	}
}
