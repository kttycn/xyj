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
                "west" : __DIR__"zoulang2",
                "north" : __DIR__"zoulang6",
        ]));

        setup();
}

