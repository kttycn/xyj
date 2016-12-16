
// bula and mon@xyj
#include <ansi.h>

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",HIW"ѩɽ����"NOR);
	create_family("��ѩɽ", 2, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("blade", j+random(15));
	me->set_skill("bingpo-blade", j+random(15));
	me->set_skill("xiaoyaoyou", j+random(15));
	me->set_skill("dengxian-dafa", j+random(15));
	me->set_skill("ningxue-force", j+random(15));
	me->set_skill("cuixin-zhang", j+random(15));

	me->map_skill("force", "ningxue-force");
	me->map_skill("blade", "bingpo-blade");
	me->map_skill("parry", "bingpo-blade");
	me->map_skill("spells", "dengxian-dafa");
	me->map_skill("dodge", "xiaoyaoyou");
	me->map_skill("unarmed", "cuixin-zhang");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"sword", "chaofeng" :),
		(: perform_action,"sword", "feijian" :),
		(: perform_action,"sword", "zheng" :),
		(: perform_action,"blade", "yushujufen" :),
		(: cast_spell, "tuntian" :),
		(: cast_spell, "juanbi" :),
		(: cast_spell, "jieti" :),
		(: exert_function, "mohu" :),
		(: exert_function, "ningxie" :),
		(: exert_function, "fog" :),
	}) );

	weapon=new("/d/xueshan/obj/anqi-jian");
	weapon->set("anqi/now",100);
	weapon->set("anqi/type","����");

	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
