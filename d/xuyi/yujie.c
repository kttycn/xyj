// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "御街");
  set ("long", @LONG

这里就是蠙城皇宫前的御街，北面宫门上的匾额写着“圣义宫”三个金字。
大道两边遍植松柏，满目苍翠。
LONG);

  set("exits", ([
        "north"   : __DIR__"gongmen",
        "south"  : __DIR__"center",
      ]));
  set("objects", ([

      ]));
  set("outdoors", __DIR__);

  setup();
}

