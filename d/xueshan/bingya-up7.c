//standroom.c used by weiqi...others may hate this format:D
//bingya-up7.c
#include <ansi.h>
inherit ROOM;

string direction_name(string);
string direction_rev(string);

void create ()
{
	set ("short", "������");
	set ("long", @LONG

��ſ�ڱ����ϣ�������С������
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/jz/herb/xuelian" : 1,
		//__DIR__"npc/xunshi" : 1,
	]));

	set("outdoors", "xuesan");
	setup();
}

void init()
{
	add_action("do_read", "mianbi");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();

	if( !arg || (arg != "up" && arg != "down" && arg != "left" && arg != "right") )
	{
		return notify_fail("��Ҫ��������ȥ��\n");
	}

	if( arg == "up" ) 
	{
		message_vision("$N���㲢�ã�С���������"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move(__DIR__"binggukou");
	}
	else if( arg == "down" ) 
	{
		message_vision("$N���㲢�ã�С���������"+direction_name(arg)+"���˹�ȥ��\n", me);
		me->move(__DIR__"bingya-up6");
	} 
	else return notify_fail( "��"+direction_name(arg)+"�Ѿ�û������֮���ˡ�\n" );

	message_vision("$N��"+direction_rev(arg)+"�����˹��������������˿�����\n", me);   
	return 1;    
}

string direction_name(string arg)
{
	if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else return "��֪���Ķ�";
}

string direction_rev(string arg)
{
	if ( arg == "up" ) return "��";
	else if ( arg == "down" ) return "��";
	else if ( arg == "left" ) return "��";
	else if ( arg == "right" ) return "��";
	else return "��֪���Ķ�";
}

int do_read(string arg)
{
	object me=this_player();

	if(me->is_busy() )
		return notify_fail("������æ���أ����й����������...\n");

	if((int)me->query_skill("ningxue-force",1)<100 )
	{
		if(me->query_temp("xueshan_ice") >= 10)
		{
			tell_object(me,BLU"�㱻�����촽���෢����\n"NOR);
			me->delete_temp("xueshan_ice");
			me->unconcious();
			return 1;
		}
		if(me->query_temp("xueshan_ice") == 5)
			tell_object(me,HIB"�㱻����ʵ���ܲ����ˣ����ǸϿ������һ�°ɡ�\n"NOR);
		else tell_object(me,HIB"�㶳���촽���࣬����΢΢���������������������\n"NOR);
		me->add_temp("xueshan_ice", 1);
		return 1;
	}

	if(me->query("family/family_name") != "��ѩɽ")
	{
		tell_object(me,"�㲻�Ǵ�ѩɽ�ģ�����Ϲ����ʲô��\n"); 
		return 1;
	}
	if(me->query("sen") < 100)
	{
		tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
		return 1;
	}
	message_vision("$N��ϥ������������ʼ��ڡ�����\n", me);
	me->add("sen",-50);
	me->start_busy(2);
	if(me->query("xueshan/yushijufen_perform")) 
	{
		tell_object(me,"���ƺ�������������ʲô�ˡ�\n");       
		return 1;
	}
	if((int)me->query_skill("bingpo-blade", 1) > 149){
		tell_object(me,HIW"��о�����һ��ı�ʹ������Ϯ����\n"NOR);
		me->improve_skill("ningxue-force", 50+random(10));
		me->add("xueshan/bingpo",1);
		me->start_busy(2);
	}
	if(me->query("xueshan/bingpo",1) > 500)
	{
		me->set("xueshan/yushijufen_perform",1);
		tell_object(me,HIR"\n��ͦ��վ����������Цһ����˵����"HIY"�Ӵ����º��˵��֣�"HIR" ��ʱ���������"HIW"����ʯ��١�"HIR"��\n"NOR);
		me->delete("xueshan/bingpo");
	}
	return 1;
}


