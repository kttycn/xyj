//edit by lucas

inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
���������������Ŀͷ����ľ�������û���κδ����
һ������������˯����
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"zoulang6",
        ]));
        set("sleep_room",1);

        setup();
}

