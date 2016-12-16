#include <ansi.h>

inherit CITY;

void create ()
{
	reload("erengu");
	set ("short", "恶人谷");
	set ("long", @LONG

这里没有门没有塔，也没有栏栅。竟是个山村模样，一栋栋房屋，
在灯火的照耀下，竟显得那么安静、平和。一方石牌立在道旁。
上面写着：“入谷入谷，永不为奴。”

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"shanlu3",
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
