//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", HIW"�ħ��"NOR);
  set ("long", @LONG
������ǹ�Ѻħ������ĵط����ڰ�֮Ԩ�ĵصס�
[1;31m      ��[2;37;0m
[1;31m      ��[2;37;0m
[1;31m      ħ[2;37;0m
[1;31m      ��[2;37;0m
LONG);

  set("objects", ([ 
     __DIR__"npc/wutian" : 1,
]));
        setup();
}
