// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "����֮·");
	set ("long", @LONG
��Ӱ��Ե������֮·��һ������֮·����·ͨ����ǹ���ġ��ˡ�
�񡢹����磬Ϊ�������ڽ��Ľ���·�Ϲ���һ����˳����������
��һ��[1;33m help newbie[2;37;0m������������ϸ�Ľ�˵��һ����������̶�е���
��֮����Ҫ�����������Ǳز����١�
LONG);

	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"newbie2",
	]));
	set("no_beg", 1);
	set("pingan", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
