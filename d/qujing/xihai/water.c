//water.c
//edit bye lucas
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ˮĻ");
        set("long",@LONG
������һ��ƬˮĻ֮�С���ˮĻ��������ˮ���ɣ����ֵĵ�ˮ��©��
�������������ﲨ��֮�£�ֻ��ˮ�����֣�ʱ��������߮��ʱ��Ծ
�����죬Ħ����һ��ȺϺ��з�����Ʋ�����������ǰ����
LONG );
        set("no_clean_up", 0);
        set("exits", ([
        ]));
        set("objects", ([
             __DIR__"npc/xiabing" : 2,
             __DIR__"npc/xiejiang" : 2,
        ]));

        setup();
}

