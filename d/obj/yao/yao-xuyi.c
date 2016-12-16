inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("class","xuyi");
	set("family/family_name","����ɽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("halberd", j+random(5));
	me->set_skill("hammer", j+random(5));
	me->set_skill("sword", j+random(5));
	me->set_skill("tianlong-halberd", j+random(5));
	me->set_skill("pangu-hammer",j+random(5));
	me->set_skill("qixi-sword",j+random(5));
	me->set_skill("tianwei-shi", j+random(5));
	me->set_skill("fumozhou", j+random(5));
	me->set_skill("lianhuan-tui", j+random(5));
	me->set_skill("guiyuanforce", j+random(5));

	me->map_skill("force", "guiyuanforce");
	me->map_skill("halberd", "tianlong-halberd");
	me->map_skill("hammer","pangu-hammer");
	me->map_skill("sword", "qixi-sword");
	me->map_skill("spells", "fumozhou");
	me->map_skill("dodge", "tianwei-shi");
	me->map_skill("unarmed", "lianhuan-tui");

	exp=query("combat_exp");
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "freeze" :),
			(: cast_spell, "sword" :),
			(: cast_spell, "wanlei" :),
			(: perform_action, "sword.quewu" :),
		}) );

		if(exp<1000000){
			switch( random(3) ) {  // 1/3 chance to greet.
				case 0:
					set("gender", "����");
					me->map_skill("parry", "tianlong-halberd");
					weapon=new("/d/obj/weapon/halberd/halberd");
					set("weapon_","/d/obj/weapon/halberd/halberd");
					break;
				case 1:
					set("gender", "����");
					me->map_skill("parry", "pangu-hammer");
					weapon=new("/d/obj/weapon/hammer/hammer");
					set("weapon_","/d/obj/weapon/hammer/hammer");
					break;
				case 2:
					set("gender", "Ů��");
					me->map_skill("parry", "qixi-sword");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
			}
		}else{
			switch( random(3) ) {  // 1/3 chance to greet.
				case 0:
					set("gender", "����");
					me->map_skill("parry", "tianlong-halberd");
					weapon=new("/d/obj/weapon/halberd/cuiling");
					set("weapon_","/d/obj/weapon/halberd/cuiling");
					break;
				case 1:
					set("gender", "����");
					me->map_skill("parry", "pangu-hammer");
					weapon=new("/d/obj/weapon/hammer/kunwu");
					set("weapon_","/d/obj/weapon/hammer/kunwu");
					break;
				case 2:
					set("gender", "Ů��");
					me->map_skill("parry", "qixi-sword");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
			}
		}
		weapon->move(me);
		command("wield all");
	}
}
