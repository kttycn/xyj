// EDIT BY LUCAS
inherit ROOM;


void create()
{
        set("short", "����");
        set("long", @LONG
���������������ң������ܲ�͸�磬����С����Ҳû�С�����
ճ����һ������С���ݣ���̦���ݣ������ܾ�û�������ˣ�һ
�����˱�һ���ֱ۴ֵ������������ùǣ����������������
�ںް���֮�顣
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "out" : __DIR__"zhongtang",
        ]));
         set("objects", ([
                __DIR__"npc/heshen":1,
        ]));
        setup();
}

