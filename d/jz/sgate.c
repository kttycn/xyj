//Cracked by Roath
#include <ansi.h>
inherit ROOM;
void chen_appearing (object who, object where);

void create()
{
	set ("short", "����̨");
	set ("long", @LONG

��ǰ�����Ǵ�ٹ����ǵ������ֵĵط�������ݳ�˥���ˣ�
����ط�������û�˿����ˣ���ʹ������Ҳ������������̨
���Ա��и�С����(paizi)���������дЩʲô���ݡ�

LONG);
	set("exits", ([
		"north":__DIR__"dingan-3",
	]));
	set("objects", ([
		__DIR__"npc/waiter": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
������������������������������������������������������������������������
                    ���㣺���ÿ����������
������������������������������������������������������������������������
TEXT
	]) );
	set("outdoors", "jiangzhou");
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_cry", "yell");
}

int valid_leave(object me, string dir)
{
	if (dir == "north"&& me->query("fish") )
		me->delete("fish"); 
	return 1;
}
/*
void say()
{
        object me=this_player();
         write("����͵Ķ���˵������~~��Ҫ���ű��˵��㡣\n");
        return 0;
}
*/

int do_jump(string arg)
{
	object me=this_player();
	if( !arg || arg != "river")
	return notify_fail("��Ҫ��������\n");
	me->move(__DIR__"river");
	message_vision(HIC "$N����һ�����������С�\n" NOR, me);
	me->add("kee", -40);
	return 1;
}

int do_cry()
{
	object me = this_player();
	object where;


	if( me->query("obstacle/jz") == "done" )
		return notify_fail("��ɺ�����ɤ�ӣ�����Ҳ����������\n");

	if( ! me->query_temp("obstacle/jz_given") )
		return notify_fail("��ɺ�����ɤ�ӣ�����Ҳ����������\n");

	if( present("chen guangrui",environment(me) ))
		return notify_fail("�¹��ﲻ��������\n");

	if( random(20) == 6 )
	{       
		where = environment(me);
		message_vision(HIG"ֻ��$N�������������������ɥ������\n"NOR,me);
		tell_room(where,"��Ȼ�󺣷���������ˮ���ϸ�����һ����....\n");
		me->delete_temp("obstacle/jz_given");
		call_out ("chen_appearing", 1, me, where);
		return 1;
	}
	message_vision(HIG"ֻ��$N����������������Ǻ������û���ں�$N��\n"NOR,me);
	me->start_busy();
	return 1;
}   

void chen_appearing (object who, object where)
{
	object chen = new (__DIR__"npc/chen");

	chen->move(where);
	chen->check (who);
	return ;
}
