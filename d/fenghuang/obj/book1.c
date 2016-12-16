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
	set_name(HIM"神"NOR"书", ({ "shen shu","shu", }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("material", "stone");
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 
	int neili_lost;

	if (!(arg=="book" || arg == "shu"))
		return 0;
	if (me->is_busy()) {
		write("你现在正忙着呢。\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("你无法在战斗中专心下来研读新知！\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "凤凰星")
	{
		write("你不是凤凰战士，不能读！\n");
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
	message("vision", me->name() + "你从书中学到一些东西。\n", environment(me), me);
	if( (int)me->query("sen") < 5 ) {
		write("你现在过于疲倦，无法专心下来研读新知。\n");
		return 1;
	}
	if( me->query_skill("literate", 1) > 80){
		write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
		return 1;
	}
	me->receive_damage("sen", 5);
	me->set("force",(int)me->query("force")-neili_lost);
	me->improve_skill("literate", (int)me->query_skill("literate", 1)/2+random(100));
	write("你从书中学到一些东西。\n");
	return 1;
}

