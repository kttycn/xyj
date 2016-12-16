inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender","Ů��");
	set("class","huli");
	set("family/family_name","��ԯ��Ĺ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
	me->set_skill("needle",  j);

	me->set_skill("blade", j+random(5));
	me->set_skill("xuanhu-blade", j+random(5));
	me->set_skill("huxing-steps", j+random(5));
	me->set_skill("xuanhu-shentong", j+random(5));
	me->set_skill("xuanhu-xinfa", j+random(5));
	me->set_skill("fox-hand", j+random(5));
	me->set_skill("tianyi-zhen", j+random(5));

	me->map_skill("force", "xuanhu-xinfa");
	me->map_skill("blade", "xuanhu-blade");
	me->map_skill("needle", "tianyi-zhen");
	me->map_skill("spells", "xuanhu-shentong");
	me->map_skill("dodge", "huxing-steps");
	me->map_skill("unarmed", "fox-hand");


    exp=query("combat_exp");
    if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "feisha" :),
			(: cast_spell, "hu" :),
			(: cast_spell, "luan" :),
			(: perform_action, "needle.caidie" :),
			(: perform_action, "needle.jue" :),
			(: perform_action, "blade.xian" :),
		}) );

		if(exp<1000000){
			if (random(2)){
				me->map_skill("parry", "tianyi-zhen");
				weapon=new("/d/qujing/xuanyuan/obj/needle");
				set("weapon_","/d/qujing/xuanyuan/obj/needle");
			}
			else{
				me->map_skill("parry", "xuanhu-blade");
				weapon=new("/d/obj/weapon/blade/dandao");
				set("weapon_","/d/obj/weapon/blade/dandao");
			}
			weapon->move(me);
			command("wield all");
		}else{
			if (random(2)){
				me->map_skill("parry", "tianyi-zhen");
				weapon=new("/d/qujing/xuanyuan/obj/needle1");
				set("weapon_","/d/qujing/xuanyuan/obj/needle1");
			}
			else{
				me->map_skill("parry", "xuanhu-blade");
				weapon=new("/d/obj/weapon/blade/jindao");
				set("weapon_","/d/obj/weapon/blade/jindao");
			}
			weapon->move(me);
			command("wield all");
		}
	}
}
