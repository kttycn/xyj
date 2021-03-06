inherit NPC;

void create()
{
	set_name("御前侍卫", ({ "shi wei", "shi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "他是宗主府的御前侍卫，都是宗主亲自挑选的，是一等一的高手。\n");
	set("attitude", "peaceful");

	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 50);
	set("str", 32);
	set("cor", 28);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("force", 80);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"御前侍卫道：我们宗主府富甲天下，武功冠绝宇内，你还是投我宗主吧\n",
    	"御前侍卫喝道：你要是不投效的话，赶快滚开，再不滚，我可要动手了！\n",
	}));
	setup();

	carry_object("/d/fenghuang/obj/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

