// jentleman.c ������ʿ

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "jentle man", "man" }));
	set("age", 32);
	set("gender", "����");
	set("long", "����һ��ʮ���з�ȵ�������ʿ����Ҳ�ǵ����ֽ������档\n");
	set("attitude", "friendly");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 30);
	set("dex", 24);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed",60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
     setup();
    carry_object("/d/city/liwu/obj/jiericloth")->wear();
}
