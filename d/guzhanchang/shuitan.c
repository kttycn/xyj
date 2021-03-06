//stone 20020611
///d/guzhanchang/shuitan.c 
#include <ansi.h>
inherit ROOM;
int do_dive();

void create()
{
	set("short", "水潭");
	set("long", @LONG

展现在你面前是个宽约百丈的深潭。你站在岸边的大石头上远眺，
只见潭水色呈碧蓝，黑沉沉的，深不见底；潭心暗流汹涌，波浪
翻滚，形成一个巨大的漩涡，潭中不见一条鱼虾游动。

LONG);
	set("exits", ([
		"east" : __DIR__"pondside",
	]));
	set("resource", ([
		"water" : 1,
	]) );
	set("no_clean_up", 0);
	set("outdoors", "guzhanchang");
	setup();
}

void init()
{
	object who=this_player();
//	object where=this_object();
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
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
	message_vision(HIY "$N一个鱼跃，“噗通”一声，跳入潭中。\n那潭水果然凶险，$N刚一入水，刚冒得一冒，被激流一卷，登时吸入潭水中心。\n" NOR, who);
	if(!( room = find_object(__DIR__"tandi1")) )
		room = load_object(__DIR__"tandi1");
	if(objectp(room))
	{
		who->move(room);
		message_vision("$N潜到了潭底。\n",who);
	}
	return 1;
}

int sounding(object where)
{
    string *msgs=({
    "水面上不时泛起一丝丝白气如烟般上升飞去。\n",    
    "潭中的水咕嘟咕嘟的冒出无数个气泡。\n",
    "一道道的白气贴着潭面上蜿蜒缓慢升起。\n",
    "一团团的雾逐渐聚集把潭面笼罩起来了。\n",
    "一阵风迎面吹来，竟然是热气腾腾的。\n",    
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}
