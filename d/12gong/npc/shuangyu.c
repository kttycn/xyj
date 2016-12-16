// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("������", ({"boseidon", "shuang yu"}));
	set("long", "��˵�еĺ������������ػ���˫����.\n");
	set("gender","����");
	set("title", HIC"������"NOR);
	set("age",37);
	set("con",60);
	set("per",32);
	set("str",80);
	set("int",80);

	set("max_force", 6000);
	set("force", 12000);
	set("max_mana",6000);
	set("mana",12000);
	set("mana_factor",300);
	set("force_factor", 300);
	set("max_kee", 10000);
	set("max_gin", 10000);
	set("max_sen", 10000);
	set("combat_exp",6400000);
	set("daoxing",6400000);

	set("attitude", "friendly");
	set("cant_be_smashed",1);
	set("chat_chance",20);
	set("chat_msg", ({
		"��ʿ��˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));

	set_skill("dodge", 401);
	set_skill("force", 401);
	set_skill("parry", 401);
	set_skill("unarmed", 401);
	set_skill("sword", 401);
	set_skill("westsword",401);
	set_skill("boxing",401);
	set_skill("balei",401);
	set_skill("spells",401);
	set_skill("shuangyu", 401);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","shuangyu");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/sy_cloth")->wear();
	carry_object(__DIR__"obj/rose")->wear();
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
	message_vision("$N��Цһ��������"HIC"������"NOR"������ˣʲô������\n",me);
	return 1;
} 
void check()
{
	object ob=this_object();
	object rose;
	object me=query_temp("my_killer");

	if( ! me ) return ;
	if(! present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}			       

	switch(random(7))
	{	
		case 0:
		{
			message_vision(HIY"$Nһ���Х����֮ˮ��֮���ڣ���$n��û��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIY"$N���ĺ�֮ˮײ�������������\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIW"$N˳��ˮ�ƣ��ڼ������沨������\n"NOR,me,ob);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N����һ����#$%^%!�����һֻ˫ͷ���㣡\n",ob);
			if(random(2)==0)
			{
				message_vision(HIM"�����ſ����죬����$Nһ���˺��\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIG"$Nһ����ת���Ὺ�����һ����\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIC"$N�ߺ�������֮�ǣ�����֮����һ����ʯ�������$n��ȥ��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N�������޷���ܣ�����������ʯ������û�ж�ܵĿռ䣡\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
				me->start_busy(1);
			}
			else
				message_vision(HIG"$N����������ò����ײŶ㿪$n�Ĺ�����\n"NOR,me,ob);
		}
		break;
		case 3:
		{
//			rose=new("/d/12gong/npc/obj/rose.c");
			message_vision(HIC"$N��������һֻ��õ�壬ֻ��$N�촽΢������õ�������ҵļ�����$n��\n"NOR,ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N����õ��Ķ��̴��������壡\n");
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
//				rose->move(environment());
			}
			else {
				message_vision(HIG"$N��׼��õ������ķ���˳�ƽ�ס�˺�õ�壡\n"NOR,me);
//				rose->move(me);
			}
		}
	break;

  }
	if( !random(6) )
		powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}
void die()
{
	object ob = query_temp("my_killer");
	if((ob&&ob->query("12gong/baoping")=="done") && (ob&&ob->query("12gong/shuangyu")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"���ڴ����˻ƽ�ʮ������\n"NOR,users());
		ob->set("12gong/shuangyu","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 50000);
		tell_object(ob,"��Ӯ������ʮ�����");
	}
	::die();
}
