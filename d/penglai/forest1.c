//Room /d/penglai/forest1.c

inherit ROOM;

void create()
{
	set("short","树林");
	set("long",@LONG

到了这里，树木更加繁荣茂盛了，这里的树少说也有几百年的
树龄了，这些树的旁边长着许多说不出名字的植物，如果你用心
的话，说不定能找(search)到一些奇花异草。
LONG);

	set("exits",([
		"east" : __DIR__"forest",
	]));
	set("num",10);

	setup();
}

void init()
{
	add_action("do_search","search");
	add_action("do_search","zao");
}

int do_search(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if(me->query("kee") < 50)
		return notify_fail("你现在太累了，歇会儿吧！\n");

	if(query("num") <= 0)
		return notify_fail("这里没什么好找的了！\n");

	message_vision("$N低着头，眼睛盯着地上不知道在找些什么。\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;
}

int finish(object me)
{
	object shouwu;

	if(random(me->query_kar()) > 15 )
	{
		message_vision("$N眼前一亮，发现了一个何首乌！\n",me);
		message_vision("乘着没人注意，$N把何首乌揣到了怀里！\n",me);
		shouwu = new("/d/jz/herb/heshouwu");
		shouwu->move(me);
		add("num",-1);
		return 1;
	} else {
		message_vision("$N找了半天什么也没找到！\n",me);
		me->start_busy(3);
		return 1;
	}
}
