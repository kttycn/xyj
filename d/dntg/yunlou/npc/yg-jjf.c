
// bula and mon@xyj

#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",HIR"�������ѽ�"NOR);
	create_family("������", 2, "�ѽ�");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("spear", j+random(15));
	me->set_skill("bawang-qiang", j+random(15));
	me->set_skill("mace", j+random(15));
	me->set_skill("wusi-mace", j+random(15));
	me->set_skill("axe",j+random(15));
	me->set_skill("sanban-axe",j+random(15));
	me->set_skill("yanxing-steps", j+random(15));
	me->set_skill("changquan", j+random(15));
	me->set_skill("lengquan-force", j+random(15));
	me->set_skill("baguazhou", j+random(15));

	me->map_skill("force", "lengquan-force");
	me->map_skill("axe", "sanban-axe");
	me->map_skill("spear","bawang-qiang");
	me->map_skill("mace","wudi-mace");
	me->map_skill("parry", "bawang-qiang");
	me->map_skill("spells", "baguazhou");
	me->map_skill("dodge", "yanxing-steps");
	me->map_skill("unarmed", "changquan");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"axe", "sanban" :),
		(: perform_action,"axe", "kai" :),
		(: perform_action,"spear", "bugong" :),
		(: perform_action,"spear", "daohai" :),
		(: perform_action,"spear", "qiangjian" :),
		(: perform_action,"spear", "jingyan" :),
		(: perform_action,"spear", "meihua" :),
		(: perform_action,"spear", "lianhuan" :),
		(: exert_function, "jingxin" :),
	}) );

	carry_object("/d/obj/weapon/spear/changqiang")->wield();
	new("/d/obj/weapon/mace/ironmace")->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
