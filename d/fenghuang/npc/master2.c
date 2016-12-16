inherit NPC;
#include <ansi.h>

void create()
{
	set_name("兵器技能教官", ({ "weapon master", "master" }));
	set("long","他是凤凰军校的教官，专门教兵器技能的。\n");
	set("gender", "男性");
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
	if (!(int)ob->query("xmark/学员"))
		return 0;
	ob->add("xmark/学员", 0);
	return 1;
}

