#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "������"NOR);
        set("long",@LONG
����һ������Ρ�룬������Ĵ����������� "����
��" ���������پ����������Ȳ���������ǽ�Ϲ���
�����ֻ�������Χ��һȦ̴��ľ���Ρ�
LONG );
        set("exits", ([
            "south" : __DIR__"zhengting",
            "east"  : __DIR__"sleep1",
            "west"  : __DIR__"sleep",
            "north"  : __DIR__"zoulang"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

