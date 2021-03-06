inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条小路，已经走到了尽头，倚云处有一株老松树(tree)，
显得十分的粗壮，有几只不知名的小鸟在其中窜来窜去。在树底好
象有一个非常小的树洞(cave)，不注意，你还真发现不了。
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"xiaolu0",
	]));

	set("item_desc", ([
		"tree" : "一棵大树，枝叶茂密，看不清上面的情况。枝头挂满了松子。\n",
	]) );
	set("no_fly",1);

	setup();
}

void init()
{
	add_action("do_enter", "zuan");
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object room;
	object who = this_player();
	if(!arg || arg != "cave")
		return notify_fail("你要进哪里？\n");
	if(!( room = find_object("/d/city/center")) )
		room = load_object("/d/city/center");
	if(objectp(room))
	{
		message_vision("$N钻出了小洞，眼前豁然一亮，竟然来到了长安城中。\n",who);
		tell_room( room, "你眼前一暗，$N不知从何处钻了出来。");
		who->move(room);
	}
	return 1;
}
