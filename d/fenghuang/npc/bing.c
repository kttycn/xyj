inherit NPC;

void create()
{
	set_name("�����ʿ", ({ "wei shi", "shi" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ��ʿ�ǵĹ����ܺ���Щϰ������ȣ��������ǽ��������˶�������\n");
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
		"�����ʿ�ȵ����󵨵��񣬾����췴���ɣ�\n",
		"�����ʿ�ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
	}));
	setup();
	carry_object("/d/fenghuang/obj/gun")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
