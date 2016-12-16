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
	set("family/family_name","��ѩɽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
	me->set_skill("sword",  j);
 
	me->set_skill("blade", j+random(5));
	me->set_skill("bingpo-blade", j+random(5));
	me->set_skill("xiaoyaoyou", j+random(5));
	me->set_skill("dengxian-dafa", j+random(5));
	me->set_skill("ningxue-force", j+random(5));
	me->set_skill("cuixin-zhang", j+random(5));
	me->set_skill("bainiao-jian", j+random(5));

	me->map_skill("force", "ningxue-force");
	me->map_skill("blade", "bingpo-blade");
	me->map_skill("sword", "bainiao-jian");
	me->map_skill("spells", "dengxian-dafa");
	me->map_skill("dodge", "xiaoyaoyou");
	me->map_skill("unarmed", "cuixin-zhang");


    exp=query("combat_exp");
    if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "juanbi" :),
			(: perform_action, "blade.yaowu" :),
			(: perform_action, "sword.chaofeng" :),
		}) );

		if(exp<1000000){
			if (random(2)){
				me->map_skill("parry", "bainiao-jian");
				weapon=new("/d/obj/weapon/sword/changjian");
				set("weapon_","/d/obj/weapon/sword/changjian");
			}
			else{
				me->map_skill("parry", "bingpo-blade");
				weapon=new("/d/obj/weapon/blade/dandao");
				set("weapon_","/d/obj/weapon/blade/dandao");
			}
			weapon->move(me);
			command("wield all");
		}else{
			if (random(2)){
				me->map_skill("parry", "bainiao-jian");
				weapon=new("/d/obj/weapon/sword/qinghong");
				set("weapon_","/d/obj/weapon/sword/qinghong");
			}
			else{
				me->map_skill("parry", "bingpo-blade");
				weapon=new("/d/obj/weapon/blade/jindao");
				set("weapon_","/d/obj/weapon/blade/jindao");
			}
			weapon->move(me);
			command("wield all");
		}
	}
}
