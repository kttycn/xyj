// Room: raceroom.c
inherit ROOM;
void create()
{
        set("short", "������ֳ�");
        set("long", @LONG
���������Ϸ�ǲ�˭�����ܵĹھ�...Ҫ�����ֳ��������Ҫ�г����...
������һλ�������е�С���...
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
//                __DIR__"npc/xrace" : 1,
        ]));
        set("exits", ([
                "up": __DIR__"mjroom",
                "down": __DIR__"diceroom",
            ]));
        set("light", 1);
        setup();
        replace_program(ROOM);
}

