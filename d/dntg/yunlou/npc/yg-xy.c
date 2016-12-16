#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",HIW"��ԯ����"NOR);
	set("gender", "Ů��");
	create_family("��ԯ��Ĺ", 2, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("needle", j+random(15));
	me->set_skill("tianyi-zhen", j+random(15));
	me->set_skill("blade", j+random(15));
	me->set_skill("xuanhu-blade", j+random(15));
	me->set_skill("huxing-steps", j+random(15));
	me->set_skill("xuanhu-xinfa", j+random(15));
	me->set_skill("fox-hand", j+random(15));
	me->set_skill("xuanhu-shentong", j+random(15));

	me->map_skill("force", "xuanhu-xinfa");
	me->map_skill("blade", "xuanhu-blade");
	me->map_skill("parry", "tianyi-zhen");
	me->map_skill("needle", "tianyi-zhen");
	me->map_skill("spells", "xuanhu-shentong");
	me->map_skill("dodge", "huxing-steps");
	me->map_skill("unarmed", "fox-hand");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"needle", "caidie" :),
		(: perform_action,"needle", "jue" :),
		(: perform_action,"blade", "xian" :),
		(: perform_action,"blade", "duanfa" :),
		(: cast_spell, "feisha" :),
		(: cast_spell, "luan" :),
		(: cast_spell, "hu" :),
	}) );

	weapon=new("/d/qujing/xuanyuan/obj/needle1");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
