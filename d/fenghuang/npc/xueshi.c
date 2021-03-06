#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"血噬藤"NOR, ({ "xueshi tengi","teng","xueshii",}));
	set("long","这是一棵血红色的血噬藤，长的十分艳丽，你不禁想去摸一下，\n",);

	set("gender", "无性");
	set("attitude", "aggressive");

	set("age", 500);
	set("shen_type", -1);
	set("str", 55);
	set("int", 25);
	set("con", 25);
	set("dex", 65);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 150);
	set("combat_exp", 550000);
	set("score", 50000);

	set_skill("force", 90);
	set_skill("unarmed", 100);
	set_skill("wuzu-xinfa", 90);
	set_skill("xueshi", 100);
	set_skill("dodge", 120);
	set_skill("fenghuang-shenfa", 105);
	set_skill("parry", 100);
	set_skill("literate", 55);

	map_skill("force", "wuzu-xinfa");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("unarmed", "xueshi");
	map_skill("parry", "xueshi");

	setup();
}


