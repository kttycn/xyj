// Room: /d/death/room10.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������������ס���ˣ�ûɶ�ÿ��ġ�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/suoming" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"up" : __DIR__"naiheqiao",
	]));

	setup();
	replace_program(ROOM);
}
