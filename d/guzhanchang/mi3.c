// Room: /shulin/lin3.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "west" : __FILE__,
                "east" : __DIR__"mi2",
                "south" : __FILE__,
                "north" : __FILE__,
                "northeast" : __DIR__"mi4",
                "southeast" : __FILE__,
        ]));
         set("objects", ([
             __DIR__"npc/jiangshi" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

