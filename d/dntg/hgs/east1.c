// Room: /d/4world/east1.c
inherit ROOM;

void create ()
{
  set ("short", "��Է��");
  set ("long", @LONG

��Է����û��ʲô�̼ң���������Ҳ���ࡣ�ϱ���һ�Ҵ����ݣ�
���治ʱ�������䷢����������һ������ͭ���Ŵ󿪣�����Ҳ
��������Ժ�䡣�����Ǹ���Ժ��������ʮ�ֵظɾ���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/wuguan/school1.c",
  "west" : __DIR__"center",
  "north" : __DIR__"shuyuan.c",
  "east" : __DIR__"east2.c",
]));
  set("outdoors", __DIR__"");

  setup();
}
