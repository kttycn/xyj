inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG  
�������������������ĵط����˴��Ĵ������˵�ǹ��ꫣ�
�����������õ��������ڶ������������֪��ʲô���⡣
�������վ�տ���Ƿ˳֮�����������ġ�
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"npc/yuren":3,
        ]));
        setup();
}

