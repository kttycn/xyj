//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","̨��");
  set ("long", @LONG

����ʯ�̳ɵ�̨�ף�ʪ������̨�����泤����޺̦����С�ĵ�
���ţ�����һ��С�Ļ�����
LONG);

  set("outdoors", "shushan");
  set("exits", ([ 
       "down" : __DIR__"houshan4",
         "up" : __DIR__"houshan6",
 ]));

  setup();
}






