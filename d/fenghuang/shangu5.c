inherit ROOM;
#include <ansi.h>
void create()
{
               set("short",HIB"�������"NOR);
               set("long",@LONG
    �����������ȵ������ˣ����ܶ��������������㿴����������·��
����������������Ϲ���ţ���ʱ�������һЩ���˿־�Ĺ���������
��С��Ϊ�
LONG);

               set("exits",([
                  "north" : __DIR__"shangu5",
                  "northwest" : __DIR__"shangu4",
                  "southwest" : __DIR__"shangu6",
                  "south" : __DIR__"shangu5",
                  "west" : __DIR__"shangu5",
                  "east" : __DIR__"shangu5",
                  "northeast" : __DIR__"shangu5",
                  "southeast" : __DIR__"shangu5",
                  ]));
            set("objects",([
            __DIR__"npc/juniao" : 4,
                             ]));
   setup();
}
