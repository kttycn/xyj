//Cracked by Roath
// Room: /moon/yunu5.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
	set ("short", "��Ů��");
	set ("long", @LONG

��ѩ���硣���������û��·������ǿ��סһЩͻ�����ı��飬�����ҳ�
һ��·��������һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�
LONG);

	set("outdoors", "moon");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/houyi" : 1,
	]));
	set("exits", ([ /* sizeof() == 2 */
		"westup" : __DIR__"neartop",
		"eastdown" : __DIR__"yunu4",
	]));

	setup();
}
