//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","��ɽ·");
  set ("long", @LONG

������ͨ����ɽ�ɺ�ɽ��ɽ·�������·ƽ̹,�����ǳ���������
�Ա��ǿ������׵����£���С����������š�
LONG);

  set("outdoors", "shushan");
  set("exits", ([ /* sizeof() == 1 */
      "southwest" : __DIR__"houshan0",
        "northup" : __DIR__"houshan2",

 ]));

  setup();
}






