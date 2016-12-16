//Cracked by Roath
//anshi.c
#include <room.h>
inherit ROOM;

int can_enter=1;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

���ǻ�԰���µ�һ�䰵�ҡ��ڹ����˵�ʲôҲ�����塣������
����������(mo)�� 
LONG);

	set("no_clean_up", 1);
	can_enter=1;

	setup();
}


void init()
{
	add_action("do_mo", "mo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate", 151200+random(1080) );//45Сʱ
	}
}

void generate()
{
	remove_call_out("generate");
	set("available", 1);
}

void reset_enter()
{
	can_enter=1;
}

int do_mo(string arg)
{
	object me, guo;
	int sen;

	me = this_player();
	notify_fail("��ʲôҲû���š�\n");
	
	if(me->is_busy()) return 0;


	sen=me->query("sen");
	if(sen<110) return 0;
	sen-=100;
	me->set("sen",sen);

	sen=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(sen<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		if(random(2))
			guo = new(__DIR__"obj/huolonggan");
		else
			guo = new(__DIR__"obj/xiandan");
		guo -> move(this_object());
		message_vision("ֻ����ͨ����һ����������ʲô�������ڵ��ϡ�\n", me);

		remove_call_out("generate");
		call_out("generate", 151200+random(1080) );

		return 1;
	}
	return 0;
}

int clean_up()
{
	return 0;
}
