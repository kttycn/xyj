inherit ROOM;

void create()
{
        set("short", "酒店二楼");
        set("long", @LONG
你正走在酒店二楼的走廊上，可以听到从客房里不时地呼呼
的打酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出
LONG );
        set("exits", ([
                "down"  : __DIR__"sleep-room",
                "1" : __DIR__"kefang1",
                "2" : __DIR__"kefang2",
                "3" : __DIR__"kefang4",
                "4" : __DIR__"kefang3",
        ]));

//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


