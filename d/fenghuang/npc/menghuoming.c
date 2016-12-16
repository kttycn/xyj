#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);
string ask_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
	set_name("�ϻ���", ({ "meng huoming", "meng" }));
	set("nickname", HIR "�һ��ʨ" NOR);
	set("age", 30);
	set("title", HIR "�һ𽫾�" NOR);
	set("gender", "����");
	set("long", "����ɫ��죬�෢���죬���������״����ӣ����������ƣ��ʵ�
���һ𽫾���\n");

	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "����");
	set("per", 20);
	set("str", 40);
	set("int", 25);
	set("con", 30);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 80);
	set("daoxing", 3000000);
	set("combat_exp", 800000);
	set("score", -5000);

	set_skill("stick", 140);
	set_skill("literate", 100);
	set_skill("unarmed",90);
	set_skill("dodge", 120);
	set_skill("parry", 110);
	set_skill("force", 120);
	set_skill("spells", 100);
	set_skill("yufeng-shu", 100);
	set_skill("tenglong-finger",90);
	set_skill("wuzu-xinfa", 110);
	set_skill("fenghuang-shenfa", 110);
	set_skill("liedi-stick",140);
	map_skill("unarmed","tenglong-finger");
	map_skill("parry", "jile-dao");
	map_skill("spells", "yufeng-shu");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");
	map_skill("stick","liedi-stick");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("�����",3,"��");
	set("inquiry", ([
		"����": (: expell_me :),
		"leave": (: expell_me :),
		"����" : (: ask_me :),
		"���": (: ask_mieyao :),
		"cancel": (: ask_cancel :),
	]));
	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "�����")
	{
		message_vision("�ϻ�������$N���ͷ��΢΢Ц��Ц��\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	ob = this_player();
	if (!(int)this_player()->query("bmark/��ҵ��"))
		command("say �㻹��ȥ��˾�Уȥ����һ�°ɡ�\n");
	else
	{
		command("say �ðɣ��������㡣\n");
		command("recruit "+ob->query("id"));
		return;
	}
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIC"��˳ǹ�������У"NOR);
	}
	return 0;
}

string ask_me()
{
	object me;
	int i;
	me=this_player();
	if (me->query("family/family_name")!="�����")
		return "�㲻�Ƿ����սʿ���������ﵷ�ң�\n";
	if (me->query_temp("digdong1")==1 || me->query_temp("digdong2")==1
	|| me->query_temp("digdong3")==1 || me->query_temp("digdong4")==1
	|| me->query_temp("digdong5")==1 || me->query_temp("digdong6")==1)
		return "���Ѿ������������ˣ�\n";
	if (me->query("combat_exp")>500000)
		return "���Ѿ�����Ҫͨ��ɱ�����������Լ�����ѧ�ˡ�\n";
	i=random(5)+1;
	if (i==1)
	{
		me->set_temp("digdong1",1);
		tell_object(me,"��˵һ���Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	if (i==2)
	{
		me->set_temp("digdong2",1);
		tell_object(me,"��˵�����Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	if (i==3)
	{
		me->set_temp("digdong3",1);
		tell_object(me,"��˵�����Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	if (i==4)
	{
		me->set_temp("digdong4",1);
		tell_object(me,"��˵�ĺ��Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	if (i==5)
	{
		me->set_temp("digdong5",1);
		tell_object(me,"��˵����Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	if (i==6)
	{
		me->set_temp("digdong6",1);
		tell_object(me,"��˵�����Ҷ��й��޳�û����ȥ�鿴һ�£�\n");
	}
	return "��ȥ��أ�\n";
}

string expell_me(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="�����") {
		command("say �����ִ���뿪��������Ҳ�����㣬�����Ժ�ɲ�Ҫ�������顣");
		me->set_temp("betray", 1);
		command("say ��Ҫ�뿪������ү��Ҫ���µ㶫�����������Ŷ��");
		return ("���Ը��(agree)��");
	}
	return ("��������ʲô�֡�");
}

void init()
{
	::init();
	add_action("do_agree", "agree");
}

int do_agree(string arg)
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		this_player()->add("betray/count", 1);
		this_player()->add("betray/phoenix", 1);
		command("say ��Ȼ�㲻�����������ɣ��Ǿ��߰ɣ�");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*90/100);
		if(this_player()->query_skill("yufeng-shu"))
			this_player()->delete_skill("yufeng-shu");
		if(this_player()->query_skill("tenglong-finger"))
			this_player()->delete_skill("tenglong-finger");
		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete("faith");
		this_player()->delete("family_wp");
		this_player()->set("title", "��ͨ����");
		this_player()->set_temp("betray",0);
		if( (int)this_player()->query("score") < 1000 )
			this_player()->set("score", 0);
		else
			this_player()->add("score", -1000 );
		this_player()->save();
		command("pat");
		command("say ������ô������������չ����¡���\n");
		return 1;
	}
	return 0;
}

//string ask_cancel()
//{
//	object me=this_player();
//	if("/d/obj/yao/mieyao"->delete_mieyao(me))
//		me->add("faith",-5);
//	return ("û�õĶ�����");
//}
string ask_cancel()
{
	object me=this_player();
	return "/d/obj/yao/mieyao"->delete_mieyao(me);
}

string ask_mieyao(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="�����") {
		if(me->query("faith")<100)
			return ("�㻹���ȶ������Ϊ�");
		tell_room(environment(me),"�ϻ�����ĿԶ��ǰ����\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"��������,����ɨ������Ϊ���Ρ�\n"NOR;
	}
	return ("�����������ס�");
}
