// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("����ŵ˹", ({"kelowooz", "mo jie"}));
	set("long", "��˵�е�����֮���ػ���Ħ����.\n");
	set("gender","����");
	set("title", HIG"������֮��"NOR);
	set("attitude", "friendly");
	set("age",37);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 4800);
	set("force", 9600);
	set("max_mana",9600);
	set("mana",4000);
	set("mana_factor",240);
	set("force_factor", 240);
	set("max_kee", 8000);
	set("max_gin", 8000);
	set("max_sen", 8000);
	set("combat_exp",3276800);
	set("daoxing",3276800);

	set("chat_chance",20);
	set("chat_msg", ({
		"����ŵ˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));
	set_skill("dodge", 321);
	set("attitude", "friendly");
	set_skill("force", 321);
	set_skill("parry", 321);
	set_skill("unarmed", 321);
	set_skill("sword", 321);
	set_skill("westsword",321);
	set_skill("boxing",321);
	set_skill("balei",321);
	set_skill("spells",321);
	set_skill("tianxie", 321);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","tianxie");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/tx_cloth")->wear();
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
	message_vision("$N��Цһ��������"HIG"������֮��"NOR"��ǰ��������ʲô������\n",me);
	return 1;
}

void check()
{
	object ob=this_object();
	object ghost;
	object me2=new("/d/12gong/npc/mojie2.c");
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
			message_vision(HIY"$N��ϥ���ڵ��ϣ���ؾ��ҵ����ţ�\n",ob);
			if(random(3)==0)
			{
				message_vision(HIY"$N����Ķ������ᣬʧȥ��ƽ�⣡\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIW"$Nվ�ȽŸ�����$n���������š�\n"NOR,me,ob);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N�ڳ���������ƣ�һ��������$n���ٷ�����\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIM"$Nһ����С�ģ�������ҧ�˸�Ѫ������\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIG"$N����Ծ�������$N�����·ɹ���\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIW"$Nҡ��һ�䣬�ֳ�����һ���Լ�����\n",ob);
//	if( present("kelowooz two",environment()));
  //      return;
			me2->move(environment());
			me2->kill_ob(me);
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
	if((ob&&ob->query("12gong/tiancheng")=="done") && (ob&&ob->query("12gong/tianxie")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵ڰ˹�����Ы����������ƽ�սʿŬ����\n"NOR,users());
		ob->set("12gong/tianxie","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
