// salehut.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","�䱦ի");
        set("long", @LONG

�������������ɫ���㡣�������ź����ֹ���ϸ��ë̺����
�ھ����������ֻ����������������������ľ�����ϰڷ����ķ�
�ı�����һ����������һ����ɫ��쵵Ķ���̴���������ƣ�ϸ��
���ƣ�������Ƣ����������ζ���˻�����ˬ��

LONG);

        set("exits", ([		
                "north" : "/d/wiz/entrance",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1); 

  set("objects", ([ /* sizeof() == 1 */
    "/d/wiz/npc/paimaishi" : 1,
]));
        setup();
}

