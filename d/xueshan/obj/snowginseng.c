//snowqinseng.c
//stone
//20020221

#include <ansi.h>
#include <dbase.h>
//#include "message.h"
inherit ITEM;

int do_eat(string);
int do_smell(string);
int do_water(string);
int do_fix(string);
void destroy();
void init();

int init ()
{
  if(this_player()==environment())
  add_action ("do_eat", "eat");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  add_action ("do_water", "water");
  add_action ("do_fix", "fix");
  call_out("need_water", 10+random(10), environment(this_object()));
  return 1;
}

void create()
{
	set_name(HIW"千年雪参"NOR, ({HIW"xue shen"NOR,"xue shen","snowshen"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", HIW"这是一株通体雪白，晶莹剔透的千年雪参。一看就知不是寻常之物，不易保存。\n"NOR);
		set("value", 900000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	string type;
	object me = this_player();
	if(me->is_fighting())
		return notify_fail("打完了再吃吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢!\n");
	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if ((string)environment(me)->query("short")=="禹王林" )
		return notify_fail("这里这么危险还吃什么东西啊？\n");

	me->set("food", (int)me->max_food_capacity());
	me->add_maximum_mana(100);
	me->add_maximum_force(100);
	message_vision("$N小心翼翼地把千年雪参纳入口中，慢慢咀嚼。
"HIG"忽觉一股极寒之气从丹田起，顿感全身如坠冰窟，须发上慢慢的结了一层薄薄的霜。\n" NOR, me,);
	me->unconcious();
	destruct(this_object());
	return 1;
}

int do_smell (string arg)
{
  object me = this_player();
  object xueshen = this_object();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xue shen")
    return 0;

  switch (random(3))
  {
    case 0:
      { msg = "$N闻了闻"+name+"，一缕清香泌入心肺，顿时神清气爽。\n"NOR; break; }
    case 1:
      { msg = "$N低头嗅了一下"+name+"，一股浓郁的参香弥漫在这里。\n"NOR; break; }
    case 2:
      { msg = "$N捧着"+name+"一嗅，不觉精神一振。\n"NOR; break; }
    }
  message_vision (msg,me);
  return 1;
}

int do_fix (string arg)
{
  object me = this_player();
  object xueshen = this_object();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xue shen")
    return 0;

  msg = "$N将"+name+"小心地用湿润的丝绢包好。\n";
  xueshen->set("fixed",1);
  message_vision (msg,me);
  return 1;
}

void need_water (object where)
{
  object xueshen = this_object();
  object who = environment(xueshen);
  string name = xueshen->query("name");
  string msg;
  object xueshengan;

  if (!who || !living(who))
    return;

  if (xueshen->query("fixed"))
    return;

  switch (xueshen->query("water"))
  {
    case 0:
      { msg = "微风吹过，"+name+"的参须在$N的眼前轻轻晃动。干了的话，想必功效一定大打折扣的吧！\n"; break; }
    case 1:
      { msg = name+"有点干了，哦，该淋一点水了。干了的话，想必功效一定大打折扣的吧！\n"; break; }
    case 2:
      { msg = name+"的颜色慢慢变得有些发黄。干了的话，想必功效一定大打折扣的吧！\n"; break; }
    case 3:
      { msg = name+"原来是白白胖胖的，现在好像瘪了下去。干了的话，想必功效一定大打折扣的吧！\n"; break; }
    case 4:
      { msg = name+"终于干枯了。\n"; xueshen->set("name","干"+name); break; }
    default:   //added by mon 8/31/97
      {  
        if(xueshen->query("water")>10 && random(10)==0) {
          message_vision(name+
	  "的根须皆以枯萎，参叶随风而起，化作了片片碎叶．．．\n"+
	  "再看时，只有一根淡黄的雪参干还留在$N手上。\n"
	  ,who);
	  xueshengan = new (__DIR__"xueshengan");
          xueshengan->move(who);
          destruct(xueshen);
	  return;
	}
      }
  }
  if(msg)message_vision (msg,who);
  xueshen->set("water",xueshen->query("water")+1);
  call_out ("need_water",random(50)+50,where);
}

int do_water (string arg)
{
  object xueshen = this_object();
  object who = this_player();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xueshen")
    return 0;

  if (xueshen->query("water") >= 5)
  {
    message_vision ("$N的泪水一滴滴流在"+name+"上。\n",who);
    return 1;
  }

  switch (random(5))
  {
    case 0:
      { msg = "$N口含清水，喷在"+name+"的参须上。\n"; break; }
    case 1:
      { msg = "$N将一点清水洒在"+name+"上。\n"; break; }
    case 2:
      { msg = "$N小心地捧起一点点露水，滴在"+name+"的参叶上。\n"; break; }
    case 3:
      { msg = "$N捧起从野外采来的晨露，洒在"+name+"的根须上。\n";break; }
    case 4:
      { msg = "$N用手指蘸着清水，一点点滴在"+name+"上。\n";break; }
  }
  message_vision (msg,who);
  message_vision (name+"重新舒展露出了参须，又变得雪白饱满了。\n",who);
  xueshen->set("water",0);
  return 1;
}
