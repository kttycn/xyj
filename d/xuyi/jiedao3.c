// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

一条整洁的碎石路面，往西是水母娘娘府邸的宫门，远远望去虹光闪烁。
卖小东西的商贩也常常主动送到娘娘府上，在这里常常可以看到水母娘娘
的几个小丫鬟在这里嬉戏。
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao2",
        "west"   : __DIR__"door",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}
 

