inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG  
�����Ǳ����������䳡��Ҫ�������£���Ҫ��������ȡ
���������������������䣬�����������������ǧ����
ѡ�ľ���������
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"obj/rack":1,
                __DIR__"npc/xiabing":1,
                __DIR__"npc/xiejiang":1,
        ]));
        setup();
}

