inherit NPC;

void create()
{
	set_name("凤凰卫士", ({ "wei shi", "shi" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "虽然兵士们的功夫不能和那些习武人相比，可是他们讲究的是人多力量大。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("str", 26);
	set("combat_exp", 18000);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);


	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"凤凰卫士喝道：大胆刁民，竟敢造反不成？\n",
		"凤凰卫士喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
	carry_object("/d/fenghuang/obj/gun")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
