inherit ROOM;
void init();
int do_move(string arg);
int do_enter(object me);

void create()
{
	set("short","花园");
	set("long",@LONG
你的眼前出现了一个美丽的花园，花园里种着一些花，花从中隐约可
见飘渺的倩影，那是府中的丫鬟们在玩耍。花园中央有一座假山(jiashan)。
花园的东西两头是长廊，南边有一条小道不知通向哪????
LONG );
	set("exits",([
		"south"	: __DIR__"xiaolu0",
		"north"	: __DIR__"zoulang2",
		"east"	: __DIR__"qianyuan",
	]));
	set("outdoors", "fenghuang");
	set("item_desc", ([
		"jiashan" : "这座假山看起来不算太大，你应该可以搬动(move)它.\n",
	]));
//	set("no_clean_up", 0);
	set("no_fly",1);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{			
	object mishi;
	object me=this_player();
	if(!arg || arg!="jiashan")
		return notify_fail("你要移动什么？\n");
	if((int)me->query_str()>68)
	{
		if( !(mishi = find_object(__DIR__"anshi")) )
			mishi = load_object(__DIR__"anshi");

		if( mishi ) 
		{
			set("exits/enter", mishi);
			message_vision("$N使出吃奶的力气推去，只听喀喀几声，假山移开，露出向下一个通口。\n", this_player());
			message("vision", "大石被人从外推开了。。\n", mishi );
			mishi->set("exits/out", __DIR__"huayuan2");
			call_out("close_down", 30);
		}
		return 1;
	}
	else
		message_vision("$N使出吃奶的力气也挪不动假山，只好悻悻地放弃了。\n", this_player()); 
	return 1;			 
}

void close_down()
{
	object mishi;

	message("vision", "假山轰地一声又回到原位。\n", this_object() );
	if( mishi= find_object(__DIR__"mishi1")) {
		message("vision", "假山轰地一声又回到原位。\n", mishi);
		mishi->delete("exits/out");
	}

	delete("exits/enter");

}
