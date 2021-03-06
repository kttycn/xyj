inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set("short","正厅");
	set("long",@LONG
这这里是宗主府的正厅，地上铺着红色的地毯，大厅中间正上方，挂着
一块金匾，上题：宗延千秋。大厅两边站着几个美丽的女孩子，正在忙
碌着，见你进来，马上给你上来一杯香茗。
LONG);
	set("objects", ([
		__DIR__"npc/shinv": 2,
		__DIR__"npc/menghuoming": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"pianting1",
		"west"  : __DIR__"pianting2",
		"north"  : __DIR__"houting",
		"south"  : __DIR__"shufang",
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
	if(phase==10&&(!query("phoenix/start_jiangjing"))) jiang_jing(where);
	if(phase==13&&query("phoenix/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"【凤凰城】"HIC"凤"HIR"凰"HIY"(Chen xin)：现在开始演武，弟子们注意了。\n"+NOR,users());
	tell_object(where,"你听到凤凰的声音：道常无名朴。虽小，天下莫能臣。侯王若能守之，万物将自宾。\n");
	tell_object(where,"你听到凤凰的声音：天地相合，以降甘露，民莫之令而自均。\n");
	tell_object(where,"你听到凤凰的声音：始制有名，名亦既有，夫亦将知止，知止可以不殆。\n");
	tell_object(where,"你听到凤凰的声音：譬道之在天下，犹川谷之于江海。\n");
	tell_object(where,"........................................\n");
	set("phoenix/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"凤凰说道：大家休息吧。\n");
	set("phoenix/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("phoenix/start_jiangjing"))
		return notify_fail(HIC"凤"HIR"凰"HIY"还没有讲授武道。\n");

	if((string)me->query("family/family_name")!="凤凰星")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail(HIC"凤"HIR"凰"NOR"对你说道：你可以去找些其它的事情做了。\n");
	tell_object(me,"你不禁被"HIC"凤"HIR"凰"NOR"的武道修为深深吸引了。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("tenglong-finger",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的阴阳腾龙指进步了！\n");
	return 1;
}
