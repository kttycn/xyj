inherit ROOM;

int do_dig(string arg);

void create()
{
	set("short", "林间空地");
	set("long", @LONG
这是一块林间空地，四周的树木花草像是被人修剪过一般，环
绕著空地围成一个整齐的圆形，空地中央一株巨大的松树像平地上
撑起一把大伞，树上针叶茂密得遮去了大半的阳光。
LONG
	);
	set("exits", ([
	]));

	set("outdoors", "dreamland");
	setup();
}

void init()
{
	add_action("do_dig","dig");
}

int do_dig(string arg)
{
	object ob = this_player();
	object wield;
	object sword;
	string sword_given,ziqing_given;

	sword_given = "/d/ourhome/honglou/dreamland/obj/qingsuo-sword.c";
//	ziqing_given = "/d/ourhome/honglou/dreamland/obj/ziqing-sword.c";

	if ( ! arg || arg != "di" )
		return notify_fail("你要挖什么？\n");
//	if ( present("qingsuo sword",ob) || present("ziqing shuangjian",ob) )
//		return notify_fail("你不是正拿着一柄吗，人可不能太贪心啊。\n");
	if ( present("qingsuo sword",ob))
		return notify_fail("你不是正拿着一柄吗，人可不能太贪心啊。\n");
//	if ( (sword_given->in_mud()) || (ziqing_given->in_mud()) )
//		return notify_fail("你来迟了一步，已经有人捷足先登了。\n");
	if ( sword_given->in_mud())
		return notify_fail("你来迟了一步，已经有人捷足先登了。\n");
	
	
	if(!wield=ob->query_temp("weapon"))
		return notify_fail("你身上没有利器。\n");
	if(((string)wield->query("skill_type")!="sword"
	&& ((string)wield->query("skill_type")!="blade")))
		return notify_fail("你应该找把剑，或是刀什么的。\n");

	if( random(6) == 3 )
	{
		ob->add("kee",-50);
		message_vision("$N用力挖了一会，突然感觉有个东西埋在地下。\n",ob);
		message_vision("$N居然发现传奇中的青索剑。\n",ob);
		sword=new("/d/ourhome/honglou/dreamland/obj/qingsuo-sword");
		sword->move(ob);
		if( sword->query("id")=="qingsuo sword" ) 
			MONITOR_D->report_rumor_object_msg(ob, "拿到〖青索剑〗了！");
		return 1;
	}
	ob->add("kee",-50);
	ob->start_busy(1);
	message_vision("$N费了大办天的劲，什么也没有挖到。\n",ob);
	return 1;
}
