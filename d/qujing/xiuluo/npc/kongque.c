//2001.5.22
//by yxm
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("��ȸ����������", ({"fomu kongque","fomu", "kongque"}));
	set("long", "�����Ƿ�ĸ��ȸ����������������������㻯���õ��ɷ�\n");
	set("title", HIM"��ĸ"NOR);
	set("gender", "Ů��");
	set("age", 3000);
	set("attitude", "friendly");
	set("per", 50);
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
	set_skill("literate", 300);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("bainiao-jian", 250);
	set_skill("spells", 250);
	set_skill("buddhism", 250);
	set_skill("wuxing-quan", 250);
	set_skill("zhenyuan-force", 250);
	set_skill("force", 250);
	set_skill("xiaoyaoyou", 250);
	map_skill("spells", "buddhism");
	map_skill("force", "zhenyuan-force");
	map_skill("sword", "bainiao-jian");
	map_skill("parry", "bainiao-jian");
	map_skill("dodge", "xiaoyaoyou");
	set("inquiry", ([
		"��ȥ": "Ҫ���ȥ�ͱ������������!",
		"out": "Ҫ���ȥ�ͱ������������!",
	]));
	setup();
	carry_object("/d/obj/cloth/jia_sha")->wear();
	carry_object("/d/qujing/xiuluo/obj/zijian")->wield();
}
