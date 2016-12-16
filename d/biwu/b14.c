inherit ROOM;
void create()
{
	set("short", "风雨楼顶");
	set("long", @LONG
这里是塔的最高层，中央放着根神杖，闪闪地放出光芒。你可以向盟主要求乘车
回去(yaoche)。
    这里没有出口，你只能等待到一刻钟后被自动送回广场。
LONG );
	set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/champion": 1,
	]));

	setup();
}

void init()
{
	add_action("do_dazuo","dazuo");
	add_action("do_dazuo","exercise");
	add_action("do_yao","yaoche");
}

int do_dazuo()
{
	object me;
	me = this_player();
	tell_object(me,"这里不能打坐。\n");
	return 1;
}

int do_yao()
{
	object me;

	me = this_player();
	if(!me->query("zhanyi/mengzhu"))
		return notify_fail("你没有乘马车的权限。\n");
	if (!me->query_temp("che"))
		return notify_fail("你刚才没有乘车来这里。\n");
	me->delete_temp("che");
	message_vision("$N走出风雨楼，乘上了马车匆匆忙忙地离去了。\n",me);
	me->move("/d/city/center");
	message_vision("$N又回到了长安。\n",me);
	return 1;
}

/*
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="down")
{remove_call_out("awayaway");
this_player()->set_temp("for_okok",0);
}return 1;
}*/
