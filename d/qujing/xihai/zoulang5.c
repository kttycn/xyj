inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������������ȣ����������������ɷ���ɷǷ���������
�İ�����һ���������Ϻ��Ϻ�ţ��������ڴ��������֡�
�컨���������ϸ�ƣ��̻��ŵ�����������ƽ�������ķṦ
ΰ���� 
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"tzroom",
                "south" : __DIR__"zoulang3",
                "west" : __DIR__"cook",
        ]));

        setup();
}

