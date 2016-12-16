// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong1.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������ͨ�򶴵�����ϱ��ǳ����Ķ��ڡ�

LONG);

  set("exits", ([
        "south" : __DIR__"dongkou",
	"north" : __DIR__"dong3",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 2,
  ]));
 
  setup();
}

int valid_leave (object who, string dir)
{
	if (! interactive(who) &&
	dir == "south")
		return 0;
	return ::valid_leave(who,dir);
}

void init()
{
	object obj;
	object ob = this_player();
	
	if ( !ob->query_temp("winded") && (! ob->query_temp("apply/name") 
	||ob->query_temp("apply/name")[0] != "[31m��������[m")
	&& userp(ob) && !ob->query("obstacle/huangfeng") )
//&& !wizardp(ob) )
	{
		message_vision(HIY"��Ȼ�Ʒ�ִ�һ������ôû��������ˣ�\n"NOR,ob);
		message_vision(HIY"ֻ���Ʒ�ִ���һ�ģ�������������硣\n"NOR,ob);
		message_vision(HIY"ֻ��$N�����еķ�ɳһ����������ա�\n"NOR,ob);
		ob->apply_condition("eyeill",50);
		ob->unconcious();
		ob->set_temp("winded",1);
		if( ob->query_temp("lingji1_done") == "yes" )
		{
			ob->move("/d/qujing/huangfeng/huangfeng5");
			return;
		}
		ob->move("/d/qujing/huangfeng/huangfeng5new");
	}
	return;
}
