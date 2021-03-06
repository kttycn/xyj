//Cracked by Roath
#include <ansi.h>
inherit ROOM;
void init();
void dance(object where);
void finish_dance(object where);
void check_time(object where);
int do_enjoy();

void create ()
{
	set ("short", "长思馆");
	set ("long", @LONG

房中珠帘低垂，案上炉中点着一束沉香，轻烟袅绕。当地放著一张花梨大
理石大案，案上堆著各种名人法帖，并十数方宝砚，各色笔筒；那一边设
著斗大的一个汝窑花囊，插著满满的水晶球的白菊花。书案正中撂着几张
绢纸，字迹娟秀，似是嫦娥百般无赖之中所涂。
LONG);

	set("item_desc", ([ /* sizeof() == 1 */
		"paper" : "纸上反反复复地写着一句话：天不老，情难绝，心似双丝网，中有千千结。",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/change.c" : 1,
		"/d/obj/flower/juhua.c" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"huilang.c",
	]));

	setup();
}

void init()
{
	object where=this_object();
	remove_call_out("check_time");        
	check_time(where);
	add_action("do_enjoy","enjoy");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if(phase==3&&(!query("moon/start_dance"))) dance(where);
	if(phase==6&&query("moon/start_dance")) finish_dance(where);
	call_out("check_time",40,where);
}
void dance(object where)
{
	message("channel:es",HIM+"【月宫】嫦娥(Chang e)：卯时整,该练舞了。\n"+NOR,users());
	tell_object(where,"嫦娥轻提纱裙，缓缓步入舞池,真个是：\n");
	tell_object(where,"天地为之变色，神鬼为之动容！\n");
	tell_object(where,"此舞只为天上有，人间能有几回见?\n");
	set("moon/start_dance",1);
	set ("long", @LONG
这里是嫦娥的居所，也是仙子练舞的地方，现在周围稀稀拉拉坐着几位仙子,
被嫦娥的仙姿所折服，正欣赏(enjoy)的如醉如痴.
LONG);
}

void finish_dance(object where)
{
	tell_object(where,"嫦娥走出舞池，轻言道：今天功课到此结束。\n");
	set("moon/start_dance",0);
	set ("long", @LONG
房中珠帘低垂，案上炉中点着一束沉香，轻烟袅绕。当地放著一张花梨大
理石大案，案上堆著各种名人法帖，并十数方宝砚，各色笔筒；那一边设
著斗大的一个汝窑花囊，插著满满的水晶球的白菊花。书案正中撂着几张
绢纸(paper)，字迹娟秀，似是嫦娥百般无赖之中所涂。
LONG);
}

int do_enjoy()
{
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("moon/start_dance"))
		return notify_fail("嫦娥还没练舞呢，你想欣赏什么?\n");
	if((string)me->query("family/family_name")!="月宫")
		return notify_fail("外派弟子不得来欣赏!\n");
	if(me->query("faith")>800)
		return notify_fail("你的修为已经足够高，不用再赏舞了。\n");      
	tell_object(me,"你在旁闻听，若有所悟，不禁眉花眼笑。\n");
	me->add("faith",1);
	me->start_busy(4+random(1));
	me->improve_skill("moondance",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的冷月凝香舞进步了！\n");
	return 1;       
}

