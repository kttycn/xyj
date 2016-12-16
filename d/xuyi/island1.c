// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "南赡部洲海岸");
  set ("long", @LONG

这里就是南赡部洲的海岸，金色的沙滩在阳光下闪闪发光，白浪如雪，沿
着海岸，有很多奇形怪状的礁石，海潮一波一波地扑过来，在礁石上击得
粉碎，发出震耳欲聋的响声。海风呼啸着吹过，吹得人的衣衫猎猎作响。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"island",
]));

  setup();
}

void init()
{
        add_action("do_dive", "dive"); 
}


int do_dive()
{
       object me;
        me=this_player();
            if((!present("bishui zhou", me)) &&
       (!((string)me->query("family/family_name")=="东海龙宫")))
                return
notify_fail("你一个猛子扎到水里．．．\n\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");
                message_vision("$N一个猛子扎到水中，然后不见了．\n", me);
                me->move("/d/xuyi/sea");
     message_vision("$N游了过来。\n", me);
                return 1;
}


