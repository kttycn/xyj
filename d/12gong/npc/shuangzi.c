inherit NPC;
#include "star.h"
 
void create()
{
	set_name("�ջ�˹��˹", ({"hephaestus", "shuang zi"}));
	set("long", "��˵�еĻ���ջ�˹��˹���ػ�˫������\n");
	set("gender","����");
	set("title", HIR"������"NOR);
	set("age",37);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 3300);
	set("force", 6600);
	set("max_mana",3300);
	set("mana",6600);
	set("mana_factor",156);
	set("force_factor", 165);
	set("max_kee", 3000);
	set("max_gin", 3000);
	set("max_sen", 3000);
	set("combat_exp",1064800);
	set("daoxing",1064800);

	set("chat_chance",20);
	set("chat_msg", ({
		"�ջ�˹��˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));

	set_skill("dodge", 221);
	set("attitude", "friendly");
	set_skill("force", 221);
	set_skill("parry", 221);
	set_skill("unarmed", 221);
	set_skill("sword", 221);
	set_skill("westsword",221);
	set_skill("boxing",221);
	set_skill("balei",221);
	set_skill("spells",221);
	set_skill("shuangzi", 221);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","shuangzi");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/sz_cloth")->wear();
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
	message_vision("$N��Цһ��������"HIR"������"NOR"��ǰ��������ʲô������\n",me);
	return 1;
}

void check()
{
	object ob=this_object();
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
			message_vision(HIG"$N��������һ�ӣ�һ�����Х����\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIG"$N���紵�Ĺ��ڵ��ϣ����ް��������\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIG"$N�ڷ�����ת�ţ������������������ս��\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(HIC"$Nһ���������죬һ����������$n��\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIC"$N���������˸����ţ�ֱ���ͷƤ���飡\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIC"$N��Ϳ���������ķ�������һ�����㿪�ˡ�\n"NOR,me);
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

	if((ob&&ob->query("12gong/jinniu")=="done") && (ob&&ob->query("12gong/shuangzi")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵�����˫��������ƽ�սʿ������\n"NOR,users());
		ob->set("12gong/shuangzi","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��õ���ʮ�����,�ǲ��Ǿ��ñȽ�����,�ٺ�,������˰�!");
	}
	::die();
}
