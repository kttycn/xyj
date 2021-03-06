//puti.c
inherit NPC;
#include <ansi.h>

void create()
{
       set_name(HIW"菩提祖师"NOR, ({"master puti","puti", "master"}));
       set("long", "大觉金仙没垢姿，西方妙相祖菩提\n");
       set("title", HIC"斜月三星"NOR);
       set("gender", "男性");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 10000000);

       set_skill("literate", 180);
       set_skill("unarmed", 180);
       set_skill("dodge", 180);
       set_skill("parry", 180);
	set_skill("stick", 200);
	set_skill("sword", 180);
	set_skill("liangyi-sword", 180);
	set_skill("spells", 200);
	set_skill("dao", 180);
	set_skill("puti-zhi", 180);
	set_skill("wuxiangforce", 200);
	set_skill("force", 200);
	set_skill("qianjun-bang", 180);
	set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
		(: perform_action, "stick", "pili" :),
		(: perform_action, "stick", "qiankun" :),
		(: perform_action, "stick", "leiting" :)
	}) );
	create_family("方寸山三星洞", 1, "蓝");
	setup();

	carry_object("/d/lingtai/obj/pao")->wear();
	carry_object("/d/lingtai/obj/shoe")->wear();
	carry_object("/d/lingtai/obj/putibang")->wield();
}
