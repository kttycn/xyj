// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "御膳房");
  set ("long", @LONG

一进此处，只闻香味扑鼻。这里是皇宫的御膳房，厨具都是金银做成。里
面有各种美食，据说还有从波丝进口的火鸡。
LONG);

  set("exits", ([
        "east"  : __DIR__"hualang",
      ]));

  set("objects", ([
  "/d/obj/food/xiangcha" : 1,
  "/d/obj/food/turkey" : 3,
  __DIR__"npc/yuchu" : 1,
       ]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));


//  set("outdoors", __DIR__);

  setup();
}

