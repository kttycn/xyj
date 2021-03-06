inherit NPC;

void create()
{
	set_name("宗主府侍卫", ({ "shi wei", "shi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是宗主府的护府侍卫，都是宗主亲自挑选的，是一等一的高手。\n");
	set("attitude", "peaceful");

	set("kee", 1500);
	set("max_kee", 1500);
	set("sen", 500);
	set("max_sen", 500);
	set("str", 24);
	set("str", 26);
	set("combat_exp", 300000);
	set("shen_type", 1);

	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("blade", 120);
	set_skill("force", 120);
	set_skill("jile-dao", 120);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);
	map_skill("blade", "jile-dao");

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"宗主府侍卫喝道：小兔崽子到这里浏什么？？还不快滚？？！！\n",
		"宗主府侍卫喝道：再不滚，我可要动手了！\n",
	}));
	setup();

	carry_object("/d/fenghuang/obj/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

