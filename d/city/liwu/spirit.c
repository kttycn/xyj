// by night
// fid 修改

inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", HIY"精灵楼"NOR);
	set ("long", @LONG
由夜精灵所筑，临窗的地上铺著猩红毛毯，楼阁正面设著大红金钱
蟒靠背，石青金钱蟒引枕，秋香色金钱蟒大条褥。两边设一对梅花式
红漆小几，几上茗琬瓶花俱备，还有一个翡翠所造的箱子。
LONG);

	set("exits", ([
                "down" : __DIR__"happyjie",
	]));
	set("objects", ([
//		__DIR__"obj/xiang" :  1,
		__DIR__"npc/spiriter.c" : 1,//人物的路径，自定义。
	]));

	setup();
}

//以下是我mud的一个功能，在往上走的时候必须支付1 gold.可以去掉...
/*
int valid_leave (object who, string dir)
{
	if (dir != "up")
	return ::valid_leave (who, dir);

	if (! who->query_temp("kaifeng_donate_silver"))
		return notify_fail ("请捐(donate)一两黄金到翡翠箱里。\n");

	return ::valid_leave (who, dir);
}
*/
