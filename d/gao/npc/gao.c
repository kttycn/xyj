//Cracked by Roath
// happ@YSZZ
 
// gao.c
#include <ansi.h>

inherit NPC;
string ask_girl();

void create()
{
	set_name("��Ա��", ({"gao yuanwai", "gao"}));

	set("long","�߼�ׯ�����ˣ��Ե��ֺ����ģ�\n��˵�����Ӧ���ֺǺǵأ���ȴ��ü����������������ʲô���£�\n");
	set("gender", "����");
	set("age", 46);
	set("title", "ׯ��");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set_skill("unarmed", 15);
	set_skill("dodge", 30);
	set_skill("parry", 15);
	set("inquiry", ([
		"name": "�Ϸ��ոߣ����Ǽ��е����ˣ�\n",
		"here": "����ׯ��Ҳ��\n",
		"��С��": (: ask_girl :),
		"����" : (: ask_girl :),
	]) );

	setup();
	add_money("silver", 3+random(5));
	carry_object("/d/ourhome/obj/choupao")->wear();
}


void init()
{
	remove_call_out("check");
	call_out("check",1);
}

void check()
{
	object room = environment();
	object lady = present("cui lan",room);        
	object ob;
	if (!lady) return ;
	if( lady->query_leader() == 0 )
		return ;
	ob = present(lady->query_leader(),room);
	if( ob == 0 )
		return ;
	remove_call_out("check2");
	call_out("check2",1,ob);
}
void check2(object ob)
{
	int i;
	object cuilan;

	if (ob->query("obstacle/gao") == "done")
		return;
	if( !ob->query_temp("pig_killed") )
		return;

	i = random(500);
	if( ! cuilan = present("cui lan", environment(ob)))
		return;
	cuilan->set_leader(0);
	ob->add("obstacle/number",1);
	ob->set("obstacle/gao","done");
	ob->add("daoxing",i+4000);
	ob->add("score", 10);
	message_vision("$Nһ��Ů����������Ů��ͷʹ�ޣ�\n",this_object());
	command("chat ��л"+ob->query("name")+"����ׯ������֣��ȳ�СŮ������");
	message("channel:chat",HIW"������ն������Ա��(Gao yuanwai)��"+ob->query("name")+"˳����������ȡ������أ�\n"NOR,users());
	tell_object (ob,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	ob->delete_temp("pig_killed");
	ob->save();
	return;
}

string ask_girl()
{
	object ob = this_player();
	object cloth = new("/d/gao/obj/cloth");

	if( ob->query("obstacle/gao") == "done" 
	|| ob->query_temp("girl_asked") )
	{
		command("?");
		return("�������ʲô��");
	}

	command("disapp1 gao");
	command("cry1");
	cloth->move(ob);
	ob->set_temp("girl_asked",1);
	command("say ����Ů����������ɽһ��Ұ��ְ�ռ�ˣ���֪����û���ֶΣ����ҾȻ�Ů���� ");
	message_vision("$N��$nһ��Բ�컨����\n", this_object(), ob);
	return("��������ǰ�����·���");       
}        
