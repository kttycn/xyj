// Room: /shulin/lin6.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "east" : __DIR__"mi5",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __DIR__"mi7",
                "northwest" : __FILE__,
        ]));
          set("objects", ([
             __DIR__"npc/kulou" : 1,
        ]));
 set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
 

