#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({ "huagu long", "long" }));
	set("title", "�����䵱���ϰ�");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("str", 100);
	set("per", 26);
	set("long",
		"���������ĵ�ʮ�������ӣ����Ը���Ų�������������˸���롣\n");
	set("no_get_from", 1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_temp("apply/attack", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/damage", 65);

	set("combat_exp", 200000);
	set("attitude", "friendly");
        
	setup();
	carry_object("/d/obj/cloth/cloth")->wear();
}
