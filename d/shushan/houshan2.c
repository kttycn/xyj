//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","С·");
  set ("long", @LONG

�������ɽ�ɵĽ���£�ԶԶ��ȥ�������֡�������
�ǲ��Ǵ�˵�е��������������
LONG);

  set("outdoors", "shushan");
  set("exits", ([ /* sizeof() == 1 */
      "southdown" : __DIR__"houshan1",
               "up" :  __DIR__"houshan3",
    ]));

  setup();
}






