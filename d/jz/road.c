//Cracked by Roath
inherit ROOM;
void create ()
{
	set ("short", "官道");
	set ("long", @LONG

　　这是一条并不算宽阔的官道，看起来走的人不多，可以看到路
上很少留有人或动物留下的痕迹。
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"ngate",
		"north" : "/d/gao/lu2",
	]));
	set("outdoors", "jiangzhou");
	setup();
}
