// Room: /d/city/chufang

#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create ()
{
	set ("short", "厨房");
	set ("long", @LONG
这儿是南城客栈的厨房，干净整齐，墙边的柜子里放着整整齐齐的餐具。
厨房的一角有一个小小的水池，里面是清清的水，你可以在这儿洗（xi）
些什么。
LONG);

	set("no_dazuo",1);
	set("no_kill",1);
	set("no_fight",1);
	set("kezhan",1);
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"kezhan",
	]));
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_xi","xi");
	add_action("do_mo", "mo");
}

int do_xi(string arg)
{
	object me=this_player(); 
	object ob,ob1;
	if (!me->query_temp("gongzuo/xipanzi"))
		return notify_fail("你还是先去给店小二打个招呼吧。\n");

	if (!arg || (arg != "脏盘子" && arg != "zangpanzi") )
		return notify_fail("你要洗什么？\n");

	if (!(ob = present("zangpanzi", this_player())))
		return notify_fail("你身上没有脏盘子，怎么能洗呢？。\n");

	if ( (int)me->query("sen")<20)
		return notify_fail("你太累了，歇息下吧。\n");

	if (me->query_temp("gongzuo/xipanzi")==6)
		return notify_fail("盘子洗好了！送回店小二那儿吧。\n");

	message_vision("$N从池子里勺起水，开始慢慢的洗盘子。\n",me);
	me->add("sen",-(10+random(10)));
	me->add_temp("gongzuo/xipanzi",1);
	if ( (int)me->query_temp("gongzuo/xipanzi")==6)
	{
		message_vision(CYN"$N洗了良久，终于将盘子全部洗好了。\n"NOR,me);
		ob->set_name( "盘子" , ({"panzi"}));
		ob->set("long","一叠刚洗好的盘子。\n");
	}
	return 1;
} 

int do_mo(string arg)
{
	object me, key;
	int sen;

	me = this_player();
	notify_fail("你什么也没摸着。\n");
	
	if(me->is_busy()) return 0;

	sen=me->query("sen");
	if(sen<110) return 0;
	me->add("sen",-100);

	sen=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(sen<10000) return 0;

	key = new(__DIR__"obj/candle");
	key -> move(me);
	message_vision("你摸到一支生日蜡烛。\n", me);

	return 1;
}
