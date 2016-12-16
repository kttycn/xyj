//standroom.c used by weiqi...others may hate this format:D
//wuchang-e.c

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();

void create ()
{
	set ("short", "东武场");
	set ("long", @LONG

这是冰宫前的一块平地，供大雪山弟子练功之用。冰面极平，光
鉴照人。不过走在上面得小心点，雪山弟子也正是借此锻炼下盘
的稳固功夫。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-se",
		"north" : __DIR__"wuchang-ne",
		"west" : __DIR__"wuchang-c",
	]));
	
	set("objects", 
	([ //sizeof() == 1
                __DIR__"npc/tuying-zunzhe" : 1,
                __DIR__"npc/baixiang-zunzhe" : 1,
	]));


	set("outdoors", "xueshan");

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
	if(phase==24&&(!query("xueshan/start_jiangjing"))) jiang_jing(where);
	if(phase==27&&query("xueshan/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}
void jiang_jing(object where)
{
	message("channel:es",HIW+"【大雪山】白象尊者(Baixiang zunzhe):雪山弟子，现在开始讲授冰谷凝血功. \n"+NOR,users());
	tell_object(where,"冰谷凝血功可谓是明王创造出来的奇特的内功.\n");
	set("xueshan/start_jiangjing",1);
	set ("long", @LONG
        就见着小小的地方，有二十多个和你一个级别的
  小妖们在听白象尊者讲仙法.
LONG);
}
void finish_jing(object where)
{
	set("xueshan/start_jiangjing",0);
}
int do_hear()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("xueshan/start_jiangjing"))
		return notify_fail("白象尊者还没开始授法呢.\n");              
	if((string)me->query("family/family_name")!="大雪山")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail("你觉得自己不用再听讲了。\n");
	tell_object(me,"你在旁闻听，若有所悟，不禁眉花眼笑。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("ningxue-force",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的冰谷凝血功进步了！\n");
	return 1;
}                                                                    
