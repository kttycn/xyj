
inherit NPC;

void create()
{
	set_name("�����ٸ�", ({ "shao fu", "fu" }));
	set("age", 32);
	set("gender", "Ů��");
	set("long", "����һ�����ϵĶ����ٸ�����Ҳ�ǵ����ֽ������档\n");
	set("attitude", "friendly");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 30);
	set("dex", 24);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed",50);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	setup();
	carry_object("/d/city/liwu/obj/jiericloth")->wear();
}
