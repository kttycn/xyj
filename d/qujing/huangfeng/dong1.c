// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dong1.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

洞内光线昏暗，且有阵阵腥臭扑鼻。妖狐狡兔在你身边蹿
来跳去。往北通向洞的深处，南边是出洞的洞口。

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
	||ob->query_temp("apply/name")[0] != "[31m花脚蚊子[m")
	&& userp(ob) && !ob->query("obstacle/huangfeng") )
//&& !wizardp(ob) )
	{
		message_vision(HIY"忽然黄风怪大喊一声：怎么没见过这个人！\n"NOR,ob);
		message_vision(HIY"只见黄风怪大嘴一鼓，吹起了三昧神风。\n"NOR,ob);
		message_vision(HIY"只见$N如狂风中的风沙一样飞上了天空。\n"NOR,ob);
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
