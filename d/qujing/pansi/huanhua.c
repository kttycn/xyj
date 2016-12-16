#include <ansi.h>

inherit CITY;

void create ()
{
	reload("huanhua");
	set ("short", "浣花堡");
	set ("long", @LONG

峰回路转处，竟有一个小小的城堡。漫山遍野都是长开不谢的火
红的杜鹃花，而山势也徒然开阔。城堡依山傍水而建，开阔处，
房屋林立，街上人们来来往往，甚是热闹。

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"ling2",
	]));
	set("no_clean_up", 1);

	setup();
}

int clean_up()
{
      return 0;
}

int valid_leave(object me, string dir)
{
    if (dir == "out" && query("attacker") == me->query("id"))
		return notify_fail("你正在攻城呢，临阵脱逃不太好吧！\n");
	return ::valid_leave(me, dir);
}
