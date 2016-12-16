#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","��Ĺ�Թ�");
	set("long", @LONG
��������ȫ��·,ȴ����ȫû��·������Ϊ�㲻֪���������Թ�
ȥ��Ҳ��֪���������Գ�ȥ�������������˵���Ϣ�����������˸�ʬ
��ζ������������ֻ��һ���뷨���ߣ���
LONG
);

	set("exits", ([
	"east" : __DIR__"ro5",
	"west" : __DIR__"ro1",
	"south" : __DIR__"ro2",
	"north" : __DIR__"ro3",
	]));	
	setup();

}

void init()
{
	object coin;
	if(random(2)){
		coin = new ("/obj/money/coin");
		coin->set_amount(81);
		coin->move(__DIR__"ro4");
		this_player()->receive_damage("kee", 20);
		this_player()->receive_wound("kee",	10);
		message_vision(HIG "ͻȻ��������һ������һ��ͭǮ�����㼲��$N��\n" NOR, this_player());
	}else{
		message_vision(YEL "$NС����������˹�����\n" NOR,this_player());
	}
}

int valid_leave(object me, string dir)
{
	if ( dir == "south")
		me->add_temp("mark/steps",1);
	if ( dir == "north")
		me->add_temp("mark/steps",-1);

	if (me->query_temp("mark/steps") == (int)this_player()->query("age")/2)
	{
	 		me->move(__DIR__"yongdao1");
		me->delete_temp("mark/steps");
	return notify_fail( MAG "�����˰��죬��������˺ۣ�����߳��˹�Ĺ�Թ���\n" NOR);
	}	

	 if (me->query_temp("mark/steps") == -(int)this_player()->query("age")/2)
		{	
	me->move(__DIR__"yongdao");
		me->delete_temp("mark/steps");
	return notify_fail( HIW "�����˰��죬��������˺ۣ�����߳��˹�Ĺ�Թ���\n" NOR );
	 	}

	return ::valid_leave(me,dir);
}
