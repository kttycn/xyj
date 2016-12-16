#include <ansi.h>
#include <mudlib.h>
inherit NPC;
string ask_me();

void create()
{
	set_name(MAG"��Ӱʹ��"NOR, ({ "xiake shizhe", "shizhe" }) );
	set("nickname", CYN"��֪���������"NOR);
	set("gender", "����" );
	set("age", 18);
	set("long", YEL"��λ�ǡ���Ӱ��Ե����ʹ�ߣ�������������Ӱ��Ե��������������벻���ľ�ϲ��\n"NOR);
	set("shen_type", 1);
	set("combat_exp", 1000000);
	set("str", 30);
	set("dex", 30);
	set("con", 30);
	set("int", 30);
	set("per", 30);
	set("attitude", "friendly");
	set("max_kee", 100000);
	set("force", 100000);
	set("max_force", 100000);
	set("score", 100000);

	set("inquiry", ([
		"��Ӱ��Ե" : (: ask_me :)
	]));
	setup();
}

void init()
{
	object ob;
	ob = this_player();     
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("whisper " + ob->query("id") + " "HIW"��ӭ���١���Ӱ��Ե��"+HIR+"(ask shizhe about ��Ӱ��Ե)\n"+NOR+HIW+"С���������߽�����"NOR);
}

string ask_me()
{
	object me = this_player();
//	mapping fam; 

	if ((int) me->query("welcomexhc"))
		return "�Ǻǡ���������Ĳ����ˣ�С���Ѿ�����ʩ�������ˣ�";
	else
	{
		me->set("welcomexhc", 1);
		me->add("food", 10000);
		me->add("water", 10000);
		CHANNEL_D->do_channel(me, "chat", sprintf("����%s���չ��١���Ӱ��Ե��"
		"\n�����������ѵõ���Ӱʹ�ߵİ�����������ʼ���߽����ˣ����λ�ɳ����������", me->name(1)));
		return "��ӭ����"NOR+HIR"����Ӱ��Ե��"NOR"��С�Ļ������٣�������������¿��������߽�����\n"
		HIW"ͻȻ�����һ��"HIM"��"HIY"��"HIR"ϼ"HIC"��"HIW"�����ķ���ת˲���ţ�"NOR;
	}
}

