// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /xuyi/taizifu.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "̫�Ӹ�");
  set ("long", @LONG

������С̫�ӵĸ�ۡ��������Ȼ��������������Ȼ��һ�ָ߹�����ŵ���
Ϣ������������һ����ü��Ŀ����������������ʫ�������Ա�СѾ�߶���
��ˮ��̽ͷ���͡�
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/d/xuyi/npc/prince" : 1,
  "/d/xuyi/npc/yahuan2" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"piandian",
]));

  setup();
}

