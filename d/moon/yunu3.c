//Cracked by Roath
// Room: /moon/yunu3.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "��Ů��");
  set ("long", @LONG

��ѩ���硣���������û��·������ǿ��סһЩͻ�����ı��飬�����ҳ�
һ��·��������һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�����������һƬ���͸�����㡣
LONG);

  set("outdoors", "moon");
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"yunu2",
  "southup" : __DIR__"yunu4",
]));

  setup();
}






