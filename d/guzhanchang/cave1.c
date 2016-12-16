// Room: /d/qujing/wudidong/book_cave1
// created 9-15-97 pickle

/************************************************************/
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);

/************************************************************/
void create ()
{
        set("short", "路口");
        set("long", @LONG
        
这里就是古战场遗址的入口了，听说里边有怪物出没，没有一定
功夫还是别去的好。
LONG );

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lukouside1",
  "southeast" : __DIR__"lukou",
]));

  setup();
}

/************************************************************/
int valid_leave(object me, string dir)
{
    object guard, here=this_object();
//    object *inv, container;
//    int sizeinv;

    if (dir == "northwest")
	me->delete_temp("guzhanchang/gave_guard_corpse");
    if (dir != "southeast")
	return ::valid_leave(me, dir);
    if (dir == "southeast"
     && objectp(guard=present("shi gui", here)))
    {
	if (me->query("guzhanchang/last_entered_lukou") + 3600 > time())
	{
		message_vision(CYN"食尸鬼恶很很地骂道：你这个混帐！进进出出的有完没完？待会儿那个恶鬼王要是知道了，叫你吃不了兜着走！\n"NOR, me);
		return notify_fail("");
	}
/*	inv=all_inventory(me);
	sizeinv=sizeof(inv);
	while (sizeinv--)
	{
	    if (userp(inv[sizeinv]))
	    {
		container=inv[sizeinv];
		break;
	    }
	    if (inv[sizeinv]->is_container())
	    {
		container=inv[sizeinv];
		break;
	    }
	    continue;
	}
	if (container)
	{
	    message_vision(CYN"食尸鬼阴阴地说道：你带着那"+container->name()+
			   CYN"进去干什么！？被那绿毛老鼠看见了怎么办！？\n"NOR,me);
	    return notify_fail("");
	}*/
    }

    if (objectp(guard=present("shi gui", here)))
    {
	if (me->query_temp("guzhanchang/gave_guard_corpse"));
	{
	    message_vision(CYN"食尸鬼阴阴地说道：快点出来，要是给那恶鬼王发现了就热闹了！\n"NOR, me);
	    me->set("guzhanchang/last_entered_lukou", time());
	    return ::valid_leave(me, dir);
	}
	message_vision(CYN "食尸鬼奸笑道：什嘛？想跑？没门！\n"NOR, me);
	return notify_fail("");
    }

    message_vision("地面上现出一个人影，慢慢地钻了出来，挡住东南面的出口。\n", me);
    guard = new(__DIR__"npc/shigui");
    guard->move(here);
    return notify_fail("你不由停下了脚步......");

}
