//edit by lucas

inherit ROOM;

#include <ansi.h>;

void create()
{
        set("short", "����");
        set("long", 
"���������������Ĵ��ţ���һ���麺�����ɡ�׺��������ɫ��
ʯ���������������ž��Ѿ���ֵ���ǡ����ԡ��γ������ޱ�������
�����ۡ�������վ�ż����������ݵ���ʿ�������ǲ����������˽�
ȥ�ġ������Ժ챦ʯ��Ƕ�����ĸ����֡�"HIR"

                          ��������
\n"NOR);
  set("water", 1);
        set("exits", ([
                "south"  : __DIR__"haidi5",
                "northup"  : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"npc/huwei" : 3,
        ]));
        setup();
} 

