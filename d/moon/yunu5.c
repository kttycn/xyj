//Cracked by Roath
// Room: /moon/yunu5.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
	set ("short", "玉女峰");
	set ("long", @LONG

冰雪世界。这里根本就没有路。你勉强扳住一些突出来的冰块，试着找出
一条路来。往下一看，不由得头晕目眩，你赶紧闭上眼睛，生怕一个不慎
，摔得粉身碎骨。
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
