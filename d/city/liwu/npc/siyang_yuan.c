#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��������Ա", ({ "siyang yuan", "yuan" }) );
	set("title", HIY"������ϰ�"NOR);
	set("gender", "Ů��" );

	set("age", 32);
	set("str", 30);
	set("con", 30);
	set("per", 25);
	set("int", 25);
         
	set("long",
		"���������������ϰ壬����������û���뵽���֣������Լ����ֵ��ϰ��ֵ���ơ�\n" );

	set("combat_exp", 50000);
	set("attitude", "friendly");
	

	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor",50);

	set_skill("unarmed",70);
	set_skill("dodge",70);
	set_skill("parry",70);
	set_skill("force",70);
 
	set_temp("apply/attack",50);
	set_temp("apply/defense",50);

	setup();
    carry_object("/d/city/liwu/obj/weiqun")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;
	command("say �����������İɣ�\n");
}
