//created by vikee
//2000-12-9 23:35

#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",MAG"��˿����ͽ"NOR);
	set("gender", "Ů��");
	create_family("��˿��", 2, "��ͽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
	me->set_skill("sword",j); 
	
	me->set_skill("yinsuo-jinling", j+random(15));
	me->set_skill("chixin-jian", j+random(15));	
	me->set_skill("whip",j+random(15));
	me->set_skill("yueying-wubu",j+random(15));
	me->set_skill("pansi-dafa", j+random(15));
	me->set_skill("sword", j+random(15));	
	me->set_skill("lanhua-shou", j+random(15));
	me->set_skill("jiuyin-xinjing", j+random(15)); 

	me->map_skill("force", "jiuyin-xinjing");
	me->map_skill("whip", "yinsuo-jinling");
	me->map_skill("parry", "yinsuo-jinling");
	me->map_skill("sword", "chixin-jian");
	me->map_skill("spells", "pansi-dafa");
	me->map_skill("dodge", "yueying-wubu");
	me->map_skill("unarmed", "lanhua-shou");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"whip", "wang" :),
		(: perform_action,"whip", "sanshou" :),
		(: perform_action,"sword", "dandiao" :),
		(: perform_action,"sword", "hongyan" :),
		(: perform_action,"unarmed", "juehu" :),
		(: cast_spell, "wuzhishan" :),
		(: cast_spell, "ziqi" :),
		(: cast_spell, "love" :),
	}) );	
	weapon=new("/d/sea/obj/dragonwhip");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
