// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("������", ({"apollo", "shi zi"}));
	set("long", "��˵�е�̫���񣭰����ޣ��ػ���ʨ������\n");
	set("gender","����");
	set("title", HIR"��̫����"NOR);
	set("age",37);
	set("con",40);
	set("spi",50);
	set("per",30);
	set("str",35);
	set("int",45);

	set("max_force", 3900);
	set("force", 7800);
	set("max_mana",3900);
	set("mana",7800);
	set("mana_factor",195);
	set("force_factor", 195);
	set("max_kee", 5000);
	set("max_gin", 5000);
	set("max_sen", 5000);
	set("combat_exp",1757600);
	set("daoxing",1757600);

	set("chat_chance",20);
	set("chat_msg", ({
		"������˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));
	set("attitude", "friendly");

	set_skill("dodge", 261);
	set_skill("force", 261);
	set_skill("parry", 261);
	set_skill("unarmed", 261);
	set_skill("sword", 261);
	set_skill("westsword",261);
	set_skill("boxing",261);
	set_skill("balei",261);
	set_skill("spells",261);
	set_skill("shizi", 261);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","shizi");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/shz_cloth")->wear();
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
	message_vision("$N��Цһ��������"HIR"��̫����"NOR"������ˣʲô������\n",me);
	return 1;
} 

void check()
{
	object ob=this_object();
	object me=query_temp("my_killer");
	if( ! me ) return ;

	if( me->is_ghost() )
	{
		remove_call_out("check");
		return;
	}
	if(!present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}
	switch(random(6))
	{	
		case 0:
		{
			message_vision(HIC"$N�ſ����죬��Ȼ�³�һ����⣬����$n��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIC"�������������$N�����ϣ�\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIC"$N���һ������Ȼ����ⷴ���˻�ȥ��\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N��ָ̫����ֻ������ͻȻ��ǿ���յ����������ۣ�\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIC"$N�о����������������ʹ��\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIC"��������$N�����ϣ�$N�е����޵�Ͼ�⡣\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIC"$N�ڻ���������ʲô......��Ȼ��һֻʨ�ӣ�ʨ����$n��ȥ��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIY"$N��֪����Ǻã�ʨ�ӳû���ҧ��һ�ڣ�\n"NOR,me);
				me->start_busy(1);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIC"$N��ϸһ����ԭ���Ǹ�ֽ����ʨ�ӣ�\n"NOR,me,ob);
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
	if((ob&&ob->query("12gong/juxie")=="done") && (ob&&ob->query("12gong/shizi")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵��幬ʨ������������ƽ�սʿǰ����\n"NOR,users());
		ob->set("12gong/shizi","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
