inherit ROOM;

void create()
{
        set("short", "������ֳ�");
        set("long", @LONG
�����������Ӳ´�С�ķ���..Ҫ�����ֳ��������Ҫ�г����...
������һλ�������е�С���...
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/xdice" : 1,
        ]));

        set("exits", ([
                "up": __DIR__"raceroom",
                "down": __DIR__"playroom",
            ]));

        set("light", 1);
        setup();
        replace_program(ROOM);
}

