inherit ROOM;

void create()
{
        set("short", "���Ӿ�");
        set("long", @LONG
����������������̫��Ħ���ľ�����Ħ�����Ժ��䣬����Ҳ����
�˸���������ǽ�ϱ�ǰ����������������߽����ֻ�����캮
�⣬���Ʊ��ˣ�һ����������������������ֲ棬�������о�
���������粨�淨��
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));
         set("objects", ([
                __DIR__"npc/taizi":1,
        ]));
        setup();
}

