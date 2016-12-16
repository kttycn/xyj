// by happ@YSZZ
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("����������", ({"proserpina", "tian chen"}));
	set("long", "��˵�е�����֮���ػ��������.��\n");
	set("gender","Ů��");
	set("title", MAG"����Ů��"NOR);
	set("age",20);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 4500);
	set("force", 9000);
	set("max_mana",4500);
	set("mana",9000);
	set("mana_factor",225);
	set("force_factor", 225);
	set("max_kee", 7000);
	set("max_gin", 7000);
	set("max_sen", 7000);
	set("combat_exp",2700000);
	set("daoxing",2700000);

	set("chat_chance",20);
	set("chat_msg", ({
		"����������˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));
	set("attitude", "friendly");

	set_skill("dodge", 301);
	set_skill("force", 301);
	set_skill("parry", 301);
	set_skill("unarmed", 301);
	set_skill("sword", 301);
	set_skill("westsword",301);
	set_skill("balei",301);
	set_skill("boxing",301);
	set_skill("tianchen", 301);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","tianchen");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/tc_cloth")->wear();
	carry_object("/d/obj/weapon/staff/chanzhang")->wield();
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
	message_vision("$N��Цһ��������"MAG"����Ů��"NOR"��ǰ��������ʲô������\n",me);
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
	switch(random(5))
	{	
		case 0:
		{
			message_vision(HIC"$N��һ���������ԡ�һ�������Ծ������ֱ��$n��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIC"$N�������ڿ��ж��÷��˼�ʮ����ͷ��\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIG"$N���ͼ�ת����֪�����˶���Ȧ�Ŷ�������Ĺ�����\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(YEL"$N�ߺ�һ�����������ԡ���һ�������Խ��׶�����β����$nɨȥ��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(GRN"$N��������β��˦�˸����ţ�$N��ʱ��ð���ǣ�\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIY"$N�þ�ȫ���������������𣬺�����β������$N�Ľŵװ���ɨ����\n"NOR,me);
		} 
		break;
		case 2:
		{
			message_vision(HIR"$N�ߺ�һ�����������ԡ�������ֻ������$n�������\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIR"$N��һ����һ����������ֻ�����ڿ���ϷŪ�ţ�\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
			}
			else
				message_vision(HIR"$N��׼������֮��Ŀ�϶����ת��ת������ǿ���ѣ�\n"NOR,me,ob);
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

	if((ob&&ob->query("12gong/shinu")=="done") && (ob&&ob->query("12gong/tiancheng")!="done"))
	{
	ob->start_busy(3);
	message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
	"�����˵��߹�����ӹ�!\n"NOR,users());
	ob->set("12gong/tiancheng","done");
	ob->add("12gong/number",1);
	ob->add("daoxing", 10000);
	tell_object(ob,"��Ӯ����ʮ�����");

	}
	::die();
}
