inherit NPC;
#include <ansi.h>

void create()
{
	set_name("�������̹ܽ�", ({ "weapon master", "master" }));
	set("long","���Ƿ�˾�У�Ľ̹٣�ר�Ẕ̌������ܵġ�\n");
	set("gender", "����");
	set("age", 35);
	set("no_get", 1);
	set_skill("blade", 60);
	set_skill("stick", 60);
	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query("xmark/ѧԱ"))
		return 0;
	ob->add("xmark/ѧԱ", 0);
	return 1;
}

