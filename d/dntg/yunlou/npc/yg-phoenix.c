#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",HIR"����泼"NOR);
	create_family("�����", 2, "�泼");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("stick", j+random(15));
	me->set_skill("liedi-stick", j+random(15));
	me->set_skill("blade", j+random(15));
	me->set_skill("jile-blade", j+random(15));
	me->set_skill("fenghuang-shenfa", j+random(15));
	me->set_skill("wuzu-xinfa", j+random(15));
	me->set_skill("tenglong-finger", j+random(15));
	me->set_skill("yufeng-shu", j+random(15));

	me->map_skill("force", "wuzu-xinfa");
	me->map_skill("blade", "jile-blade");
	me->map_skill("parry", "tenglong-finger");
	me->map_skill("stick", "liedi-stick");
	me->map_skill("spells", "yufeng-shu");
	me->map_skill("dodge", "fenghuang-shenfa");
	me->map_skill("unarmed", "tenglong-finger");

	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"unarmed", "guangqiu" :),
		(: perform_action,"unarmed", "fengdao" :),
		(: cast_spell, "powerup" :),
		(: cast_spell, "tongtie" :),
	}) );

//	weapon=new("/d/obj/weapon/sword/qingfeng");
//	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
