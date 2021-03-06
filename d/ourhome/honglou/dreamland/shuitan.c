
//shuitan.c 寻水灵珠
#include <ansi.h>
inherit ROOM;
int do_dive();
int do_jump();
void create()
{
	set("short", "水潭");
	set("long", @LONG
迎面是一个瀑布，下面是一个巨大的水潭，瀑布倾泻入水潭，发出轰轰的巨响。
飞溅的水雾在阳光下出现了美丽的彩虹。潭中许多白色的鱼游来游去。
LONG);
	set("exits", ([
		"northeast" : __DIR__"shangu2",
	]));
	set("resource", ([
		"water" : 1,
	]) );

	setup();
}
void init()
{
	add_action("do_dive","dive");
	add_action("do_jump","jump");
}

int do_dive()
{
	object zhou,who,room;

	who = this_player();
	if(( !(zhou=present("bishui zhou", who))
	||(string)zhou->query("unit")!="张")
	&& (string)who->query("family/family_name")!="龙宫"
	&& (string)who->query("family/family_name")!="东海龙宫")
		return notify_fail("你一个猛子扎到水里．．．\n"+
		"\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");
	message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, who);
	if(!( room = find_object(__DIR__"tandi")) )
		room = load_object(__DIR__"tandi");
	if(objectp(room))
	{
		who->move(room);
		message_vision("$N潜到了潭底。\n",who);
	}
	return 1;
}

int do_jump()
{
	object zhou,who,room;

	who = this_player();
	message_vision(HIY "$N吃力地爬呀爬......\n" NOR, who);
	if( !(who->query_temp("ask_qingsuo_li") 
	|| who->query_skill("dodge", 1) < 150 ))
	{
		message_vision(CYN"\n可是石壁太光滑了$N一不小心滑了下来。。。\n"NOR, who );
		who->unconcious();
		return 1;
	}
	if(!( room = find_object(__DIR__"shulin0")) )
		room = load_object(__DIR__"shulin0");
	if(objectp(room))
	{
		message_vision(CYN"\n$N刺溜一声就爬了上去。\n你大吃一惊,想不到这里竟有如此天地。\n\n"NOR,who);
		who->move(room);
	}
	return 1;
}
