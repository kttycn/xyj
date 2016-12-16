//modified by vikee
//2000-12-9 23:34
#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",RED"���ƶ�С��"NOR);
	create_family("���ƶ�", 2, "С��");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("spear", j+random(15));
	me->set_skill("wuyue-spear", j+random(15));
	me->set_skill("moyun-shou",j+random(15));
	me->set_skill("moshenbu",j+random(15));
	me->set_skill("huomoforce", j+random(15));
	me->set_skill("pingtian-dafa", j+random(15));

	me->map_skill("force", "huomoforce");
	me->map_skill("spear", "wuyue-spear");
	me->map_skill("parry", "wuyue-spear");
	me->map_skill("spells", "pingtian-dafa");
	me->map_skill("dodge", "moshenbu");
	me->map_skill("unarmed", "moyun-shou");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: cast_spell, "sanmei" :),
		(: cast_spell, "zhuang" :),
		(: exert_function, "fire" :),
		(: perform_action,"spear", "fengshan" :),
		(: perform_action,"spear", "buhui" :),
		(: perform_action,"unarmed", "zhangxinlei" :),
		(: perform_action,"unarmed", "juesha" :),
	}) );

	carry_object("/d/obj/weapon/spear/tieqiang")->wield();
//	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
