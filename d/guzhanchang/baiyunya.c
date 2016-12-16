// stone 20020620
// /d/guzhanchang/baiyunya.c

inherit ROOM;
#include <room.h>
string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", "������");
  set ("long", @LONG

һ���Ķ��Сƽ̹�Ĵ���ʯ����ʱ��ƬƬ���ƴӽ���Ʈ��
��������ȥ��ֻ��ɽ��������һ�����ģ���һ��������
�﷽Բ�ڣ���Ϊͻ����
LONG);
  set("exits", ([ /* sizeof() == 3 */
]));
  set("objects", ([
        __DIR__"npc/xianhe":1,
]));
	set("outdoors", 1);
  setup();
}

void init() {
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();
	
	if( !arg || (arg != "left" && arg != "right" && arg != "up" && arg != "down" ) ){
		return notify_fail("��Ҫ��������ȥ��\n");
	}

	if( arg == "left" ) 
	{
		message_vision("$N�����ұڣ���ץʯ�����"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move("/d/wusheng/xuanya3");
	}

	else return notify_fail( "��"+direction_name(arg)+"�Ѿ�û������֮���ˡ�\n" );

	message_vision("$N��"+direction_rev(arg)+"�����˹���������������һ������\n", me);   
	return 1;    

}

string direction_name(string arg)
{
	if ( arg == "right" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else return "��֪���Ķ�";
}

string direction_rev(string arg)
{
	if ( arg == "right" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else return "��֪���Ķ�";
}