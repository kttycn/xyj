
// Room: /shulin/lin1.c
inherit ROOM;
void create()
{
        set("short", "·��");
        set("long", @LONG
������ǹ�ս����ַ������ˣ���˵����й����û��û��һ�������Ǳ�ȥ�ĺá�
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "south" : __DIR__"mi2",
                "north" : __FILE__,
                "southwest"      : "/d/changan/nanyue",

        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

