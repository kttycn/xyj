// Room: /shulin/lin4.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "east" : __FILE__,
                "south" : __DIR__"mi5",
                "west" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __DIR__"mi3",
        ]));
                set("objects", ([
             __DIR__"npc/jiangshi" : 1,
        ]));
 set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

