// changan wusheng
// baiyun0.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ʥ����");
  set ("long", @LONG

һ�������˸ߣ������˿��ɽ���ڣ������ϻ�������д������
���֡�����ʥ�𶴡������ڹɹ��ȷ紵�������л�����˿˿��ζ��
��ʱ����һ��������������Ī���й��ޣ�������
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "���к��������ʲôҲ���������\n",
]));
  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"huoyun0",
  "south" : __DIR__"xuanya3",
]));

  setup();
}

