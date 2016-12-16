//puti.c
inherit NPC;
#include <ansi.h>

void create()
{
       set_name(HIW"������ʦ"NOR, ({"master puti","puti", "master"}));
       set("long", "�������û���ˣ���������������\n");
       set("title", HIC"б������"NOR);
       set("gender", "����");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
	set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
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
	create_family("����ɽ���Ƕ�", 1, "��");
	setup();

	carry_object("/d/lingtai/obj/pao")->wear();
	carry_object("/d/lingtai/obj/shoe")->wear();
	carry_object("/d/lingtai/obj/putibang")->wield();
}
