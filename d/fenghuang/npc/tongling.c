inherit NPC;
void create()
{
	set_name("��ǰ����ͳ��", ({ "shiwei tongling", "tongling" }));
	set("age", 30);
	set("gender", "����");
	set("long", "��������������ǰ������ͳ�죬������ǰ����������ָ�ӡ�\n");
	set("attitude", "peaceful");

	set("kee", 1200);
	set("max_kee", 1200);
	set("sen", 1000);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 100);
	set("str", 32);
	set("dex", 28);
	set("combat_exp", 90000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("force", 100);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	setup();
	carry_object("/d/fenghuang/obj/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}


