// Room: /changan/wside2.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

��ˮ��ȥ������ǹ��������ڴˣ��㲻�ɵ��Ŀ�����������
������һ��������΢����һ��������Ϣ����֪�ɺδ�Ʈ����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wside3",
  "east" : __DIR__"wside1",
]));
  set("outdoors", "changan-south");

  setup();
}





