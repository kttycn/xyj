inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "地下岩洞入口");
        set("long", @LONG
这里就是凤凰星的地下岩洞入口，里面就是凤凰
星的地下岩洞了，如果你运气好可以帮军校杀些
怪兽来增加自己的战斗力。
LONG
        );
        set("exits", ([
                "down"     : __DIR__"yandong1",
                "west"     : __DIR__"eshangjie2"
        ]));
        setup();
        
}

