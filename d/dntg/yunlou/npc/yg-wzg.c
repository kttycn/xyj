
// bula and mon@xyj
#include <ansi.h>

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title",YEL"��ׯ����ͽ"NOR);
	create_family("��ׯ��", 2, "��ͽ");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("hammer", j+random(15));
	me->set_skill("kaishan-chui", j+random(15));
	me->set_skill("staff", j+random(15));
	me->set_skill("fumo-zhang", j+random(15));
	me->set_skill("sword",j+random(15));
	me->set_skill("sanqing-jian",j+random(15));
	me->set_skill("baguazhen", j+random(15));
	me->set_skill("taiyi", j+random(15));
	me->set_skill("wuxing-quan", j+random(15));
	me->set_skill("zhenyuan-force", j+random(15));

	me->map_skill("force", "zhenyuan-force");
	me->map_skill("sword", "sanqing-jian");
	me->map_skill("staff", "fumo-zhang");
	me->map_skill("hammer","kaishan-chui");
	me->map_skill("parry", "sanqing-jian");
	me->map_skill("spells", "taiyi");
	me->map_skill("dodge", "baguazhen");
	me->map_skill("unarmed", "wuxing-quan");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"sword", "juejian" :),
		(: perform_action,"sword", "hammer" :),
		(: perform_action,"sword", "staff" :),
		(: perform_action,"sword", "jianmang" :),
		(: perform_action,"sword", "jianzhang" :),
		(: perform_action,"sword", "jianqi" :),
		(: perform_action,"staff", "luanwu" :),
		(: perform_action,"hammer", "danshan" :),
		(: cast_spell, "zhenhuo" :),
		(: cast_spell, "qiankun" :),
	}) );

	weapon=new("/d/obj/weapon/sword/qingfeng");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}
