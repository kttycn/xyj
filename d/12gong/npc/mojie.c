inherit NPC;
#include "star.h"
 
void create()
{
	set_name("����˹", ({"hades", "tian xie"}));
	set("long", "��˵�е�ڤ������˹���ػ�����Ы��.\n");
	set("gender","����");
	set("title", HIB"��������"NOR);
	set("age",37);
	set("con",45);
	set("per",30);
	set("str",63);
	set("int",64);

	set("max_force",5400);
	set("force", 10800);
	set("max_mana",5400);
	set("mana",10800);
	set("mana_factor",270);
	set("force_factor", 270);
	set("max_kee", 10000);
	set("max_gin", 10000);
	set("max_sen", 10000);
	set("combat_exp",4665600);
	set("daoxing",4665600);

	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg", ({
		"����˹˵������֪��ʱ���ټ����ŵ��ȣ�\n"   
	}));

	set_skill("dodge", 361);
	set_skill("force", 361);
	set_skill("parry", 361);
	set_skill("unarmed", 361);
	set_skill("sword", 361);
	set_skill("westsword",361);
	set_skill("boxing",361);
	set_skill("balei",361);
	set_skill("spells",361);
	set_skill("mojie", 361);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","mojie");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/mj_cloth")->wear();
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
	message_vision("$N��Цһ��������"HIB"��������"NOR"������ˣʲô������\n",me);
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
			message_vision(YEL"$Nһ����Ц���޲���ɽ��������$n��ȥ����\n",ob,me);
			if(random(2)==0)
			{
				message_vision(YEL"$N�ڲ�����ҡ���ţ�\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(YEL"$N�����ˮ��������ǿ�˽�����\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N����һ������һ����ɫ�Ķ�����$n��ȥ��\n",ob,me);
			if(random(2)==0)
			{
				message_vision(YEL"$N��ʱ��Ѭ����ͷ��\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(YEL"$N��ת��ͣ������һ�ᶾ����ʧ����Ӱ���١�\n"NOR,me);
		}
		break;
		case 2:
		{
			message_vision(HIR"$N�������С����ڣ�\n",ob);
			ghost=new("/obj/npc/ghost.c");
			ghost->move(environment());
			ghost->set("combat_exp",ob->query("combat_exp"));
			ghost->set("max_kee",ob->query("max_kee"));
			ghost->set("max_sen",ob->query("max_sen"));
			ghost->kill_ob(ob);
			message_vision(HIC"��֪�Ӻδ�����������С����$Nɱȥ��\n"NOR,me);
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
	if((ob&&ob->query("12gong/renma")=="done") && (ob&&ob->query("12gong/mojie")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"���ƽ�ʮ�������ŵ���(Ya dian na):"+ob->name()+
		"�����˵�ʮ��Ħ������������ƽ�սʿŬ����\n"NOR,users());
		ob->set("12gong/mojie","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"��Ӯ����ʮ�����");
	}
	::die();
}
