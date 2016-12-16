// by happ@YSZZ

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string ask_chuxian(object me);
string ask_cancel();
string ask_bigan();
#include <ansi.h>

void create()
{
	set_name("槼�", ({"da ji", "daji", "master"}));
	set("long",
"���������Լ���ɫ���˳�����ҵ��槼�,��˵�����ѱ�\n��ն,����Ů����￪��������������,�������½紴����ԯĹ.\n");
	set("title", "��ԯĹ����");
	set("gender", "Ů��");
	set("age", 20);
	set("class", "huli");
	set("attitude", "friendly");
	set("per", 40);
	set("int", 30);
	set("max_kee", 3500);
	set("max_gin", 4600);
	set("max_sen", 3200);
	set("force", 4800);
	set("max_force", 1800);
	set("force_factor", 80);
	set("max_mana", 2000);
	set("mana", 2600);
	set("mana_factor", 70);
	set("combat_exp", 2400000);

	set("eff_dx", 200000);
	set("nkgain", 350);

	set_skill("literate", 180);
	set_skill("unarmed", 160);
	set_skill("dodge", 190);
	set_skill("force", 200);
	set_skill("parry", 180);
	set_skill("needle",180);
	set_skill("blade", 150);
	set_skill("spells", 180);
	set_skill("xuanhu-shentong", 180);
	set_skill("fox-hand", 180);
	set_skill("tiaobo",200);
	set_skill("xuanhu-xinfa", 180);
	set_skill("xuanhu-blade", 150);
	set_skill("tianyi-zhen", 190);
	set_skill("huxing-steps", 200);
	map_skill("spells", "xuanhu-shentong");
	map_skill("unarmed", "fox-hand");
	map_skill("force", "xuanhu-xinfa");
	map_skill("blade", "xuanhu-blade");
	map_skill("needle","tianyi-zhen");
	map_skill("parry", "xuanhu-blade");
	map_skill("dodge", "huxing-steps");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "feisha" :),
	}) );

	set("inquiry", ([
		"name" : "�Ҿ���槼���Ư���ɡ� ",
		"here" : "˭Ҳ�������ҵĵ�������Ұ��",
		"����" : "�����ҵİ��ˡ�//shy",
		"����" : (: ask_chuxian :),
		"cancel" : (: ask_cancel :),
		"�ȸ�" : (: ask_bigan :),
	]) );
	create_family("��ԯ��Ĺ", 2, "����");
	setup();

	carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/qujing/xuanyuan/obj/needle")->wield();
	carry_object("/d/obj/book/tiaobo");
}

void init()
{
	object ob = this_player();
	if( present("bigan heart",ob) )
		command("say ��λ"+RANK_D->query_respect(ob) +"����Ĳ����������ҽ����𣿣�ok��");
	add_action("do_ok","ok");
}

int accept_object(object who, object ob)
{
	object book;
	book=present("tiaobo book",who);
	if( ob->query("id") == "old hen" )
	{
		if( who->query_temp("mark/hen") < 5 + random(2) )
		{
			command("say �������ĸ���ˣ���֪"+who->name()+"�ܷ�����ŪЩ������\n");
			who->add_temp("mark/hen",1);
			return 1;
		}
		else 
		{
			if(book)
			{
				command("say ��Ȼ"+who->name()+"��ô���壬ū��Ҳ��һ��������\n");
				command("haha");
				book->move(who);
				tell_object(who,"槼�������һ���飡\n");
				who->delete_temp("mark/hen");
				return 1;
			}
			command("say ����������㶫���ģ�����һʱ���Ҳ��֪����ʲô�ã�\n");
			command("grin");
			return 1;
		}
		return 1;
	}
	return 0;
}

int do_ok()
{  
	int i;
	object ob = this_player();
	object *inv;
	if( ! present("bigan heart",ob) ) return 0; 
	message_vision("$N�ӻ����ͳ�һ�ź��ĵݸ���槼���\n",ob);
	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if (inv[i]->query("heart"))
			destruct(inv[i]);
	}

	call_out("eat",2,ob);
	return 1;
}

void eat(object ob)
{
	message_vision(HIY"槼����űȸɵĺ��Ľ����ζ�ĳ��š�\n"NOR,ob);
	message_vision(HIY"槼�����ЦЦ��ζ��������\n"NOR,ob);
	command("say ��λ" +RANK_D->query_respect(ob) + "��ʲôҪ�󾡹��ᡣ");
	tell_object(ob,"槼���������ζ�����ˡ�\n");
	ob->set_temp("can_in",1);
}	 

string ask_bigan()
{
	object ob = this_player();

	if( ob->query("obstacle/xuanyuan") == "done" )
		return "�Ǹ��϶����������ˡ�\n";
	 
	command("grin");
	command("say �Ǻã��Ҿ�����ȥ�����Ǹ��ϲ����ġ�\n");
	ob->delete("env/brief");
	ob->move("/d/qujing/xuanyuan/dream");
	return "�����˴��ö���������\n";
}



void attempt_apprentice(object ob)
{
	if ( !((string)ob->query("gender")=="Ů��")){
		command("shake");
		command("say ������ֻ��Ůͽ����λ" +RANK_D->query_respect(ob) + "���ǰݱ��˰ɡ�\n");
		return;
	}
	if ( (int)ob->query("per") < 25){
		command("shake");
		command("say ���ҿ���λ" +RANK_D->query_respect(ob) + "��ģ���ƺ��е���ⲻȥ����\n");
		return;
	}

	if ((int)ob->query_skill("xuanhu-shentong",1) < 50) {
		command("say ��ı��ŷ���̫����,����ŬŬ�������һ�°�!");
		command("kick2 " + ob->query("id"));
		return;
	}
	command("pat "+ob->query("id"));
	command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������ԯĹ������\n");
	command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "huli");
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}
string ask_chuxian(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��ԯ��Ĺ") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"槼���ĿԶ��ǰ����\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"��־����\n"NOR;
	}
	return ("�����ﲻ���ס�");
}

void destruct_me (object me)
{
	destruct (me);
}

void die()
{
	unconcious();
}

void unconcious()
{
	object me = this_object();
	object ob = query_temp("my_killer");
	object where = environment (me);

	if( !ob || !present("zhou wang",environment(ob)) )
	{
		::die();
		return;
	}
	ob->set_temp("obstacle/daji_killed",1);
	message_vision ("\n$N�޿��κε���������ԭ����һֻ�߲ʾ�β���ꡣ\n",me);
	message_vision ("\n�ʺ�������������Ů������������ġ�\n",me);
	if( ob->query_temp("can_in") )
	{
		load_object("/obj/empty");
		me->move("/obj/empty");
		call_out ("nvwa_appearing", 1, ob, where);
	}
	message_vision ("�ʺ������϶�ȥ\n\n",me);
	call_out ("destruct_me",3,me);
}

void nvwa_appearing (object who, object where)
{
	object nvwa = new ("/d/qujing/xuanyuan/npc/nvwa");
	string add = where->query("short");

	nvwa->move(where);
	nvwa->announce_success (who);
	return ;
}

int accept_fight(object ob)
{
	ob->apply_condition("killer", 100);
	kill_ob(ob);
	return 1;
}

void kill_ob (object ob)
{
	object me = this_object();
	set_temp("my_killer",ob);
}
