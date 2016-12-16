inherit ROOM;
void create()
{
	set("short","厨房");
	set("long",@LONG

　　这里当然都是狐狸们喜欢的事物了，狐狸们
平时也喜欢干些偷鸡摸狗的事情，但是这些想升天的
狐狸们好象更喜欢吃活人，来增加他们的修行。不信
的话，你来做（make）一个人头试试。

LONG);
	set("exits", ([
		"south" : __DIR__"nei1",
	]));
	set("objects", ([
		"/d/obj/misc/head":1,
		"/d/qujing/xuanyuan/obj/renxue":2,
		"/d/obj/misc/head2":1,
		"/d/obj/food/jitui":3,
	]));
	setup();
}


void init()
{
	add_action("do_make","make");
}
int do_make()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if((string)me->query("family/family_name")!="轩辕古墓")
		return notify_fail("你不是我们 轩辕古墓的，用不着来我们这做人头\n");
	if(me->query("faith")>200||me->query("daoxing")>100000)
		return notify_fail("您不需要在这种地方干活了．\n");
	tell_object(me,"你抓起一个活人，......三下五除二，顿时一个头颅出现了。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->add("combat_exp",15);
	me->add("daoxing",15);
	me->add("potential",4);
	me->add("bellicosity",1);
	me->improve_skill("spells",2);
	me->receive_damage("kee",50);
	message_vision("$N觉得法术进步了!\n",me);
	("/d/obj/misc/head")->move(me);
	return 1;
}
