// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("��˹", ({"zeus", "ren ma"}));
	set("long", "��˵�е������˹���ػ���������.\n");
	set("gender","����");
	set("title", HIY"����ۡ�"NOR);
	set("age",37);
	set("con",40);
	set("per",30);
	set("str",43);
	set("int",54);

	set("max_force", 5100);
	set("force", 10200);
	set("max_mana",5100);
	set("mana",10200);
	set("mana_factor",225);
	set("force_factor", 225);
	set("max_kee", 9000);
	set("max_gin", 9000);
	set("max_sen", 9000);
	set("combat_exp",3930400);
	set("daoxing",3930400);

	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg", ({
		"��˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));

	set_skill("dodge", 341);
	set_skill("force", 341);
	set_skill("parry", 341);
	set_skill("unarmed", 341);
	set_skill("sword", 341);
	set_skill("westsword",341);
	set_skill("boxing",341);
	set_skill("balei",341);
	set_skill("spells",341);
	set_skill("renma", 341);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","renma");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/rm_cloth")->wear();
	carry_object("/d/obj/weapon/sword/westsword")->wield();
}
void init()
{
	add_action("do_none","perform");
	add_action("do_none","cast");
	add_action("do_none","ji");
}
int do_none()
{
	object me = this_object();
	message_vision("$N��Цһ��������"HIY"����ۡ�"NOR"������ˣʲô������\n",me);
	return 1;
} 
void check()
{
	object ob=this_object();
	object ghost;
	object me=query_temp("my_killer");
	if( ! me ) return ;
	if(! present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}			       
	switch(random(6))
	{	
		case 0:
		{
			message_vision(HIY"$N��ָ$n��$N��ָ��ͻȻ����һ���׹⣡\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIY"�׹�֮��$N�е������ޱȵ���ʹ��\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIW"$N���޾�ɫ��һ��ת���㿪�˰׹⡣\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(HIC"$Nһ�����ڣ�һֻ���˰���Ĺ�����$n�� ȥ��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N������һ��ҧ����Ҫ����\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIG"$N����������ϸһ����ԭ��ֻ�ǻ���\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIW"$N˫�ֺ�ʮ������˫�ۣ�$n��ʱ�Ի�������\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N�о�������������ӽ��±����ߣ�\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
			}
			else
				message_vision(HIG"$Nվ�ȽŸ��������ںʹ�ز�����\n"NOR,me);
		}
		break;
	}
	if( random(8) == 5 )
		powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}
void die()
{
	object ob = query_temp("my_killer");
	if((ob&&ob->query("12gong/tianxie")=="done") && (ob&&ob->query("12gong/renma")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵ھŹ�����������ƽ�սʿŬ����\n"NOR,users());
		ob->set("12gong/renma","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
