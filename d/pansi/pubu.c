// pubu.c 
// by/lestat

inherit ROOM;
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_xianmei();

#include <ansi.h>
void create()
{
	set("short", "瀑布");
	set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见一
条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾弥漫，
望不到尽头。。。。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" :  __DIR__"tao_out",
	]));
	set("objects",([
		__DIR__"npc/qingxia" : 1,
	]));
	set("outdoors", "xiaoyao" );
	set("no_clean_up", 0);
	setup();
}
 
void init()
{
	object where=this_object();
	remove_call_out("check_time");
	check_time(where);
	add_action("do_xianmei","xianmei");
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object ob;
	int new_sen;
	ob = this_player();
	new_sen = random( ob->query("max_sen")*3 );
	if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
	if( !arg || arg=="" ) return 0;
	if( arg != "down" )
		return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
	tell_object(ob, HIR"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
	message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
	if((ob->query_skill("dodge",1)<30) && ob->query("family/family_name") != "盘丝洞"){
		ob->unconcious();
		ob->receive_damage("sen",new_sen);
		ob->move(__DIR__"yanfeng");
	}else{
		ob->move(__DIR__"yanfeng");
	}
	return 1;
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if((phase==45)&&(!query("pansi/start_hungry"))) feel_hungry(where);
	if((phase==48)&&query("pansi/start_hungry")) feel_full(where);
	call_out("check_time",40,where);
}

void feel_hungry(object where)
{
	message("channel:es",HIM+"【盘丝洞】青霞仙子(Qingxia xianzi)：妾身心情烦闷，不知那位爱徒能来安慰一下我啊。\n"+NOR,users());
	set("pansi/start_hungry",1);
}
void feel_full(object where)
{
	tell_object(where,"青霞仙子笑道：现在心情平静多了。\n");
	set("pansi/start_hungry",0);
}
int do_xianmei()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("pansi/start_hungry"))
		return notify_fail("青霞仙子白了你一眼，道：我心情好的很！走远点。\n");
	if((string)me->query("family/family_name")!="盘丝洞")
		return notify_fail("青霞仙子说道：我心情烦不烦，关你什么事！\n");
 	if(me->query("faith")>800)
		return notify_fail("这些事情就让其它弟子来做吧。\n");
	tell_object(me,"你不停的安慰着青霞仙子，直把青霞仙子说道转忧为喜。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("pansi-dafa",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的盘丝大法进步了！\n");
	return 1;
}
