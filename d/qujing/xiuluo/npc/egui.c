inherit NPC;
#include <ansi.h>

void create()
{
	set_name("���޶��", ({"xiuluo egui", "gui", "egui"}));
	set("gender", "����");
	set("age", 30);
	set("long", "һֻ���ǻ��������϶������޶��\n");
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per", 10);
	set("str", 20);
	set("combat_exp", 800000);
	set("daoxing", 1000000);
	set_skill("literate", 120);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("bainiao-jian", 120);
	set_skill("spells", 120);
	set_skill("buddhism", 120);
	set_skill("wuxing-quan", 120);
	set_skill("zhenyuan-force", 120);
	set_skill("force", 120);
	set_skill("xiaoyaoyou", 120);
	map_skill("spells", "buddhism");
	map_skill("force", "zhenyuan-force");
	map_skill("sword", "bainiao-jian");
	map_skill("parry", "bainiao-jian");
	map_skill("dodge", "xiaoyaoyou");
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_kee",1200);
	set("max_sen",1200);
	set("mana", 6000);
	set("mana_factor", 150);
	set("max_mana", 3000);

	set("inquiry", ([
		"here": "���Ѿ���������ķ�϶���ǻ���һǧ�����ˣ�\n",
	]) );

	setup();

	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void die()
{  
	object killer,yao;
	killer = query_temp("last_damage_from");
	yao =this_object();
	if(killer->query("xiuluo/jiemen")!="done" )
	{
		killer->set("xiuluo/jiemen","done");	  
		killer->add("daoxing",20000);   
		tell_object(killer,"��Ӯ���˶�ʮ�����!\n");
		message("channel:rumor", HIR+"�������޽硿: ��˵"+killer->query("name")+"�¸ҵĴ����˺ڰ�֮Ԩ��\n"+NOR,users());
	}
// destruct(this_object());
	::die();
}