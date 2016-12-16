//standroom.c used by weiqi...others may hate this format:D
//bingya-up7.c
#include <ansi.h>
inherit ROOM;

string direction_name(string);
string direction_rev(string);

void create ()
{
	set ("short", "冰崖上");
	set ("long", @LONG

你趴在冰崖上，当真是小心翼翼。
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/jz/herb/xuelian" : 1,
		//__DIR__"npc/xunshi" : 1,
	]));

	set("outdoors", "xuesan");
	setup();
}

void init()
{
	add_action("do_read", "mianbi");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();

	if( !arg || (arg != "up" && arg != "down" && arg != "left" && arg != "right") )
	{
		return notify_fail("你要爬到哪里去？\n");
	}

	if( arg == "up" ) 
	{
		message_vision("$N手足并用，小心翼翼地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move(__DIR__"binggukou");
	}
	else if( arg == "down" ) 
	{
		message_vision("$N手足并用，小心翼翼地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move(__DIR__"bingya-up6");
	} 
	else return notify_fail( "往"+direction_name(arg)+"已经没有着手之点了。\n" );

	message_vision("$N从"+direction_rev(arg)+"面爬了过来，长长地舒了口气。\n", me);   
	return 1;    
}

string direction_name(string arg)
{
	if ( arg == "up" ) return "上";
	else if ( arg == "down" ) return "下";
	else if ( arg == "left" ) return "左";
	else if ( arg == "right" ) return "右";
	else return "不知道哪儿";
}

string direction_rev(string arg)
{
	if ( arg == "up" ) return "下";
	else if ( arg == "down" ) return "上";
	else if ( arg == "left" ) return "右";
	else if ( arg == "right" ) return "左";
	else return "不知道哪儿";
}

int do_read(string arg)
{
	object me=this_player();

	if(me->is_busy() )
		return notify_fail("你现在忙着呢，哪有功夫面壁修炼...\n");

	if((int)me->query_skill("ningxue-force",1)<100 )
	{
		if(me->query_temp("xueshan_ice") >= 10)
		{
			tell_object(me,BLU"你被冻得嘴唇乌青发亮。\n"NOR);
			me->delete_temp("xueshan_ice");
			me->unconcious();
			return 1;
		}
		if(me->query_temp("xueshan_ice") == 5)
			tell_object(me,HIB"你被冻得实在受不了了，还是赶快起来活动一下吧。\n"NOR);
		else tell_object(me,HIB"你冻得嘴唇发青，身子微微发抖，好象冷得厉害。。\n"NOR);
		me->add_temp("xueshan_ice", 1);
		return 1;
	}

	if(me->query("family/family_name") != "大雪山")
	{
		tell_object(me,"你不是大雪山的，你来瞎搅和什么。\n"); 
		return 1;
	}
	if(me->query("sen") < 100)
	{
		tell_object(me,"你还是先休息一会儿吧。\n");     
		return 1;
	}
	message_vision("$N盘膝坐了下来，开始面壁。。。\n", me);
	me->add("sen",-50);
	me->start_busy(2);
	if(me->query("xueshan/yushijufen_perform")) 
	{
		tell_object(me,"你似乎不能在这里悟到什么了。\n");       
		return 1;
	}
	if((int)me->query_skill("bingpo-blade", 1) > 149){
		tell_object(me,HIW"你感觉到了一阵的悲痛从心中袭来！\n"NOR);
		me->improve_skill("ningxue-force", 50+random(10));
		me->add("xueshan/bingpo",1);
		me->start_busy(2);
	}
	if(me->query("xueshan/bingpo",1) > 500)
	{
		me->set("xueshan/yushijufen_perform",1);
		tell_object(me,HIR"\n你挺身站了起来，狂笑一声，说道："HIY"从此天下何人敌手？"HIR" 顿时你领悟出了"HIW"「玉石俱焚」"HIR"！\n"NOR);
		me->delete("xueshan/bingpo");
	}
	return 1;
}


