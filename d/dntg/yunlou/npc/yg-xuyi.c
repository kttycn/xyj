inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	object me=this_object();
	object weapon;

	set("title","��������");
	create_family("����ɽ", 2, "����");
	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("halberd", j+random(15));
	me->set_skill("tianlong-halberd", j+random(15));
	me->set_skill("sword", j+random(15));
	me->set_skill("qixi-sword", j+random(15));
	me->set_skill("tianwei-shi", j+random(15));
	me->set_skill("guiyuanforce", j+random(15));
	me->set_skill("lianhuan-tui", j+random(15));
	me->set_skill("fumozhou", j+random(15));

	me->map_skill("force", "guiyuanforce");
	me->map_skill("sword", "tianlong-halberd");
	me->map_skill("parry", "tianlong-halberd");
	me->map_skill("sword", "qixi-sword");
	me->map_skill("spells", "fumozhou");
	me->map_skill("dodge", "tianwei-shi");
	me->map_skill("unarmed", "lianhuan-tui");

	level = 20/level;
	set("chat_chance_combat", cast_chance(level));
	set("chat_msg_combat", ({
		(: perform_action,"halberd", "tiandihunran" :),
		(: perform_action,"sword", "quewu" :),
		(: cast_spell, "freeze" :),
		(: cast_spell, "sword" :),
		(: cast_spell, "wanlei" :),
	}) );

//	weapon=new("/d/obj/weapon/sword/qingfeng");
//	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
//	command("wield all");
}
