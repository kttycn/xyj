// /d/welcome/welcome.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "混沌之初");
	set ("long", @LONG
混元开世，泥潭中就有了这一片极乐之净土，何去何从？哦！如
果你是老泥巴转世于此，还请向[1;33m oldplayer[2;37;0m这条路走，你所要做的只
是用[1;33m news [2;37;0m来看看这里都有些什么新东西。如果你是初玩泥巴，呵呵！
那么还是请你走[1;33mnewbie[2;37;0m这条路吧。
[1;31m新手通告:新手请看一下!!!!
[1;30m
新手用help 或查看其中分项，如help task,help wlzb,help
 qujing,help aboutquest这是我们MUD的基本生存方法.也是
我们与别的西游MUD不同的地方.我们所有的pfm,也是与其它西游
ＭＵＤ不同的,我们的pfm十分华丽,基本上全部全新的,用verify
 可以查看你所学的PFM.我们还有类UO的生存技能,大家可以用
skills2查看.查地图用help maps
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"newbie" : __DIR__"newbie1",
		"oldplayer" : "/d/city/kezhan",
	]));
	set("objects", ([
		"/d/city/npc/shizhe" : 1,
	]));
	set("no_beg", 1);
	set("valid_startroom", "1");
	set("pingan", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
