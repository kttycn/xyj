// Room: /shulin/lin7.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"mi6",
                "south" : __DIR__"mi8",
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __FILE__,
        ]));   set("objects", ([
             __DIR__"npc/kulou" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

