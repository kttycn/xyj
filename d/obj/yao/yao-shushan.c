inherit __DIR__"yaoguai.c";
#include "/d/obj/yao/yao-xian.h"

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;
	int exp;

	set("gender", "����");
	set("class","swordsman");
	set("family/family_name","��ɽ����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("sword", j+random(5));
	me->set_skill("whip", j+random(5));
	me->set_skill("yujianshu", j+random(5));
	me->set_skill("mindsword",j+random(5));
	me->set_skill("canxin-jian",j+random(5));
	me->set_skill("yiruwhip",j+random(5));
	me->set_skill("seven-steps", j+random(5));
	me->set_skill("hunyuan-zhang", j+random(5));
	me->set_skill("zixia-shengong", j+random(5));
	me->set_skill("taoism", j+random(5));

	me->map_skill("force", "zixia-shengong");
	me->map_skill("whip", "yiruwhip");
	me->map_skill("spells", "taoism");
	me->map_skill("dodge", "seven-steps");
	me->map_skill("unarmed", "hunyuan-zhang");

	exp=query("combat_exp");
	if(exp>100000){
		set("chat_chance_combat", cast_chance(level));
		set("chat_msg_combat", ({
			(: cast_spell, "fu" :),
			(: cast_spell, "jianshen" :),
			(: perform_action, "sword.tianjian" :),
			(: perform_action, "sword.fumo" :),
			(: perform_action, "sword.duanshui" :),
			(: perform_action, "sword.wanjian" :),
			(: perform_action, "sword.xiangsi" :),
			(: perform_action, "sword.fenguang" :),
			(: perform_action, "whip.yue" :),
			(: perform_action, "whip.snoke" :),
		}) );

		if(exp<1000000){
			switch( random(4) ) {  // 1/3 chance to greet.
				case 0:
					me->map_skill("sword", "yujianshu");
					me->map_skill("parry", "yujianshu");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
				case 1:
					me->map_skill("sword", "mindsword");
					me->map_skill("parry", "mindsword");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
				case 2:
					me->map_skill("sword", "canxin-jian");
					me->map_skill("parry", "canxin-jian");
					weapon=new("/d/obj/weapon/sword/changjian");
					set("weapon_","/d/obj/weapon/sword/changjian");
					break;
				case 3:
					me->map_skill("parry", "yiruwhip");
					weapon=new("/d/obj/weapon/whip/whip");
					set("weapon_","/d/obj/weapon/whip/whip");
					break;
			}
		}else{
			switch( random(4) ) {  // 1/3 chance to greet.
				case 0:
					me->map_skill("sword", "yujianshu");
					me->map_skill("parry", "yujianshu");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
				case 1:
					me->map_skill("sword", "mindsword");
					me->map_skill("parry", "mindsword");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
				case 2:
					me->map_skill("sword", "canxin-jian");
					me->map_skill("parry", "canxin-jian");
					weapon=new("/d/obj/weapon/sword/qinghong");
					set("weapon_","/d/obj/weapon/sword/qinghong");
					break;
				case 3:
					me->map_skill("parry", "yiruwhip");
					weapon=new("/d/obj/weapon/whip/longsuo");
					set("weapon_","/d/obj/weapon/whip/longsuo");
					break;
			}
		}
		weapon->move(me);
		command("wield all");
	}
}
