#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","ƫ��");
        set("long",@LONG
����������������ƫ�����������ź�ɫ�ĵ�̺������վ��
����������Ů���ӣ���Цӯӯ�Ŀ����㡣�
LONG);
        set("objects", ([
           __DIR__"npc/shinv": 4,
        ]));
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang5",
            "west"  : __DIR__"zhengting",
        ]));
        setup();
        replace_program(ROOM);
}

