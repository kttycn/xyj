//created 5-20-97 pickle

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;
int rank_me();
string avenge();

void create()
{
	set_name(HIY"�Ʒɻ�"NOR, ({"huang feihu", "huang", "feihu", "master"}));
	set ("long", @LONG
����������Ʒɻ������ܵ�һ�󽫣������
������֮�׶���̩ɽ������ʥ��ۣ��·�Ѱ
������ɫ��ţ�����䡣
LONG);
 
	set("title", HIW"����̩ɽ������ʥ���"NOR);
	set("gender", "����");
	set("age", 43);
	set("str", 45);
	set("per", 35);
	set("int", 30);
	set("cor", 50);
	set("cps", 40);
	set("combat_exp", 8000000);
	set("daoxing", 10000000);

	set_skill("spear", 300);
	set_skill("force", 290);
	set_skill("dodge", 280);
	set_skill("literate", 280);
	set_skill("parry", 260);
	set_skill("unarmed", 280);
	set_skill("wuyue-spear", 300);
	set_skill("spells", 290);
	set_skill("pingtian-dafa", 280);
	set_skill("moshenbu", 280);
	set_skill("huomoforce", 280);
	set_skill("moyun-shou", 280);

	map_skill("force", "huomoforce");
	map_skill("spells", "pingtian-dafa");
	map_skill("unarmed", "moyun-shou");
	map_skill("spear", "wuyue-spear");
	map_skill("parry", "wuyue-spear");
	map_skill("dodge", "moshenbu");

	set("max_sen", 6000);
	set("max_kee", 8000);
	set("force", 10000);
	set("max_force", 6000);
	set("mana",6000);
	set("max_mana",3000);
	set("daoxing",5000000);
	set("force_factor", 200);
	set("mana_factor", 150);
	set("inquiry", ([
		"����" : (: avenge :),
		"ְλ": (: rank_me :),
	]));
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "buhui" :),
		(: perform_action, "unarmed", "zhangxinlei" :),
		(: perform_action, "unarmed", "zhangxinlei" :),
	}) );
 
	create_family("���ƶ�", 1, "��");
	setup();
 
	carry_object("/d/obj/weapon/spear/huaji2")->wield();
	carry_object("/d/city/obj/xjdan");
	carry_object("/d/obj/armor/jinjia")->wear();
}
 
int accept_fight(object me)
{
	command("say �Ϸ����أ��������˷��������ˡ�\n");
	return 0;
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "ƽ���ʥ")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "���ƶ�"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", RED"��ɽ�Ŷ�"NOR+RED"��"BLU"Ѳ��С��"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", RED"��ɽ�Ŷ�"NOR+RED"��"YEL"��ɽ��"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", RED"��ɽ�Ŷ�"NOR+RED"��"RED"ʳ������"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", RED"��ɽ�Ŷ�"NOR+RED"��"MAG"�ž�����"NOR);
		} else {
			me->set("nick", RED"��ɽ�Ŷ�"NOR+RED"��"CYN"ͨ�춴��"NOR);
		}

		tell_object(me, "�Ʒɻ�����˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"�Ʒɻ���"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

int attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="���ƶ�") {
		if (((int)ob->query("daoxing") < 400000 )) {
			command("say " + RANK_D->query_respect(ob) +
			"�ĵ��в��������Щ��ѧ�ط�������������\n");
			return 0;
		}
		command("haha "+ob->query("id"));
		command("say ��������֣����Ǽ������������Ҵ���Щ������ȥ���Ұ���pk��û���У�\n");
		command("recruit " + ob->query("id") );
		return 0;
	}
	command("say " + RANK_D->query_respect(ob) +"�����ٿ�������ǹ���գ�\n");
	return 1;
}
/*
{	
string myname=RANK_D->query_respect(me);
 if ((int)me->query_skill("spear")< 200) 
//	if ((int)me->query_skill("spear")< 200) 
		{
			command("say ��"+myname+"�ٿ�������ǹ���գ�");
			return 0;
		}
	if ((int)me->query_skill("stick") < 200 )
		{
			command("say ��"+myname+"֪��������������䣿");
			return 0;
		}
	command("say ��������֣����Ǽ������������Ҵ���Щ������ȥ���Ұ���pk��û���У�\n");
	command("recruit " + me->query("id") );
	return 1;
}
*/
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
	ob->set("title", "�����������ɽ��");
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="���ƶ�")
		return ("�㲻�Ǳ��ɵ��ӣ������뱾����θɣ�");
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
	tell_room(where,"ֻ���Ʒɻ������һָ��\n");
	tell_room(where,"����ħ�����ڣ���ȥ��"+killer->query("name")+"ץ����\n");
	tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")
+"ץ��������");
	killer->move(where);
	tell_room(where,killer->query("name")+"���ӿ�������������\n");
	command("say ������������ɱ���һ��ƶ�����");
	this_object()->kill_ob(killer);
	return("��������");
}  
