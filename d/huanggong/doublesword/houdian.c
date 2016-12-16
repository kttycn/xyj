// by snowcat
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "后殿");
  set ("long", @LONG


此地庄严肃穆，墙上绘有金龙戏珠，殿顶上画着紫色祥云，瑞气朦胧。
你四下里探望，突然发现东墙角(east wall)上似乎有些问题。


LONG);
  set("exits", ([ 
    "south" : "/d/huanggong/dadian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("item_desc", ([
                "east wall": "你接着探望，东墙上绘有金龙戏珠，下面却似乎有一个按纽(button)。
你心中不由一动。                \n",
                "button": "你磨试了按纽(button)，发现似乎可以旋转(turn)。\n",
       	]));
  
  
  
  setup();
}

void init()


{
        add_action("do_turn","turn");
 }

int do_turn(string arg)
{
        object me = this_player();

        if( !arg || arg != "button" )
                return notify_fail("你要旋转什么？\n");

        if( !(me->query_temp("ask_ziying") == "laojun2"))
                return notify_fail("你试着把按纽转了又转，但按纽纹丝不动。\n");

//        set("exits/south", "/d/update/stone/d/mishi");
        message_vision(HIC"$N轻轻地把按纽转了几转，只听喀嚓一声! 一道暗门翻出，$N大叫一声，落了下去。\n"NOR,me);
        me->move(__DIR__"anshi");
        message("vision", "一阵冷风吹过，暗室中突然多了一个人。\n", me);
//        remove_call_out("close");
//        call_out("close", 3, me);
        return 1;
}
/*void close()
{
	object room = load_object("/d/update/stone/d/mishi");
        message("vision","忽然墙自动的合拢了。\n", room);
        room->delete("exits/south");
}*/