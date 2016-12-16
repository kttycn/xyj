
// bula and mon@xyj

#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",HIB"��ڤ���"NOR);
	create_family("���޵ظ�", 2, "���");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("whip", j+random(15));
	me->set_skill("hellfire-whip", j+random(15));
	me->set_skill("sword", j+random(15));
	me->set_skill("zhuihun-sword", j+random(15));
	me->set_skill("stick",j+random(15));
	me->set_skill("kusang-bang",j+random(15));
	me->set_skill("ghost-steps", j+random(15));
	me->set_skill("jinghun-zhang", j+random(15));
	me->set_skill("tonsillit", j+random(15));
	me->set_skill("gouhunshu", j+random(15));

	me->map_skill("force", "tonsillit");
	me->map_skill("whip", "hellfire_whip");
	me->map_skill("stick","kusang-bang");
	me->map_skill("sword","zhuihun-sword");
	me->map_skill("parry", "hellfire-whip");
	me->map_skill("spells", "gouhunshu");
	me->map_skill("dodge", "ghost-steps");
	me->map_skill("unarmed", "jinghun-zhang");
        if (level==0) level=1; //add by fix ������һ�г�0����
	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"whip", "three" :),
		(: perform_action,"stick", "qmly" :),
		(: perform_action,"whip", "lunhui" :),
		(: perform_action,"whip", "lianyu" :),
		(: perform_action,"whip", "biluo" :),
		(: cast_spell, "gouhun" :),
		(: cast_spell, "infreno" :),
		(: cast_spell, "heiwu" :),
		(: cast_spell, "hunfei" :),
		(: exert_function, "sheqi" :),
	}) );

	carry_object("/d/obj/weapon/whip/tielian")->wield();
//	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
