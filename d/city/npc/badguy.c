//By waiwai@mszj 2000/11/13

void consider();

#include <ansi.h>
#include <combat.h>
inherit NPC;
void create()
{
	set_name("�����ϲ�", ({ "dizhu laochai", "dizhu", "laochai" }) );
	set("long",CYN
		"һ�������˰̼Ӻ���ļһ�,ר�Ÿ�եȡ����Ѫ���Ĺ����������ﻹɱ��Խ������������\n"NOR);
	set("attitude", "aggressive");
//        set("attitude", "friendly");
	set("per", 1);
	set("combat_exp", 100000+random(4000000));
	set("bellicosity", 10000);
	set("chat_chance", 30);
	set("chat_msg", ({
		HIB"�����ϲ�ȵ�����������ҪǮ��Ҫ������\n"NOR,
		HIB"�����ϲ�Ц����С����ȥ���ɣ�\n"NOR,
		(: random_move :),
	}) );

	set_skill("unarmed", 20+random(20));
	set_skill("blade", 20+random(20));
	set_skill("parry", 20+random(20));
	set_skill("dodge", 20+random(20));
	set_skill("stealing", 200);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 30+random(10));
	set_temp("apply/move", 10);
	
	setup();
	carry_object("/d/city/obj/xiangyan")->set_amount(3);
	carry_object("/d/city/obj/gourou")->set_amount(5);
	carry_object("/d/city/obj/yexing")->wear();
	carry_object("/d/city/obj/guiblade")->wield();
}

void init()
{	
	object ob;

	set_heart_beat(1);
	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("dizhu");
		call_out("dizhu", 1, ob);
	}
}

void dizhu(object ob)
{
	set("leader",ob->query("id"));
	switch( random(2) ) {
		case 0:
			command("kill ob");
			command("look " + ob->query("id"));
			command("follow " + ob->query("id"));
			command ("grin");
			command("xiyan");
			break;
		case 1:
			command("look " + ob->query("id"));
			command("follow " + ob->query("id"));
			command ("grin");
			command("eat gourou");
			break;
	}
}

void die()
{
	int i = random(500);
	object who = this_player();
	object me = this_object();

	command("chat "+who->query("name")+"����һ��Ҫ���㱨��ģ�");
	message_vision("$N�ҽ�һ�������ˡ�\n",who);

	who->add("combat_exp",500+i);
	who->add("daoxing",500+i);
	who->add("potential",20+i/10);

	tell_object(who, "��õ���"+chinese_number(500+i)+"����ѧ����,"+
	COMBAT_D->chinese_daoxing(500+i)+"���к�"+chinese_number(20+i/10)+
			    "��Ǳ�ܣ�\n");
	destruct(me);
}
