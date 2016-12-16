
// bula and mon@xyj

#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",HIM"�¹�ħŮ"NOR);
	set("gender", "Ů��");
	create_family("�¹�", 2, "ħŮ");
//	set("gender","����");
//	create_family("�¹�", 4, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("whip", j+random(15));
	me->set_skill("jueqing-whip", j+random(15));
	me->set_skill("sword",j+random(15));
	me->set_skill("snowsword",j+random(15));
	me->set_skill("moondance", j+random(15));
	me->set_skill("moonshentong", j+random(15));
	me->set_skill("baihua-zhang", j+random(15));
	me->set_skill("moonforce", j+random(15));

	me->map_skill("force", "moonforce");
	me->map_skill("sword", "snowsword");
	me->map_skill("whip","jueqing-whip");
	me->map_skill("spells", "moonshentong");
	me->map_skill("dodge", "moondance");
	me->map_skill("unarmed", "baihua-zhang");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: cast_spell, "arrow" :),
		(: cast_spell, "mihun" :),
		(: cast_spell, "shiyue" :),
		(: cast_spell, "huimeng" :),
	}) );

	if (random(2))
	{
		weapon=new("/d/obj/weapon/whip/longsuo");
		me->map_skill("parry", "jueqing-whip");
	}
	else
	{
		weapon=new("/d/obj/weapon/sword/qingfeng");
		me->map_skill("parry", "snowsword");
	}
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
