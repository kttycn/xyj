// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "��ʯС��");
  set ("long", @LONG

һ����ʯС���ɺ�̲���쵽Զ������·���Բ�Զ��һЩ��ׯ������������
�𡣴�ׯ��Χ��һ������أ�������һЩ���ڸ�����ũ�ˡ��������ط�
�֣�����ǧ�꣬���㰵�ͣ���账������һ�ɸ�����ƽ֮����
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"island",
  "northwest" : __DIR__"path1",
]));

  setup();
}


