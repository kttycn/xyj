// dapeng.c...weiqi, 97.09.27.

inherit NPC;
inherit F_MASTER;
string avenge();

void create()
{
	set_name("��������", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "ѩɽ֮��");
	set("gender", "����" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "��λ����������ȷ����������˵��������������Ҳ�е����ݹ�ϵ��\n���������ġ��˾ˡ������������ֿ�ȸ���������ˣ�ȴҲ�������࣬\n��������֮�ʸ����Ž��������ƽ������ľ��Ǻ��С�\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 1, "��ʦ");
	set("rank_info/respect", "����");

	set_skill("unarmed", 250);
	set_skill("cuixin-zhang", 250);
	set_skill("dodge", 300);
	set_skill("xiaoyaoyou", 300);
	set_skill("parry", 270);
	set_skill("sword", 280);
	set_skill("bainiao-jian", 280);
	set_skill("blade", 280);
	set_skill("bingpo-blade", 280);
	set_skill("throwing", 280);
	set_skill("force", 280);   
	set_skill("ningxue-force", 280);
	set_skill("literate", 250);
	set_skill("spells", 260);
	set_skill("dengxian-dafa", 260);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxue-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "juanbi" :),
		(: cast_spell, "tuntian" :),
		(: perform_action, "blade", "yaowu" :),
		(: exert_function, "mohu" :),
		(: exert_function, "ningxie" :),
		(: perform_action, "sword", "chaofeng" :)
	}) );
	set("inquiry", ([
		"����" : (: avenge :),
	]) );

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/obj/misc/seven_belt")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="����"  )
	{
		command("kick " + ob->query("id"));
		command("say ���ߣ����ߣ���һ�������о�������\n");
		return;
	}

	if( (string)ob->query("family/family_name")=="��ѩɽ" ){
		if( (int)ob->query("family/generation") > 3   ){
			command("say û���Ĵ󻤷����Ƽ����������ѿ��ǡ�\n");
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 500000 ){
				command("nod ");
				command("say �ã�" + RANK_D->query_respect(ob) + "�úø��Ҹɣ��������п�Ϊ��\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say �㻹������ʨ���������������Űɡ�\n");
			}
		}
	}

	else{
		command("hmm");
		command("say ��λ" + RANK_D->query_respect(ob) + "���ڱ��ſ�û��һ��������¡�\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

void init()
{       
	object ob=this_player();

	::init();
	if ( ((string)ob->query("gender")=="����") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	switch( random(1) ) {
		case 0:
			command("kick " + ob->query("id"));
			command("say ����ͺ��");
			break;
	}
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="��ѩɽ")
		return ("�㲻�Ǳ��ŵ��ӣ������뱾���θɣ�");
	if(who->query("faith")<1000)
		return ("���ڱ���������������������Ŭ�����С�");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("����δ����Ѷ");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("��������������һ��");
	command("say �������ȥΪ�㱧��");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"ֻ���������������һָ��\n");
	tell_room(where,"��ɽ���ߺ��ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")
+"ץ��������");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ���Ҵ�ѩɽ����");
	this_object()->kill_ob(killer);
	return("��������");
}  
