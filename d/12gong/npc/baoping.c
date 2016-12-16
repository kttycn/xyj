// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("�ڴ�ŵ˹", ({"uranus", "bao ping"}));
	set("long", "��˵�е����֮���ػ��ű�ƿ��.\n");
	set("gender","����");
	set("title", BLU"�����֮��"NOR);
	set("age",37);
	set("con",55);
	set("per",30);
	set("str",73);
	set("int",64);

	set("max_force", 5700);
	set("force", 11400);
	set("max_mana",5700);
	set("mana",11400);
	set("mana_factor",285);
	set("force_factor", 285);
	set("max_kee", 12500);
	set("max_gin", 12500);
	set("max_sen", 12500);
	set("combat_exp",5487200);
	set("daoxing",5487200);

	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg", ({
		"����ŵ˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));

	set_skill("dodge", 381);
	set_skill("force", 381);
	set_skill("parry", 381);
	set_skill("unarmed", 381);
	set_skill("sword", 381);
	set_skill("westsword",381);
	set_skill("boxing",381);
	set_skill("balei",381);
	set_skill("spells",381);
	set_skill("baoping", 381);
	map_skill("parry","westsword");
	map_skill("sword","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","baoping");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/bp_cloth")->wear();
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
	message_vision("$N��Цһ��������"BLU"�����֮��"NOR"������ˣʲô������\n",me);
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
			message_vision(HIY"$N�߾ٱ�ƿ��һ��쫷���$n�Ľ�������\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIY"$N�����Ϳ��Ʋ�ס�Լ����������Ȼ�������ص�ˤ����������\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIW"$N�����³�����ǿ����ס$n��쫷硣\n"NOR,me,ob);
		}
		break;
		case 1:
		{
			message_vision(HIC"$NͻȻ�����ȥ��Ȼ�������������$n����������\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N��Ȼ��$n�������´���֮��,$N��æ�ӵ���ת�˳�����\n"NOR,me,ob);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
				ob->start_busy(2);
			}
			else
			{
				message_vision(HIG"$N�͵�һ����$nһͷ�Ե����¡�\n"NOR,me,ob);
				ob->start_busy(1);
			}
		}
		break;
		case 2:
		{
			message_vision(HIC"$N�������б�ƿ����ƿ�����������ʯ��ֱ��$n��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N��ʯͷ���˸�ͷ��Ѫ����\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
				me->start_busy(1);
			}
			else
				message_vision(HIG"$N�����λ����ʯͷ����ɱ��һ��Ѫ·��\n"NOR,me);
		}
		break;
		case 3:
		{
			message_vision(HIW"$N����һ����������ȣ�ֻ��һ�ɺ���ֱϮ$n\n"NOR,ob,me);
			if(random(2)==0)
			{
				message_vision(HIW"$N���������У�����֫����ľ���ƺ�Ҫ����һ�㣡\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
				me->start_busy(3);
			}
			else
				message_vision(HIW"$N��ͣ���˶��Լ������壬�Ա���һ����ů��\n"NOR,me);
		}
		break;
	}
	if( random(7) == 5 )
	powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}
void die()
{
	object ob = query_temp("my_killer");
	if((ob&&ob->query("12gong/mojie")=="done") && (ob&&ob->query("12gong/baoping")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵�ʮһ����ƿ������ƽ�սʿŬ����\n"NOR,users());
		ob->set("12gong/baoping","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
