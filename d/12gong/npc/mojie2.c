inherit NPC;
#include "star.h"
 
void create()
{
	set_name("����˹", ({"hades", "tian xie"}));
	set("long", "��˵�е�ڤ������˹���ػ�����Ы��.\n");
	set("gender","����");
	set("title", "��������");
	set("age",37);
	set("con",45);
	set("per",30);
	set("str",63);
	set("int",64);

	set("max_force",5400);
	set("force", 10800);
	set("max_mana",5400);
	set("mana",10800);
	set("mana_factor",270);
	set("force_factor", 270);
	set("max_kee", 10000);
	set("max_gin", 10000);
	set("max_sen", 10000);
	set("combat_exp",4665600);
	set("daoxing",4665600);

	set("attitude", "aggressive");

	set_skill("dodge", 361);
	set_skill("force", 361);
	set_skill("parry", 361);
	set_skill("unarmed", 361);
	set_skill("sword", 361);
	set_skill("westsword",361);
	set_skill("boxing",361);
	set_skill("balei",361);
	set_skill("spells",361);
	set_skill("mojie", 361);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","mojie");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/mj_cloth")->wear();
	carry_object("/d/obj/weapon/sword/westsword")->wield();
}

