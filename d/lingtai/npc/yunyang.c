//yunyang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/d/obj/lquest.h"
#include "/d/lingtai/npc/zhenfa.h"

int rank_me();
string do_task();
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();
void re_rank(object who);

void create()
{
		 set_name("��������", ({"master yunyang", "master", "yunyang"}));
		 set("long", "����������������ʦʵ�ǰ�ʦ���ѣ�Ҳ�����Ƕ������ܹܣ�
����׳��ʱ��ħ�����������˳ơ�С��ʦ����\n");
		set("faith",4000);
		 set("gender", "����");
	set("title", "С��ʦ");
	set("class", "taoist");
		 set("age", 70);
		 set("attitude", "friendly");
		 set("shen_type", 1);
		 set("rank_info/respect", "�ϵ���");
		 set("per", 30);
	set("int", 30);
	set("str", 30);
	set("cps", 30);
	set("max_kee", 1100);
	set("max_gin", 1100);
	set("max_sen", 1100);
	set("force", 2300);
	set("max_force", 1200);
	set("force_factor", 80);
	set("max_mana", 1200);
	set("mana", 2300);
	set("mana_factor", 60);
	set("combat_exp", 800000);
	set("daoxing", 1500000);

	set("eff_dx", 250000);
	set("nkgain", 400);

	set_skill("literate", 90);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("stick", 120);
	set_skill("spells", 120);
	set_skill("dao", 120);
	set_skill("puti-zhi", 120);
	set_skill("wuxiangforce", 120);
	set_skill("force", 120);
	set_skill("qianjun-bang", 120);
	set_skill("jindouyun", 120);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "qiankun" :),
		(: perform_action, "leiting" :),
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
		(: cast_spell, "thunder" :)
	}) );

	set("inquiry", ([
		"����": (: ask_mieyao :),
		"��ɽ": (: expell_me :),
		"leave": (: expell_me :),
		"task": (: do_task :),
		"cancel": (: ask_cancel :),
		"ְλ": (: rank_me :),
		"������" : (: ask_sixiang :),
		"������" : (: ask_bagua :),
	]) );

	create_family("����ɽ���Ƕ�", 1, "��");
	setup();

	carry_object("/d/lingtai/obj/xiangpao")->wear();
	carry_object("/d/lingtai/obj/bang")->wield();
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}

int rank_me()
{
	object me=this_player();
	int exp;
	exp=(int)me->query("combat_exp");
	if( me->query("title") == "����ɽ���Ƕ�����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
	if( (string)me->query("family/family_name") == "����ɽ���Ƕ�"){
		if( exp <= 500000 ) {
			return notify_fail("��������ѧ̫�ͣ���������Ҫʲôְλ��\n");
		} else if(exp <= 1000000 ){
			me->set("nick", CYN"���緽��"NOR+RED"��"BLU"ӭ�͵�ͯ"NOR);
		} else if(exp <= 2000000 ){
			me->set("nick", CYN"���緽��"NOR+RED"��"YEL"ƽ������"NOR);
		} else if(exp <= 5000000 ){
			me->set("nick", CYN"���緽��"NOR+RED"��"RED"��ħ����"NOR);
		} else if(exp <= 10000000 ){
			me->set("nick", CYN"���緽��"NOR+RED"��"MAG"������ʦ"NOR);
		} else {
			me->set("nick", CYN"���緽��"NOR+RED"��"CYN"��������"NOR);
		}

		tell_object(me, "�������˶���˵���������"+me->query("nick")+"��\n");
		tell_room(environment(me),
"�������˶�"+me->query("name")+"˵���������"+me->query("nick")+"��\n", ({me, me}));
		CHANNEL_D->do_channel(this_object(),"chat","�����豾�ŵ���"+me->query("name")+""+me->query("nick")+HIC"һְ�������λ�ɳ����������");
		me->save();  
	}
	return 1;
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
		if (((int)ob->query("daoxing") < 100000 )) {
			command("say ��������֮ʿ���صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ�����ǡ�\n");
			return;
		}
		command("smile");
		command("say �ü����ü���ʱ����ħ��������ֺ��С���"  + RANK_D->query_respect(ob) +
"����������֮ʿȴ���ټ���\n");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
		  return;
}
string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
		command("say �����ִ����ɽ��Ϊʦȴ�м��仰˵��");
		me->set_temp("betray", 1);
		command("say �ҷ���ɽҲ���������ɣ��������ڡ����й�����ɽ��ɽ�棡");
		return ("����Ҫ��ɽ��ȴ����ɽ��ͷ������Ը��(agree)?");
	}
	return ("ƶ����֪��");
}
void init()
{
	::init();
	re_rank(this_player());
	add_action("do_agree", "agree");
	add_action("do_fuming","fuming");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray") &&
	this_player()->query("family/family_name") == "����ɽ���Ƕ�") {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		this_player()->add("betray/count", 1);
		this_player()->add("betray/fangcun", 1);
		command("say �����ҷ���ɽ��ǳ�ݲ��������������ɽȥ�ɣ�");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query("taoist") )
			this_player()->delete("taoist");
		if( this_player()->query_skill("dao") )
			this_player()->delete_skill("dao");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );

		this_player()->set("title", "��ͨ����");
		this_player()->save();
		command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
		return 1;
	}
	else return notify_fail("ʲô��\n");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"�������˾������е�ľ�ȣ���ʱһ����â�����\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"��������,������ħΪ���Ρ�\n"NOR;
	}
	return ("ƶ�������ס�");
}

string do_task()
{
	object me=this_player();

	if(me->query("family/family_name")!="����ɽ���Ƕ�")
		return ("�㲻�Ǳ��ŵ��ӣ�");
	if(me->query("combat_exp")<1100000)
		return ("��ľ��黹������");
	if(me->query("longquest/name"))
		return ("��������������");

	give_quest(me);
	return ("�����ȥ�ɣ�");
}

int do_fuming()
{
	  fuming(this_player());
	  return 1;
}

void re_rank(object who)
{
	int faith=who->query("faith");
	if(who->query("class")!="taoist")return;
	if(faith<=100){
		if(who->query("gender")=="Ů��")
			who->set("title","����ɽ���Ƕ�����");
		else who->set("title","����ɽ���Ƕ���ʿ");
		return;
	}else if(faith<=300){
		who->set("title","����ɽ���Ƕ�С����");
		return;
	}else if(faith<=600){
		who->set("title","����ɽ���Ƕ�����");
		return;
	}else if(faith<=1000){
		who->set("title","����ɽ���Ƕ�С��ʦ");
		return;
	}else if(faith<=1800){
		who->set("title","����ɽ���Ƕ���ʦ");
		return;
	}else if(faith<=3000){
		who->set("title","����ɽ���Ƕ�����ʦ");
		return;
	}else if(faith<=6000){
		who->set("title","����ɽ���Ƕ�����");
		return;
	}else who->set("title","����ɽ���Ƕ�Ԫ��");
	return;
}
