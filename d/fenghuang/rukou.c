inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�����Ҷ����");
        set("long", @LONG
������Ƿ���ǵĵ����Ҷ���ڣ�������Ƿ��
�ǵĵ����Ҷ��ˣ�����������ÿ��԰��УɱЩ
�����������Լ���ս������
LONG
        );
        set("exits", ([
                "down"     : __DIR__"yandong1",
                "west"     : __DIR__"eshangjie2"
        ]));
        setup();
        
}

