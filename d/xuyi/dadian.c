inherit ROOM;
#include <ansi.h>
string *strs = ({
	"观宝树者，一一观之，作七重行树想。一一树，高八千由旬，",
	"其诸宝树，七宝华叶，无不具足。一一华叶，作异宝色：",
	"琉璃色中，出金色光；玻（王黎）色中，出红色光；",
	"玛瑙色中，出砗磲光；砗磲色中，出真珠绿光；",
	"珊瑚琥珀，一切众宝，以为映饰。",
	"妙真珠网，弥覆树上，一一树上，有七重网；",
	"一一网间，有五百亿妙华宫殿，如梵王宫。",
	"诸天童子，自然在中，一一童子，五百亿释迦毗楞伽摩尼，",
	"以为璎珞。",
	"其摩尼光，照百由旬，犹如和合百亿日月，不可具名，",
	"众宝闲错，色中上者。",
	"此诸宝树，行行相当，叶叶相次。於众叶间，生诸妙华，",
	"叶上自然有七宝果，一一树叶，纵广正等二十五由旬，其叶千色，",
	"有百种画，如天璎珞；　有众妙华，作　浮檀金色，如旋火轮，",
	"宛转叶间，涌生诸果，如帝释瓶。有大光明；化成幢　无量宝盖；",
	"是宝盖中，映现三千大千世界，一切佛事，十方佛国，亦於中现。",
	"见此树已，亦当次第一一观之，观见树茎枝叶华果，皆令分明。 ",
	"是为树想，名第四观。",
});
void check_time(object where);
void nianjing(object where);
void finish_nianjing(object where);
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "大圣禅寺宝殿");
	set("long",@LONG 

    这是一座宽广的大殿，正面有一座高约二十余尺的佛祖宝像，通体
金光耀眼。座下香烟缭绕，大殿两旁树立两根檀木大柱，南面是一道红
杉大门(gate)。　
LONG );
	set("exits", ([
		"north" : __DIR__"taijie",
		"east" : __DIR__"zoulang3",
	])); 
	set("valid_startroom", 1);
    set("item_desc",([ 
        "gate" : "一道三丈来高的朱红杉木包铜大门。\n"
    ]));
	set("objects",([
		"/d/nanhai/npc/shami" : 1,
		__DIR__"npc/heshang" : 2,
	]));
	setup();
}
 
void init()
{
	remove_call_out("check_time");
	check_time(this_object());
	add_action("do_nianjing", "nianjing");
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object("/d/xuyi/frontgate")) )
		room = load_object("/d/xuyi/frontgate");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision", "小沙弥上前把大门关了起来。\n", this_object());
		room->delete("exits/north");
		message("vision", "乒地一声，里面有人把大门关上了。\n", room);
	}
} 

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("大门已经是关着的了。\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要关什么？\n");

	message_vision("$N朝小沙弥点了点头。\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);

	return 1;
} 

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object("/d/xuyi/frontgate")) )
		room = load_object("/d/xuyi/frontgate");
	if(objectp(room))
	{
		set("exits/south", "/d/xuyi/frontgate");
		message_vision("$N使劲把大门打了开来。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "吱地一声，里面有人把大门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));

	if(phase==17&&(!query("xuyi/start_nianjing"))) nianjing(where);
	if(phase==20&&query("xuyi/start_nianjing")) finish_nianjing(where);
	call_out("check_time",40,where);
}

void nianjing(object where)
{
	message("channel:es",HIY+"【南赡盱眙山】大圣国师王菩萨(Guoshiwang pusa)：门徒该来念经了!\n"+NOR,users());
	where->set("xuyi/start_nianjing",1);
} 

int do_nianjing()
{ 
	object who=this_player();

	if(who->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!this_object()->query("xuyi/start_nianjing"))
		return notify_fail("还不到念经的时候呢。\n");
	if((string)who->query("family/family_name")!="盱眙山")
		return notify_fail("外派弟子不得来此念经。\n");
	tell_object( who,"你低眉垂目，口中微颂："+strs[random( sizeof(strs) )] );
	who->start_busy(5);
	if ( (int)who->query("faith")<800 )
		who->add("faith",1);
	who->improve_skill("fumozhou",random((int)(who->query("spi")+who->query("int"))/2),1);
	who->add("combat_exp",30);
	who->add("daoxing",30);
	who->add("potential",10);
	who->receive_damage("kee",20);
	who->receive_damage("sen",20);
	tell_object(who,"你觉得你的伏魔咒进步了！\n");
	return 1;
}

void finish_nianjing(object where)
{
	tell_object(where,"院外传来悠扬的钟声，却原来是经课结束了。\n");
	tell_object(where,"惠岸行者起身道：各位师兄弟请去吧，经课结束了!\n");
	where->delete("xuyi/start_nianjing");
}
