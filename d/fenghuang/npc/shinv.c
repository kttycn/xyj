inherit NPC;

void create()
{
	set_name("侍女", ({ "shi nv", "shi" }));
	set("age", 18);
	set("gender", "女性");
	set("long", "她们是宗主府的侍女，各个美若天仙。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("cor", 16);
	set("per", 36);
	set("combat_exp", 18000);
	set("shen_type", 0);

	set("chat_chance_combat", 4);
	set("chat_msg_combat", ({
		"侍女笑盈盈的看着你，又与其他人窃窃私语。好象在谈论什么\n",
		"侍女抬头看了你一下，又低下头去了n",
	}));
	setup();
	carry_object("/d/fenghuang/obj/shoes")->wear();
	carry_object("/d/fenghuang/obj/dress")->wear();
}

