inherit ROOM;

void create()
{
        set("short", "�Ƶ��¥");
        set("long", @LONG
�������ھƵ��¥�������ϣ����������ӿͷ��ﲻʱ�غ���
�Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�������
LONG );
        set("exits", ([
                "down"  : __DIR__"sleep-room",
                "1" : __DIR__"kefang1",
                "2" : __DIR__"kefang2",
                "3" : __DIR__"kefang4",
                "4" : __DIR__"kefang3",
        ]));

//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


