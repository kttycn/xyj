//Cracked by Roath
// Room: /d/4world/school1.c
inherit ROOM;

void create ()
{
	set ("short", "东方武馆大门");
	set ("long", @LONG

你现在正站在一间大宅院的入口，两只巨大的石狮镇守在大门的两
侧，一阵阵吆喝与刀剑碰撞的声音从院子中传来，通过大门往南可
以望见许多身穿灰衣的汉子正在操练。
LONG);

	set("light_up", 1);
	set("no_magic", 1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 1,
	]));
	set("outdoors", __DIR__"");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"school2.c",
		"north" : "/d/dntg/hgs/east1",
	]));
	set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" ) {
		if ( (me->query("combat_exp")<30000 || me->query("daoxing")<30000
		|| me->query("maximum_force")<900 ) || wizardp(me) )
			return ::valid_leave(me, dir);
		else if(objectp(present("guard", environment(me))))
			return notify_fail("老齐笑道：东方武馆已不能再教你什么了，请回，请回。\n");
		return 1;
	}
	return 1;
}
