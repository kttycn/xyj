//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","��ɽ���칬");
  set ("long", @LONG

��ɽ���칬����ɽ���ɿ�ɽ��ʦ�������������ĵط�,
����ɽ�������ܵط���һ����ɽ�ɵ��ӣ�û�кܺ�����
�����ǲ�֪�������,������ɽ��ʥ��ͽ�ؼ�Ϊ�ϸ�
LONG);

  set("exits", ([
   "west" : __DIR__"sleeproom",
   "south" : __DIR__"midao",
  ]));
  set("objects", ([         
     __DIR__"npc/laozu" : 1,
  ]));
  setup();
}
