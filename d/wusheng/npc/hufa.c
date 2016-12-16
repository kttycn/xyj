// hufa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name(HIW"��������"NOR, ({"hufa zunzhe", "zunzhe"}));
	set("long", "��ʥ���������ߣ����ɴ�С����������֪����\n");
	set("title", HIC"�����"NOR);
	set("gender", "����");
	set("age", 1000);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("looking", "Ӣ�������������ٷ磬�������Ρ�");
	set("max_kee", 1000);
	set("max_gin", 100);
	set("max_sen", 1000);
	set("force", 1000);
	set("max_force", 500);
	set("force_factor", 10);
	set("max_mana", 500);
	set("mana", 1000);
	set("mana_factor", 10);
	set("combat_exp", 1000000);
	set("daoxing", 1100000);

	set_skill("unarmed", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
	set_skill("spells", 130);
	set_skill("feisheng-spells", 130);
	set_skill("literate", 80);
	set_skill("sword", 130);
	set_skill("wuying-sword", 130);
	set_skill("fumobashi", 130);
	set_skill("mizong-steps", 130);
	set_skill("dodge", 130);
	set_skill("force", 130);
	set_skill("xiantian-force", 130);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");

	set("inquiry", ([
		"����" : (: expell_me :),
		"leave" : (: expell_me :),
		"cancel": (: ask_cancel :),
		"��ħ": (: ask_mieyao :),
	]) );

	create_family("��ʥ��", 1, "����");

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��ʥ��") {
		 message_vision("�������ߺ��Ӷ���������ǳ�������\n", me);
		 me->set_temp("betray", 1);
		 message_vision("�������߶�$N�����ţ�С��������˵�������Ļ�(true)��\n", me);
		 return ("�������ˣ��������ˣ�\n");
	}
	return ("��ʲô�ʣ��Լ���ȥ��\n");
}
void init()
{
	add_action("do_true", "true");
}

int do_true(string arg)
{
	if(this_player()->query("family/family_name") != "��ʥ��" )
		return 0;
	if(this_player()->query_temp("betray")) {
		message_vision("$N��������ӽ������Ļ���\n\n", this_player());
		message_vision("��������̾�˿�����������ˣ������ɽ�ɣ�\n", this_player());
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("feisheng-spells") )
			this_player()->delete_skill("feisheng-spells");
		if( this_player()->query_skill("xiantian-force") )
			this_player()->delete_skill("xiantian-force");
		this_player()->add("betray/count", 1);
		this_player()->add("betray/wusheng", 1);
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray", 0);
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		message_vision("������������ֽ�$Nһ�ƣ�$N����һ�������򶫶�ȥ ... \n", this_player());
		this_player()->move("/d/city/center");
		tell_room( environment(this_player()),"������������¼����죬���¸�������\n", ({this_player()}));
		this_player()->unconcious();
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="��ʥ��") {
	if ((int)ob->query("daoxing") < 100000 ) {
  	command("say ���ǽ�ħ����֮�����صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�������ѿ����ۣ���������������������ˣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("feisheng-spells", 1) < 80 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���ҷ�������ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
	command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "wusheng");
}
string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("û�õĶ�����");
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="��ʥ��") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"�������߷�ĿԶ��ǰ����\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"������ħ��������ʥ������֮���֡�\n"NOR;
	}
	return ("�����߲����ס�");
}
