// bula and mon@xyj

#include <ansi.h>
inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",HIY"���Ӷ�ɮ"NOR);
	create_family("�Ϻ�����ɽ", 2, "��ɮ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(15));
	me->set_skill("lunhui-zhang", j+random(15));
	me->set_skill("hammer", j+random(15));
	me->set_skill("bighammer", j+random(15));
	me->set_skill("lotusmove", j+random(15));
	me->set_skill("buddhism", j+random(15));
	me->set_skill("jienan-zhi", j+random(15));
	me->set_skill("lotusforce", j+random(15));

	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
	me->map_skill("parry", "lunhui-zhang");
	me->map_skill("hammer", "bighammer");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"staff", "pudu" :),
		(: perform_action,"staff", "forudiyu" :),
		(: perform_action,"staff", "poche" :),
		(: perform_action,"staff", "fuhu" :),
		(: perform_action,"staff", "shenlong" :),
		(: perform_action,"hammer", "bighammer" :),
		(: perform_action,"unarmed", "storm" :),
		(: cast_spell, "bighammer" :),
	}) );

	weapon=new("/d/obj/weapon/staff/budd_staff");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
