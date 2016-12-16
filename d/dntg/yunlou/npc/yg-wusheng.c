
// bula and mon@xyj
#include <ansi.h>

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",WHT"��ʥ��ͽ"NOR);
	create_family("��ʥ��", 2, "��ͽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("sword", j+random(15));
	me->set_skill("wuying-sword", j+random(15));
	me->set_skill("mizong-steps", j+random(15));
	me->set_skill("xiantian-force", j+random(15));
	me->set_skill("fumobashi", j+random(15));
	me->set_skill("feisheng-dafa", j+random(15));

	me->map_skill("force", "xiantian-force");
	me->map_skill("sword", "wuying-sword");
	me->map_skill("parry", "wuying-sword");
	me->map_skill("spells", "feisheng-spells");
	me->map_skill("dodge", "mizong-steps");
	me->map_skill("unarmed", "fumobashi");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"unarmed", "wanfo" :),
		(: perform_action,"sword", "fenge" :),
		(: perform_action,"sword","juechen" :),
		(: cast_spell, "feixian" :),
		(: exert_function, "qiankun" :),
	}) );

	weapon=new("/d/obj/weapon/sword/qingfeng");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
