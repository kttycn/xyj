// kongwu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW"孔武大帝"NOR, ({"master dadi", "dadi", "master"}));
	set("long", "中国五千年传奇人物，自盘古开天以来便掌管着所有的武技。\n");
	set("title", HIC"武帝圣君"NOR);
	set("gender", "男性");
	set("age", 100);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "大帝");
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("max_kee", 6000);
	set("max_gin", 1000);
	set("max_sen", 6000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2500000);
	set("daoxing", 7500000);

	set_skill("unarmed", 170);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("spells", 190);  
	set_skill("feisheng-spells", 190);
	set_skill("literate", 180);
	set_skill("sword", 200);
	set_skill("wuying-sword", 200);
	set_skill("fumobashi", 180);  
	set_skill("mizong-steps", 180);
	set_skill("dodge", 180);
	set_skill("force", 200);
	set_skill("xiantian-force", 200);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "feixian" :),
		(: perform_action, "sword", "juechen" :),
		(: perform_action, "sword", "fenge" :)
	}) );
	create_family("武圣门", 1, "尊者");
	setup();
	carry_object("/d/wusheng/obj/armor")->wear();
	carry_object("/d/wusheng/obj/cloth")->wear();
	carry_object("/d/wusheng/obj/pifeng")->wear();
	carry_object("/d/wusheng/obj/sword")->wield();
}

