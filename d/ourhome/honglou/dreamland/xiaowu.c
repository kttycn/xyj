
//xiaowu.c 寻李逍遥
inherit ROOM;
int do_open(string arg);
void create()
{
	set("short", "小茅屋");
	set("long", @LONG
这是一个简陋的小茅屋，东面墙上挂着一柄宝剑，想来主人当年也是叱咤风云。
西面墙上贴着一首诗：
        仙灵岛上别洞天，池中孤莲伴月眠。
        一朝风雨落水面，愿君拾得惜相怜。
LONG
	);
	set("exits", ([
		"out" : __DIR__"shangu2",
	]));
	set("objects", ([
		__DIR__"npc/servent" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
	object who=this_player();
	object ob;

	if(who->is_busy()) return notify_fail("你正忙着呢！\n");
	if(!arg || arg != "密道")
		return notify_fail("你要打开什么？\n");
	if( (int) who->query("force_factor") >= 100 )
	{
		write("打开了西面屋角的一扇暗门。\n");
		if( !query("exits/down") ) {
			set("exits/down", __DIR__"xiaowu2");
			call_out("close_path", 5);
		}
		return 1;
	}
	else
	{
		write("试着推了推墙角，但没有什么动静。\n");
		return 1;
	}
}

int valid_leave(object me, string dir)
{
	object ob;
	int i;
	if( dir == "west" && ob=present("servent", this_object())
	&& !me->query("search_for_mujian") && !wizardp(me) )
	{
		message_vision("$N对$n喝道：想进去？宰了我再说！！\n", ob,me);
		ob->kill_ob(me);
		return notify_fail("快逃！\n");
	}
	if ( me->query("search_for_mujian") )
		message_vision("$N对$n笑道：是小姐让你来取木剑的吗？请进，请进，哎，这孩子！！\n", ob,me);
	return 1;
}

void close_path()
{
	if( !query("exits/down") ) return;
	message("vision","暗门又喀嚓一声关上了。\n",this_object() );
	delete("exits/down");
}
