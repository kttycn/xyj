#include <ansi.h>

inherit ROOM;

void init();
void reset_path(object);
int check_out(object);

void create ()
{
	set ("short", "[1;32m�����ſ�");
	set ("long", @LONG

���Ѿ������ƳγεĽ��ӣ��׻��������ӣ���â�����ҹ���飬
��Ө��͸����ʯ���������������觡�������ǰ�棬û��Զ�ˣ���
�����ֿɼ��������ܲ����ˣ����ɵļӿ��˽Ų���

LONG);
	set("exits", 
	([
	"north" : __DIR__"maze5",
	"south" : __DIR__"maze3",
	"west" : __DIR__"maze7",
	"east" : __DIR__"maze7",
	"northwest" : __DIR__"maze1",
	]));
	
	set("objects", 
	([

	]));

	setup();
}

void init()
{	
	object me=this_player();

	add_action("do_hujiu", "hujiu");

	if( me->query_temp("xmaze6") == 0 )
	{
	me->set_temp("xmaze6", 1);
	}
	else if( me->query_temp("xmaze6") == 1 )
	{
	reset_path(me);
	}
	
	if( check_out(me) ) me->move(__DIR__"baozang0");
}

void reset_path(object me)
{
	me = this_player();

	if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
	if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
	if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
	if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
	if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
	if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
	if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
	if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
	if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
	if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
	if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
	if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
	return;
}

int check_out(object me)
{
	me = this_player();

	if ( me->query_temp("xmaze1") != 1 ) return 0;
	if ( me->query_temp("xmaze2") != 1 ) return 0;
	if ( me->query_temp("xmaze3") != 1 ) return 0;
	if ( me->query_temp("xmaze4") != 1 ) return 0;
	if ( me->query_temp("xmaze5") != 1 ) return 0;
	if ( me->query_temp("xmaze6") != 1 ) return 0;
	if ( me->query_temp("xmaze7") != 1 ) return 0;
	if ( me->query_temp("xmaze8") != 1 ) return 0;
	if ( me->query_temp("xmaze9") != 1 ) return 0;
	if ( me->query_temp("xmaze10") != 1 ) return 0;
	if ( me->query_temp("xmaze11") != 1 ) return 0;
	if ( me->query_temp("xmaze12") != 1 ) return 0;
	if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
	if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
	if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
	if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
	if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
	if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
	if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
	if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
	if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
	if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
	if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
	if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
	return 1;
}
int do_hujiu(string arg)
{
	if( (!arg) || !((arg == "�������") || (arg == "jinfox help me!")))
	return notify_fail( HIW "�������ɤ�ӣ�����ʲôҲû�з�����\n" NOR );
	else
	{
		message_vision( HIB "�����֪���Ķ�ð�˳���,����$N���־�����!\n" NOR ,this_player());
		this_player()->move("/d/qujing/xuanyuan/yongdao2");
		tell_object(this_player(), HIB "����������������ͳ����Թ���\n" NOR );
	}
	return 1;
}
