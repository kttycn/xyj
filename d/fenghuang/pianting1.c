#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","偏厅");
        set("long",@LONG
这这里是宗主府的偏厅，地上铺着红色的地毯，两边站着
几个美丽的女孩子，正笑盈盈的看着你。�
LONG);
        set("objects", ([
           __DIR__"npc/shinv": 4,
        ]));
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang5",
            "west"  : __DIR__"zhengting",
        ]));
        setup();
        replace_program(ROOM);
}

