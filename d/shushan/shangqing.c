//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short","上清宫");
  set ("long", @LONG

这是蜀山剑圣修炼的地方，中央有一个香炉，香气充满了
整个房间。
LONG);
   set("exits", ([      
       "south" : __DIR__"zushi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiansheng" : 1,
      __DIR__"npc/jiantong" : 2,
       ]));
  setup();
}

void init()
{
	object where=this_object();

	remove_call_out("check_time");
	check_time(where);
	add_action("do_hear","hear");
}
void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];

	int phase=((int)(t%120));
	if(phase==38&&(!query("shushan/start_jiangjing"))) jiang_jing(where);
	if(phase==41&&query("shushan/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"【蜀山剑派】静虚老祖(Shushan jiansheng)：现在开始讲剑道，弟子们注意了。\n"+NOR,users());
	tell_object(where,"你听到静虚老祖的声音：天下皆谓我道大，似不肖。夫唯大，故似不肖。若肖，久矣其细也夫！\n");
	tell_object(where,"你听到静虚老祖的声音：我有三宝，持而保之。一曰慈，二曰俭，三曰不敢为天下先。\n");
	tell_object(where,"你听到静虚老祖的声音：慈故能勇；俭故能广；不敢为天下先，故能成器长。\n");
	tell_object(where,"你听到静虚老祖的声音：今舍慈且勇；舍俭且广；舍后且先；死矣！\n");
	tell_object(where,"你听到静虚老祖的声音：夫慈以战则胜，以守则固。天将救之，以慈卫之。\n");
	tell_object(where,"........................................\n");
	set("shushan/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"静虚老祖说道：大家休息吧。\n");
	set("shushan/start_jiangjing",0);
}

int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("shushan/start_jiangjing"))
		return notify_fail("静虚老祖还没有说道。\n");

	if((string)me->query("family/family_name")!="蜀山剑派")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail("静虚老祖对你说道：你可以去找些其它的事情做了。\n");
	tell_object(me,"你不禁被静虚老祖的讲道深深吸引了。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("taoism",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的天师仙法进步了！\n");
	return 1;
}
