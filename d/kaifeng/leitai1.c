// leitai.c 擂台
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "比武擂台");
	set("long",@long
这里是开封城里的一个擂台，这里据说曾经有很多对武林人士在这里比
武，招亲。擂台下面的人声鼎沸，擂台之上有一面大鼓(gu)，想在这里比武
的人必须要先击鼓，才能比擂。在擂台的中央放着一块大牌子(paizi)，在擂
台的一角放着一块比擂须知(sign)。
long);
	set("exits",([
		"down" : __DIR__"leitai",
	]));

	set("item_desc", ([
		"gu" : "这是一面大鼓，比擂的人分为两种一种是切磋比试(dagu qiecuo player name)" +
				"另外一种是生死决战(dagu juezhan player name),如果你想在擂台上了结恩怨" +
				"是非，那么进行生死决战是再好不过的选择了。\n",
		"paizi" : "生  死  自  负\n",
		"sign" : "在比武之前必须击鼓，办法请详见(gu),然后就可以比划了(fight player name)。\n",
	]));
//	set("no_death", 1);;
	set("objects",([
		__DIR__"npc/killer" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_dagu", "dagu");
}

int do_dagu(string arg)
{
	object ob, me = this_player();
	string opp, opp1, str, event;

	if ( !arg ) return notify_fail("你要宣布什么？\n");

	if ( sscanf(arg, "%s %s %s", event, opp, opp1) == 3 ) return notify_fail("和公平子较什么劲呀。\n");

	if ( sscanf(arg, "%s %s", event, opp) != 2 ) return notify_fail("你要宣布什么？\n");

	if ( me->query("id") == opp ) return notify_fail("你有毛病啊？\n");

	if ( !present(opp, environment(me)) ) return notify_fail("这里并无此人，还是约好再来吧。\n");

	if ( !find_living(opp) ) return notify_fail("你鬼迷心窍啦？那不是活物！\n");

	if ( event == "marryfight" || event == "zhaoqin" ) {
		if ( me->query("gender") == "无性" )
			return notify_fail("你这辈子别指望了！\n");
		else if ( me->query("class") == "bonze" )
			return notify_fail("你凡心未净，罪过！罪过！\n");
		else if ( me->query("gender") == "男性" )
			return notify_fail("唯有女方才能举行比武招亲！\n");
		else str = "比武招亲";
	}
	else if ( event == "fight" || event == "qiecuo" ) {
		str = "切磋比试";
	}
	else if ( event == "kill" || event == "juezhan" ) {
		str = "生死绝战";
	}
	else return notify_fail("这里只供比武招亲(marryfight,zhaoqin)，切磋比试(fight,qiecuo)及生死绝战(kill,juezhan)所用。\n"); 

	ob = find_player(opp);

	message_vision("$N拿起鼓槌，打了大鼓一下，大鼓发出「嗵」的一声巨响，传出老远。\n", me);

	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s拿起鼓槌，打了大鼓一下，大鼓发出「嗵」的一声巨响，传出老远。", me->name()));
	me->delete_temp("last_channel_msg");
	CHANNEL_D->do_channel(me,"chat",sprintf("本人现与%s于擂台进行%s，请各位江湖同道做个见证。", ob->name(), str));
	me->set_temp("dagu", 1);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->is_fighting()) return notify_fail("打完架才能离开。\n");
	me->remove_all_killer();
	me->delete_temp("dagu");
	return ::valid_leave(me, dir);
}
