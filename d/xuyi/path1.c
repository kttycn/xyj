// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "��ʯС��");
  set ("long", @LONG

һ����ʯС���ɺ�̲�������ˡ���·����ʢ���Ÿ��ָ�����Ұ������ɵ�
�裬���ﻨ�㡣��ǰ�治Զ��һ�����У�������д�š�ϙ�ǡ������̽��
�֣�������ʿ������ǰ��ע�����������������ˡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"path",
  "north" : __DIR__"nanmen",
]));

  setup();
}


