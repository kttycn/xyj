#include <ansi.h> 
inherit ROOM;
int do_jump(string arg);
int do_volunteer();

void create ()
{
	set ("short", "奈何桥");
	set ("long", @LONG

这是一座仅数寸之宽，数长之长的石桥。上有寒风滚滚，下是
血浪滔滔。桥上左右无扶手，险峻之路如同匹练搭长江，桥下
之水阴气逼人，腥风扑鼻。
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bidouya",
		"north" : __DIR__"huangwai",
	]));
	set("hell", 1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shizhe" : 2,
	]));
	set("no_spells",1);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_volunteer", "volunteer");
}

int do_jump(string arg)
{       
	object me;
	me=this_player();

	if ( !arg || ((arg != "bridge") ))
		return notify_fail("你要往哪跳？往桥下跳准死．．．\n");
	message_vision("$N不顾一切的往桥下跳去．．．\n",me);
	me->move("/d/death/room10");
//	me->die();
	return 1;
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;

	if((string)me->query("family/family_name")!="阎罗地府")
		return notify_fail("您不是本门中人。\n");
	if(me->query("faith")>500)
		return notify_fail("您是本门大有名望之人，怎敢有劳您做看桥这样的杂务呢？\n");
	if(me->query("combat_exp")<50000 || me->query("daoxing")<50000)
		return notify_fail("守门是比较危险的事,你还是多做基本修行吧!\n");
	if (me->query_temp("in_guard"))
		return notify_fail("桥梁使者对你说:你专心守好桥头，别想打两份工。\n");
	if(time()-me->query("last_guard")<300)
		return notify_fail("桥梁使者对你说：你怎么这么快又要当班了？歇歇吧!\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--)
	{
		if (ob[i-1]->query_temp("in_guard"))
		return notify_fail("桥梁使者对你说：已经有人守奈何桥了，你一会再来吧！\n");
	}
	tell_object(me,"那好，就请你守一会儿奈何桥吧。\n");
	tell_room(environment(me),me->query("name")+"开始在奈何桥值守。\n");
	me->set("last_guard",time());
	me->set_temp("in_guard","1");
	me->save();
	remove_call_out("end_guard");
	call_out("end_guard",70,me);
	call_out("clone_meng",20,me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("in_guard"))
		return notify_fail("你正在守值，不能离开!\n");
	return ::valid_leave(me,dir);
}

void clone_meng(object me)
{
	object ob;
	tell_room(environment(me),"突然冲上来一伙鬼，看来他们想回阳间。\n");
	ob=new("/d/obj/npc/mengmian");
	ob->set("combat_exp",me->query("combat_exp"));
	ob->move("/d/death/naiheqiao");
	call_out("clone_meng", 20, me);
}

void end_guard(object me)
{
	object ob;
	int reward=me->query("combat_exp")/5000;
	me->delete("guard");
	me->add("faith",2+random(4));
	me->add("combat_exp",100+random(reward));
	me->add("potential",30+random(reward/4));
	me->delete_temp("in_guard");
	me->save();
	remove_call_out("clone_meng");
	tell_room(environment(me),me->query("name")+"在山门值守期已满。\n");

	tell_object(me,"你在山门值守期已满。\n");
	while(ob = present("dahan",environment(me)))
	destruct(ob);
}
