// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
	set ("short", "入世之路");
	set ("long", @LONG
离开入世之路后！你会到达游戏中的第一站！也就是长安城，在长
安城里，你也可以在里面的客栈做做工作挣些钱，也可以到傲来武馆学
点初级的武技好了！我们还为你们准备了一些装备了，到了客栈后，
west,north,down。然后list，就可以列出所有可以给你的装备，但
要记住：这些东西可不能卖哟。让我们祝贺你踏入西行之路吧！
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"down" : "/d/city/kezhan",
	]));
	set("no_magic", 1);
	set("no_beg",1);
	set("pingan",1);
	set("no_fight", 1);

	setup();
}
int valid_leave(object me, string dir)
{
	if (dir =="down")
	{
		me->set("startroom","/d/city/kezhan");
		me->save();
	}
	return ::valid_leave(me, dir);
}
