//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����ͤ");
  set ("long", @LONG 
��л���ɻ����죬���½�Ͼ��£��벻��������Ҳ�ɿ�����
�������ݼ��ޣ����߼������ٻ����������ڲ���ͤ�У���
��ˮ��Ҳ�п���˵��Ļ�������һ����ө�ɵ��裬���ﻨ
�㡣
LONG);

  set("water", 1);
  set("exits", ([ 
  "south" : __DIR__"dayuan",
])); 
        set("objects", ([
                __DIR__"npc/yaowang" : 1,
        ])); 
        setup();
} 

