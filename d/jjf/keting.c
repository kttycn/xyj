// Room: /d/jjf/keting.c

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "正厅");
  set ("long", @LONG

厅门口挂着一块横匾，上书「铁面无私」四个大字，看来还是御笔
亲书。几个家将站立两旁。秦将军坐在当中的太师椅上，不怒自威。
看到你进来，他对你点头笑了笑。也许是因为没有人说话，厅上的
气氛很严肃。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"stone_road",
  "north" : __DIR__"front_yard2",
  "west" : __DIR__"side_keting",
  "east" : __DIR__"dining_room",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/jiajiang" : 2,
  __DIR__"npc/qinqiong" : 1,
]));
  set("valid_startroom", 1);

  setup();

  call_other("/obj/board/jjf_b", "???");
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
	if(phase==59&&(!query("fighter/start_yanwu"))) jiang_jing(where);
	if(phase==62&&query("fighter/start_yanwu")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"【将军府】秦琼(Qin qiong)：现在开始演武，弟子们注意了。\n"+NOR,users());
	tell_object(where,"你听到秦琼的声音：昔之善战者，先为不可胜，以待敌之可胜。不可胜在己，可胜在敌。\n");
	tell_object(where,"你听到秦琼的声音：故善战者，能为不可胜，不能使敌之必可胜。\n");
	tell_object(where,"你听到秦琼的声音：故曰：胜可知，而不可为。不可胜者，守也；可胜者，攻也。\n");
	tell_object(where,"你听到秦琼的声音：守则不足，攻则有余。善守者藏于九地之下，善攻者动于九天之上，故能自保而全胜也。\n");
	tell_object(where,"........................................\n");
	set("fighter/start_yanwu",1);
}
void finish_jing(object where)
{
	tell_object(where,"秦琼说道：大家休息吧。\n");
	set("fighter/start_yanwu",0);
}

int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(!query("fighter/start_yanwu"))
		return notify_fail("秦琼还没有说道。\n");

	if((string)me->query("family/family_name")!="将军府")
		return notify_fail("外派弟子不得来听讲。\n");
	if(me->query("faith")>800)
		return notify_fail("秦琼对你说道：你可以去找些其它的事情做了。\n");
	tell_object(me,"你不禁被秦琼的武道深深吸引了。\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("bawang-qiang",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"你觉得你的霸王枪法进步了！\n");
	return 1;
}
