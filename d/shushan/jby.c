//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "�����");
  set ("long", @LONG

�������ɽ�ɵĽ���£�ԶԶ��ȥ�·��ܿ���̫������ĵط���
���ǡ��Ӹ����¡�������������ȥ����ͷͻȻһ�������ǿ�����
�׵���Ԩ����һʧ�����ȥ�ͻ����������ǡ��㲻��������˼�����
��������ɽ���أ�����ɽ���ӿ��ء�
LONG);

  set("outdoors", "shushan");
  set("exits", ([ 
       "south" : __DIR__"houshan6",
         "east" : __DIR__"jindi",
        "west" : __DIR__"feipu",

 ]));

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  
  object who = this_player();
  message_vision("$N��������ţ�����һ������\n",who);
  message_vision ("$N��������������������һ�������\n",who);
  who->unconcious();
  who->move(__DIR__"shanjian");
  return 1;
}
