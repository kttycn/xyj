inherit ROOM;

void create()
{
        set("short", "ˮ��������");
        set("long", @LONG
����������������������������䲻�綫�����������ûʣ�
ȴҲ��ׯ��ΰ���ı�����������������ȫ��ˮ������������
�������䣬����ɺ����������ɫ���飬������ʣ�����ʤ�ա�
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "out" : __DIR__"yanwu", 
                "west" : __DIR__"zoulang1",
                "east" : __DIR__"zoulang2",
        ]));
        set("objects", ([
      "/d/qujing/xihai/npc/aoshun":1,
        ]));


        setup();
}

