#include <ansi.h>

inherit NPC;

void create()
{
	set_name("化骨龙", ({ "huagu long", "long" }));
	set("title", "龙升典当行老板");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("str", 100);
	set("per", 26);
	set("long",
		"他是宗主的第十三个儿子，他性格豪放不羁，与宗主府的人格格不入。\n");
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
