// 九重天 望仙崖 by Calvin

#include <ansi.h>
inherit ROOM;
#include <room.h>
string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", WHT"望仙崖"NOR);
  set ("long", @LONG

相传这里的山崖是上天所设，是为心诚者提供的成仙便径，
只要诚心得道的人跳下崖去就会升仙，遨游极乐世界....
你可以试试跳下去(jump down)。

LONG);

  set("exits", ([ /* sizeof() == 3 */
//  "up": __DIR__"lingge",
]));

  setup();
}
void init() {
	add_action("do_jump","jump");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_jump(string arg) {
  object me=this_player(),ridee=me->ride();
  int damage;
  string dest=__DIR__"lukou0";

  string msg;

   if (!arg) return 0;
  if (arg!="down") return notify_fail("往哪儿跳？\n");

  msg="$N";
  if (ridee) msg=msg+"骑着"+ridee->query("name");
  msg+="纵身往崖底跃下。\n\n一朵朵的白云在你的脚下飘飘而过。\n\n";
  message_vision(msg,me);

  damage=random(300-me->query_skill("dodge"));
  if (damage>me->query("eff_kee")-200) damage=me->query("eff_kee")-200;
  if (damage<=0) damage=0;
  me->receive_wound("kee",damage);
  me->move(dest);
  if (ridee) ridee->move(dest);
  if (!damage) message_vision("$N从悬崖上跳了下来，轻轻巧巧地落在地上，毫发未损。\n",me);
  else {
  message_vision("$N从悬崖上跳了下来，跌了个大跟斗。\n",me);
  COMBAT_D->report_status(me); 
  }
  if (ridee) {
      message_vision("\n$N骑着的"+ridee->query("name")+"摔成了一团肉饼。",me);
      ridee->die();
  }
  me->start_busy(1+random(2));
  return 1;
}


int do_climb(string arg)
{
	object me;

	me=this_player();
	
	if( !arg || (arg != "left" && arg != "right" && arg != "up" && arg != "down") ){
		return notify_fail("你要爬到哪里去？\n");
	}

	if( arg == "right" ) 
	{
		message_vision("$N紧贴岩壁，死抓石棱地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move("/d/wusheng/xuanya3");
	}

	else return notify_fail( "往"+direction_name(arg)+"已经没有着手之点了。\n" );

	message_vision("$N从"+direction_rev(arg)+"面爬了过来，轻轻吁出了一口气。\n", me);   
	return 1;    

}

string direction_name(string arg)
{
	if ( arg == "right" ) return "右";
	else if ( arg == "left" ) return "左";
	else if ( arg == "up" ) return "上";
	else if ( arg == "down" ) return "下";
	else return "不知道哪儿";
}

string direction_rev(string arg)
{
	if ( arg == "right" ) return "左";
	else if ( arg == "left" ) return "右";
	else if ( arg == "up" ) return "下";
	else if ( arg == "down" ) return "上";
	else return "不知道哪儿";
}