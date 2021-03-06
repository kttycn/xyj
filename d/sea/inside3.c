//modified by sgzl for dntg/donghai quest

inherit ROOM;
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_serve();

void create ()
{
	set ("short", "龙宫正殿");
	set ("long", @LONG

正殿之上悬一明珠，把诺大一殿照得通亮。两旁桌椅玉石打造而成，　　
当中还嵌着无数珠宝。两边墙上挂了两幅画，看起来相当的陈旧。　　　
南北是两座偏殿。如果龙王累了，你还可以给他服务一下。(serve)

LONG);

	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"inside2.c",
		"east" : __DIR__"inside4",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/longwang" : 1,
	]));
	set("water", 1);

	setup();
}

int valid_leave()
{
	if(present("dao kan dao", this_player())
	|| present("jiu gu cha", this_player())
	|| present("mei hua chui", this_player())
	|| present("hua gan ji", this_player()))
		return notify_fail("龙宫至宝不能随便带走！\n");
	return ::valid_leave();
}

void init()
{
	object where=this_object();

	remove_call_out("check_time");
	check_time(where);
	add_action("do_serve","serve");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if((phase==66)&&(!query("dragon/start_hungry"))) feel_hungry(where);
	if((phase==69)&&query("dragon/start_hungry")) feel_full(where);
	call_out("check_time",40,where);
}

void feel_hungry(object where)
{
	message("channel:es",HIY+"【东海龙宫】敖广(Ao guang)：朕累了，有人来服务吗？\n"+NOR,users());
	set("dragon/start_hungry",1);
}
void feel_full(object where)
{
	tell_object(where,"东海龙王笑道：很好，很好。\n");
	set("dragon/start_hungry",0);
}
int do_serve()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("dragon/start_hungry"))
		return notify_fail("东海龙王道：我现在不累！\n");
	if((string)me->query("family/family_name")!="东海龙宫")
		return notify_fail("东海龙王道：不敢劳您大驾！\n");
	if(me->query("faith")>800 )
		return notify_fail("您是我们龙宫有身份的人，这样的事就让小辈们做吧。\n");
	tell_object(me,"你给龙王又是捶，又是掐的，把龙王服务的直叫痛快！\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("seashentong",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的碧海神通进步了！\n");
	return 1;
}
