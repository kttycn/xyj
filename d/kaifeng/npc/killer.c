// killer.c

inherit NPC;
#include <ansi.h>;

string ask_me();

void create()
{
	set_name("��ƽ��", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "����");
	set("age", 35);
	set("long","����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
	set("combat_exp",60000);
	set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 50);
	set("apply/defense", 50);

	set("max_gin", 800);
	set("max_kee", 800);
	set("max_sen", 800);
	set("max_force", 800);
	set("max_mana", 800);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);

	set("inquiry", ([
		"������" : (: ask_me :),
	]));

	setup();

	carry_object("/d/obj/cloth/cloth")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void init()
{
	::init();	
	add_action("do_bihua", ({ "fight", "kill" }));
	add_action("do_halt", "halt");
}

string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "����Ȩ�ٿ������ᣡ\n";

	command("chat* hi");
	command("chat ���ڱ�������ʽ��ʼ��ȫ�弯�ϣ�");
	for ( i=sizeof(ob); i>0; i-- ) {
		ob[i-1]->move(environment());
	}

	return "�ã����ڱ�������ʽ��ʼ��ȫ�弯�ϣ�\n";
}

int do_bihua(string arg)
{     
	object ob1, ob2;

	ob1 = this_player();
        
	if (!arg) return 0;
	ob2 = present(arg, environment(ob1));
	if (!ob2) return 0;
	if ( ob2 == this_object() )
	{
		command("say " + ob1->name() + "���㲻�ܸ��ұȻ���");
		return 1;
	}

	if ( query_temp("busy") ) {
		write("ÿ��ֻ�������˲μӱ��䡣\n");
		return 1;
	}

	if( !ob1->query_temp("dagu") ) {
        write("��ƽ��˵��: �����߱����ȴ�ı��ޣ�\n");
		return 1;
	}

	if( !ob2->query_temp("dagu") ) {
		write("��ƽ��˵��: �����߱����ȴ�ı��ޣ�\n");
		return 1;
	}

	if( query_verb()=="fight" && userp(ob2) && ob2->query_temp("pending/fight") !=ob1 )
		return 0;

	if (!ob2->is_character()) return 0;

        ob1->delete_temp("halted");
        ob2->delete_temp("halted");             
        
	CHANNEL_D->do_channel(this_object(), "chat", ob1->name() 
		+ "��" + ob2->name() + "������" + environment()->query("short") + "��ʼ�����۽���\n");

	set_temp("busy",1);
	call_out("observe",1,ob1,ob2);

	return 0;
}

int observe(object ob1,object ob2)
{
	if(ob1->is_fighting()) 
	{
		call_out("observe",1,ob1,ob2);
		return 1;
	}

	this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

	if (ob1->is_ghost()) {
		command("chat " + ob1->name() + "���������ˣ�\n");
		return 1;
	}

	if (ob2->is_ghost()) {
		command("chat " + ob2->name() + "���������ˣ�\n");
		return 1;
	}

	if ( !present(ob1, environment()) ) 
	{
		command("chat " + ob1->name() + "��Ķ����ˣ�\n");
		return 1;
	}

	if ( !present(ob2, environment()) ) 
	{
		command("chat " + ob2->name() + "��Ķ����ˣ�\n");
		return 1;
	}
           
        if (ob1->query_temp("halted"))
         {
	       ob1->delete_temp("halted");
               command("chat " + ob1->name() + 
                       "��;�������䣡\n");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->name() + 
                       "��;�������䣡\n");
                return 1;
         }

	if ( ob1->query("kee")*2 > ob1->query("max_kee")) 
	{
		if  (ob2->query("kee")*2 > ob2->query("max_kee")) {
			command("chat " + ob1->name() 
				+ "��" + ob2->name() + "���䲻��ʤ����\n");
			return 1;
		}
		command("chat " + ob1->name() 
			+ "����սʤ" + ob2->name() + "��\n");
	}
	else
	{
		command("chat " + ob2->name() 
			+ "����սʤ" + ob1->name() + "��\n");
	}
	ob1->delete_temp("dagu");
	ob2->delete_temp("dagu");
	return 1;

}

int do_halt()
{
	object me = this_player();

	if (me->is_fighting())
	me->set_temp("halted",1);
	return 0;
}
