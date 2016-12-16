#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "瀚海书屋");
        set("long",@LONG
屋中一架檀香木搭成的书架倚墙而立，书架上摆满了经史典籍。屋
子正中央是一张书桌，桌上笔墨纸砚一应俱全，墙上挂着一
幅条幅(tiaofu)。大名鼎鼎的宗主常在这里博览群书。
LONG );
     set("objects", ([
           __DIR__"obj/book1": 1,
           __DIR__"npc/yanbixue": 1,
        ]));
     set("exits", ([
            "north": __DIR__"zhengting",
        ]));

        set("item_desc",([
                          "tiaofu" : HIR "
              踏雪御风笑看江湖，
              覆雨翻云雄霸天下。 \n\n\n "NOR,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

