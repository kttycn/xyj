inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}
void create()
{
	set_name(HIM"凤凰女神"NOR"像", ({ "nvshen xiang","xiang", }));
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "樽");
		set("material", "stone");
		set("no_get", "这样东西你搬不动，你还是别费力了。\n");
		set("long",
	"这是一樽用紫水晶精心雕成的凤凰女神像。\n"
	"看起来栩栩如生，女神宛若欲随风而去。\n", );
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel, neili_lost, busy;

	if (!(arg=="nvshen xiang" || arg == "xiang"))
	return 0;
	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "凤凰星"
	&& !(int)me->query("xmark/学员"))
	     {
	     write("你还不赶紧跑，要不被宗主府的人逮到了！\n");
		return 1;
	}
	if (!id(arg)) { 
		write("你要读什么？\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) ){
		write("你是个文盲，先学点文化(literate)吧。\n");
		return 1;
	}
	busy = 1;
	pxlevel = me->query_skill("dodge", 1);
	if(pxlevel > 140) {
		neili_lost = 3;
		busy = 5;
	} else if(pxlevel > 100) {
		neili_lost = 3;
		busy = 3;
	} else if(pxlevel > 50)
		neili_lost = 3;
	else neili_lost = 0;

	if( (int)me->query("force") < neili_lost && pxlevel > 50 ) {
		write("你内力不够，无法钻研这么高深的武功。\n");
		return 1;
	}
	if( (int)me->query("sen") < 15 ) {
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("你的实战经验不足，再怎么读也没用。\n");
		return 1;
	}
	if( pxlevel > 180){
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}
	message("vision", me->name() + "你从女神的姿态中悟出身法的奥妙。\n", environment(me), me);
	me->receive_damage("sen", 15);
	me->set("force",(int)me->query("force")-neili_lost);
	me->start_busy(busy);
	if (me->query("food") >= pxlevel) me->add("food",-pxlevel/10);
	else me->set("food", 0);

	if (me->query("water") >= pxlevel) me->add("water",-pxlevel/10);
	else me->set("water", 0);
	me->improve_skill("dodge", (int)me->query_skill("literate", 1)/2+random(10));
	write("你从女神的姿态中悟出身法的奥妙。\n");
	return 1;
}
