// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by night 7/26/2000

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ϙ�����ţ�һ��С���Ƴ�ǽ��������ǽ���ںӱ�����ʯ������ݳɣ�
�߶����壬�����ɣ���������¥��פ�и��ڡ��������������������ľ�
ʿ��һλ�����Ĵ������Ĵ�Ѳ�飬�ɴ����۾��۲����������������ˡ���
ʯС��ֱ�����죬ͨ����

LONG);

  set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/zhao" : 1,
        __DIR__"npc/weishi" : 4,
]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"path1",
  "north" : __DIR__"jiedao0",
]));

  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/xuyi_b", "???");
}
