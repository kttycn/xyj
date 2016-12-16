
// bula and mon@xyj
#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",HIC"��������"NOR);
	create_family("��������", 2, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("fork", j+random(15));
	me->set_skill("dragon-cha", j+random(15));
	me->set_skill("hammer",j+random(15));
	me->set_skill("huntian-hammer",j+random(15));
	me->set_skill("dragon-steps", j+random(15));
	me->set_skill("dragonfight", j+random(15));
	me->set_skill("dragonforce", j+random(15));
	me->set_skill("seashentong", j+random(15));

	me->map_skill("force", "dragonforce");
	me->map_skill("fork", "dragon-cha");
	me->map_skill("hammer","huntian-hammer");
	me->map_skill("parry", "huntian-hammer");
	me->map_skill("spells", "seashentong");
	me->map_skill("dodge", "dragon-steps");
	me->map_skill("unarmed", "dragonfight");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: cast_spell, "freez" :),
		(: cast_spell, "water" :),
		(: cast_spell, "dragonfire" :),
		(: exert_function, "roar" :),
		(: exert_function, "shield" :),
        (: perform_action,"hammer", "dragon" :),
	}) );

	weapon=new("/d/obj/weapon/hammer/jingua");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
