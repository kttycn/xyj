//created by vikee
//2000-12-9 23:35

#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	me->set("title",HIG"��ɽ��ħ"NOR);
	create_family("��ɽ����", 2, "��ħ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
	me->set_skill("sword",j); 
	
	me->set_skill("yujianshu", j+random(15));
//	me->set_skill("mindsword", j+random(15));	
	me->set_skill("spells",j+random(15));
	me->set_skill("seven-steps",j+random(15));
	me->set_skill("taoism", j+random(15));
	me->set_skill("unarmed", j+random(15));	
	me->set_skill("hunyuan-zhang", j+random(15));
	me->set_skill("zixia-shengong", j+random(15)); 

	me->map_skill("force", "zixia-shengong");
	me->map_skill("sword", "yujianshu");
	me->map_skill("parry", "yujianshu");
	me->map_skill("spells", "taoism");
	me->map_skill("dodge", "seven-steps");
	me->map_skill("unarmed", "hunyuan-zhang");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"sword", "tianjian" :),
		(: perform_action,"sword", "fumo" :),
		(: perform_action,"sword", "duanshui" :),
		(: perform_action,"sword", "wanjian" :),
		(: perform_action,"unarmed", "shou" :),
		(: cast_spell, "jianshen" :),
		(: cast_spell, "fu" :),
	}) );	
//	weapon=new("/d/obj/weapon/sword/qingfeng");
//	weapon->move(me);
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
