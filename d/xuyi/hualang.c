// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "花廊");
  set ("long", @LONG

这里就是蠙城皇宫的花廊，走廊下到处是奇花异草，往北是正殿，往南是
御花园，往西是御膳房，往东是偏殿。
LONG);

  set("exits", ([
        "north"   : __DIR__"zhengdian",
        "south"  : __DIR__"yuhuayuan",
        "west" : __DIR__"chufang",
        "east" : __DIR__"piandian",
      ]));
  set("objects", ([

      ]));
//  set("outdoors", __DIR__);

  setup();
}

