inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-yao.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "Ů��");
	set("class","xian");
	set("family/family_name","��˿��");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("whip", j+random(5));
	me->set_skill("yinsuo-jinling", j+random(5));
	me->set_skill("sword", j+random(5));
	me->set_skill("qingxia-jian", j+random(5));
	me->set_skill("chixin-jian", j+random(5));
	me->set_skill("yueying-wubu", j+random(5));
	me->set_skill("lanhua-shou", j+random(5));
	me->set_skill("jiuyin-xinjing", j+random(5));
	me->set_skill("pansi-dafa", j+random(5));

	me->map_skill("force", "jiuyin-xinjing");
	me->map_skill("whip", "yinsuo-jinling");
	me->map_skill("spells", "pansi-dafa");
	me->map_skill("dodge", "ghost-steps");
	me->map_skill("unarmed", "lanhua-shou");

	exp=query("combat_exp");
	
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: perform_action, "whip.wang" :),
			(: perform_action, "sword.haotan" :),
			(: perform_action, "sword.hongyan" :),
			(: perform_action, "sword.mantian" :),
			(: perform_action, "unarmed.juehu" :),
			(: cast_spell, "wuzhishan" :),
		}) );
		if(exp<1000000){
			switch( random(3) ) {
				case 0:
					me->map_skill("sword", "qingxia-jian");
					me->map_skill("parry", "qingxia-jian");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
				case 1:
					me->map_skill("sword", "chixin-jian");
					me->map_skill("parry", "chixin-jian");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
				case 2:
					me->map_skill("parry", "yinsuo-jinling");
					weapon=new("/d/obj/weapon/whip/whip");
					set("weapon_","/d/obj/weapon/whip/whip");
					break;
				case 3:
					break;
			}
			weapon->move(me);
			command("wield all");		
		}else{
			switch( random(3) ) {
				case 0:
					me->map_skill("sword", "qingxia-jian");
					me->map_skill("parry", "qingxia-jian");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
				case 1:
					me->map_skill("sword", "chixin-jian");
					me->map_skill("parry", "chixin-jian");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
				case 2:
					me->map_skill("parry", "yinsuo-jinling");
					weapon=new("/d/obj/weapon/whip/longsuo");
					set("weapon_","/d/obj/weapon/whip/longsuo");
					break;
				case 3:
					break;
			}
			weapon->move(me);
			command("wield all");
		}
	}
}
