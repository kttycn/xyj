// xunbu.c Ѳ��
#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name("��˳�Ѳ��", ({ "xunbu"}));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 120);
	set_skill("blade",120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 50);

	set("force", 1000); 
	set("max_force", 1000);
	set("force_factor", 50);

	set("inquiry", 
	([
		"ͨ����"  : (: ask_me :),                       
	]));

	setup();
	carry_object("/d/obj/weapon/blade/blade")->wield();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
	if (clonep()) call_out("randommove", 10);
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if( ob->query_condition("killer") && userp(ob) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object me;

	me=this_object();
	if (is_fighting()) return;
	if (wizardp(ob)) return;
	if(interactive(ob) && !ob->is_fighting() && ob->query_condition("killer")) 
	{
		me->set("killer_name",ob->query("name"));
		call_out("do_kill", 0, me, ob);
	}
}

int do_kill(object me,object ob)
{	
	if(me->is_fighting()) return 0;
	if (wizardp(ob)) return 0;
	if( objectp(ob) && present(ob, environment(me))
	&& !environment(me)->query("no_fight"))
	{
		if (!me->query_temp("marks/kill1")){
			command("look "+ob->query("id"));
			message_vision(CYN "$N��$n˵����ɱ���ˣ���Ҫ������"
				+RANK_D->query_rude(ob)+"����Ͽ������ɣ�\n" NOR, me,ob);
			me->set_temp("marks/kill1",1);
		}
		me->set_leader(ob);
		me->kill_ob(ob);
		call_out("checking", 0,  me);   
	}
	else
		call_out("waiting", 1, me);     
	return 1;
}
int waiting(object me)
{
	object ob;
	
	if ( objectp(ob) )
	{
		if (ob->is_ghost())
		{
			me->delete_temp("marks/kill1");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(ob, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob,ob1;
	
	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
        return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
		 &&ob->query("victim_name") ==me->query("killer_name") )
	{
		command("say ��������ɱ��һ��ͨ����������ѽ�������Ȼ�ȥ����ɡ�");
		me->delete("killer_name");
		this_object()->delete_temp("marks/kill1");
		call_out("do_back", 1, me);
        return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}
int do_back(object me)
{
	me=this_object();
	message("vision", "Ѳ��ɱ�����ڵ��뿪�ˡ�\n", 
		environment(), me );
	me->move("/d/fenghuang/guangchang");
	message("vision", "Ѳ��ɱ�����ڵ����˹�����\n", environment(), me );

	me->set_leader(0);
	return 1;
}
void randommove()
{
	call_out("randommove", 10);
	if (living(this_object()) && !is_fighting()) random_move();
}
string ask_me()
{
	object ob=this_player();
	if(ob->query_condition("killer")>0)
		return "�ߣ�ͨ�������������ѣ��㻹�ǹԹԵ������ɣ�";
	if(ob->query("shen")<=-100){
		write("Ѳ���������㿴����֪����Щʲô���⡣\n");
		return RANK_D->query_respect(this_player()) + 
			"���ܶԲ��𣬲��ܸ����㣬�����ҿ������ӵ�����ͨ������";
	}
	if(ob->query("shen")>-100){
		write("Ѳ������������ĵ�˵����"+FINGER_D->get_killer());
		message("vision","Ѳ�����ĵ���"+ob->name()+"����˵�˼��仰��\n",
			environment(ob), ({ob}) );
		return "���ӷ�����������ͬ�ɱ���ˣ���Ҫ������";
	}	
}
