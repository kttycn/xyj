inherit NPC;
#include "star.h"
void get_date();
 
void create()
{
	set_name("����˹", ({"ares", "bai yang"}));
	set("long", "��˵�е�վ����˹���ػ��Ű�����\n");
	set("gender","����");
	set("title", RED"��ս��"NOR);
	set("age",37);
	set("attitude", "friendly");
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 2700);
	set("force", 5400);
	set("max_mana",2700);
	set("mana",5400);
	set("mana_factor",135);
	set("force_factor", 135);
    set("max_kee", 1000);
    set("max_gin", 1000);
	set("max_sen", 1000);
	set("combat_exp",583200);
	set("daoxing",583200);

	set("chat_chance",20);
	set("chat_msg", ({
		"����˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));
	set_skill("dodge", 181);
	set_skill("force", 181);
	set_skill("parry", 181);
	set_skill("unarmed", 181);
	set_skill("sword", 181);
	set_skill("westsword",181);
	set_skill("boxing",181);
	set_skill("balei",181);
	set_skill("baiyang", 181);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","baiyang");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/by_cloth")->wear();
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
	message_vision("$N��Цһ��������"RED"��ս��"NOR"������ˣʲô������\n",me);
	return 1;
} 

void check()
{
	object ob=this_object();
	object me=query_temp("my_killer");
    
	if(! present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}
	if( me->is_ghost() )
	{
		remove_call_out("check");
		return;
	}
	 
	switch(random(6))
	{	
		case 0:
		{
			message_vision(HIR"$N˫��һ�ӣ�һ���һ�ֱ��$n��ȥ��\n",ob,me);
			if(random(2))
			{
			    message_vision(HIR"$N��$n���һ��ո���ͷ������\n"NOR,me,ob);
			    me->add("eff_kee",-query("max_kee")/10);
	    		me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIR"$N����׾ٵĶ����$n�Ĺ�����\n"NOR,me,ob);
		}
		break;
		case 1:
		{
			message_vision(HIR"$N�������ѣ���ʱһֻ������$nֱ���ȥ��\n",ob,me);
			if(random(2))
			{
			    message_vision(HIR"$N������ײ�˸���������\n"NOR,me);
			    me->add("eff_kee",-2*query("max_kee")/10);
			    me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIR"$N���Ű�����һ����ͣ������ԹԴ��Ա��￪�ˣ�\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIR"$N���г������˶���ޱȣ�ֱ��$n����\n",ob,me);
			if(random(2))
			{
			    message_vision(HIR"$N��ʱѪ����ע�����Ⱦ����ȫ��\n"NOR,me);
			    me->add("eff_kee",-3*query("max_kee")/10);
	    		me->add("eff_sen",-3*query("max_sen")/10);
			}
			else
				message_vision(HIR"$N˳�Ž��ķ�������Ծ�𣬶��������һ����\n"NOR,me);
		}
		break;
	}
//	  if( present(me,environment()) )  return ;
	if( random(8) == 5 )
		powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}

void die()
{
	object ob = query_temp("my_killer");

	if(ob&&ob->query("12gong/baiyang")!="done")
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"������"+environment(ob)->query("short")+"\n"NOR,users());
		ob->set("12gong/baiyang","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
