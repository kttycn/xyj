//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/update/stone/d/mishi.c

inherit ROOM;

void create ()
{
  set ("short", "藏珍阁");
  set ("long", @LONG

这是一间很隐蔽的房子，里面放的都是些大柜子，居然里面全部都是
古书，真是浩瀚书海，四壁书架，石头巫师居然还有此爱好。
LONG);

  set("exits", ([
         "north": "/d/update/stone/d/bookroom",
       ]));
  set("objects", ([
//        __DIR__"npc/monk_gm":1,
//         "/d/update/stone/obj/huanyang" : 1,
        ]));
  setup();
}
