#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��߸", ({ "nezha santaizi", "nezha", "santaizi" }));
	set("title", "��̳����֮��");
	set("long", "һλ����ݰ׵������ꡣ\n");
	set("gender", "����");
	set("age", 16);
	set("attitude", "heroism");
	set("rank_info/respect", "С̫��");
	set("rank_info/rude", "���δ�ɵ�С��");
	set("per", 40);
	set("str", 30);
	set("cor", 40);
	set("con", 40);
	set("int", 40);
	set("spi", 40);
	set("cps", 40);
	set("kar", 40);
	set("max_kee", 2000);
	set("max_gin", 1800);
	set("max_sen", 3000);
	set("force", 2600);
	set("max_force", 4000);
	set("force_factor", 100);
	set("max_mana", 3000);
	set("mana", 5000);
	set("mana_factor", 120);
	set("combat_exp", 1500000);
	set("daoxing", 2000000);

	set_skill("spells", 180);
	set_skill("dao", 150);
	set_skill("unarmed", 180);
	set_skill("yinfeng-zhua", 180);
	set_skill("dodge", 180);
	set_skill("lingfu-steps", 180);
	set_skill("parry", 180);
	set_skill("force", 180);
	set_skill("huntian-qigong", 180);
	set_skill("blade", 180);
	set_skill("sword", 200);
	set_skill("qixiu-jian", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "yinfeng-zhua");
	map_skill("parry", "huoyun-qiang");
	map_skill("sword", "qixiu-jian");
	map_skill("dodge", "lingfu-steps");
	map_skill("force", "huntian-qigong");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "bite" :),
		(: cast_spell, "jushu" :),
		(: perform_action, "sword", "qijian" :),
	}) );
	create_family("�ݿ�ɽ�޵׶�", 1, "����");
	setup();
	carry_object("/d/obj/cloth/taijicloth")->wear();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
	if ("/d/obj/fabao/huntian-ling"->in_mud())
		carry_object("/d/obj/fabao/huntian-fake");
	else
		carry_object("/d/obj/fabao/huntian-ling");
	if ("/d/obj/fabao/qiankun-quan"->in_mud())
		carry_object("/d/obj/fabao/qiankun-fake");
	else
		carry_object("/d/obj/fabao/qiankun-quan");
}

