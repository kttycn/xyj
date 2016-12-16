#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "龙凤厅"NOR);
        set("long",@LONG
这是一座气势巍峨，构造宏大的大厅堂厅门上 "龙凤
厅" 三个大字遒劲有力，气度不凡。厅中墙上挂满
名人字画，四周围着一圈檀香木大椅。
LONG );
        set("exits", ([
            "south" : __DIR__"zhengting",
            "east"  : __DIR__"sleep1",
            "west"  : __DIR__"sleep",
            "north"  : __DIR__"zoulang"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

