//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "大厅");
  set ("long", @LONG

一个大如宫殿的大厅，厅的中间摆满了石桌石椅，厅的石壁上
挂着兽油铜灯。大厅的西面传来烤肉的香味，东南有一通向里
面的通道，往东北方向有一石廊。这个地方也是传授杀人越货
的地方。你只要来(hear)，就可以了。

LONG);

  set("exits", ([
        "west"   : __DIR__"canting",
        "northeast"   : __DIR__"shilang",
        "southeast"   : __DIR__"woshi",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
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
	if(phase==94&&(!query("kusong/start_jiangjing"))) jiang_jing(where);
	if(phase==97&&query("kusong/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIW+"【枯松涧火云洞】牛魔王(Niumo wang)：现在开始传授我们火云洞的心法。\n"+NOR,users());
	tell_object(where,"牛魔王说道：这杀人啊，一定要心狠手毒，决不留情。\n");
	tell_object(where,"要六亲不认，更不能拖泥带水。\n");
	tell_object(where,"取经人的肉，听说吃一块就能长生不死，你们要快点给我弄来偿偿。\n");

	tell_object(where,"要点是：默默潜伏，突然出击，致人于死地而后快。\n");
	set("kusong/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"牛魔王说道：回去试试本王的方法如何。\n");
	set("kusong/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("kusong/start_jiangjing"))
		return notify_fail("牛魔王还没开始传授心法呢。\n");

	if((string)me->query("family/family_name")!="火云洞")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail("杀人越货这种小事，你已经是牛魔王的师傅了。\n");
	tell_object(me,"你在旁边听着，听着。不禁想起了杀人的快感。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("pingtian-dafa",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的平天大法进步了！\n");
	return 1;
}


