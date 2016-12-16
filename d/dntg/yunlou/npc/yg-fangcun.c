
// bula and mon@xyj

#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",CYN"��������"NOR);
	create_family("����ɽ���Ƕ�", 2, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("stick", j+random(15));
	me->set_skill("qianjun-bang", j+random(15));
	me->set_skill("sword",j+random(15));
	me->set_skill("liangyi-sword",j+random(15));
	me->set_skill("jindouyun", j+random(15));
	me->set_skill("wuxiangforce", j+random(15));
	me->set_skill("puti-zhi", j+random(15));
	me->set_skill("dao", j+random(15));

	me->map_skill("force", "wuxiangforce");
	me->map_skill("sword", "liangyi-sword");
	me->map_skill("stick", "qianjun-bang");
	me->map_skill("parry", "qianjun-bang");
	me->map_skill("spells", "dao");
	me->map_skill("dodge", "jindouyun");
	me->map_skill("unarmed", "puti-zhi");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"stick", "pili" :),
		(: perform_action,"stick","qiankun" :),
		(: perform_action,"stick","leiting" :),
		(: perform_action,"unarmed","jingmo" :),
		(: cast_spell, "thunder" :),
		(: cast_spell, "light" :),
		(: cast_spell, "taijitu" :),
		(: cast_spell, "dingshen" :),
		(: exert_function, "jldl" :),
	}) );

//	if (random(2))
  //	 weapon=new("/d/obj/weapon/hammer/jingua");
    //    else
	     weapon=new("/d/obj/weapon/stick/xiangmo");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
