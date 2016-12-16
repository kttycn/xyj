// changan wusheng
// xuanya3.c

inherit ROOM;
#include <room.h>

string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", "ʥ�������");
  set ("long", @LONG

ʥ����·�������������Ǻ�ȥ����ǰ��һ��ɽ������������
�����ƣ����к�⡣�±��϶�����̦��𣬿���ȥ�쳣�Ļ��֡�
�������������󣬿�ɽ����������
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huoyunwai",
  "down" : __DIR__"xuanya2",
]));
	set("outdoors", "wusheng");
  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();
	

	if( !arg || (arg != "left" && arg != "right" && arg != "up" ) ){
		return notify_fail("��Ҫ��������ȥ��\n");
	}

	if( arg == "left" ) 
	{
		message_vision("$N�����ұڣ���ץʯ�����"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move("/d/guzhanchang/wangxianya");
	}
	
	else if( arg == "right" ) 
	{
		message_vision("$N�����ұڣ���ץʯ�����"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move("/d/guzhanchang/baiyunya");
	}

	else return notify_fail( "��"+direction_name(arg)+"�Ѿ�û������֮���ˡ�\n" );

	message_vision("$N��"+direction_rev(arg)+"�����˹���������������һ������\n", me);   
	return 1;    
  
}

string direction_name(string arg)
{
	if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else if ( arg == "up" ) return "��";
	else return "��֪���Ķ�";
}

string direction_rev(string arg)
{
	if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else if ( arg == "up" ) return "��";
	else return "��֪���Ķ�";
}