// �����硤���μ�֮�����ͣ�
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "���ŷ�");
  set ("long", @LONG

һ���˴���ֻ����ζ�˱ǡ������ǻʹ������ŷ������߶��ǽ������ɡ���
���и�����ʳ����˵���дӲ�˿���ڵĻ𼦡�
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

