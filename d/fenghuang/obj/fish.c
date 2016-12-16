#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"金色鲤鱼"NOR, ({"gloden fish", "fish","yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "尾");
		set("long", "这是一尾极为罕见的金色鲤鱼。\n");
		set("value", 2500);
	}
	setup();
}

int do_eat(string arg)
{      
	int force_limit, neili_limit ;
	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_force");
        
	if (!id(arg)||(arg!="fish"&&arg!="golden fish"))
		return notify_fail("你要吃什么？\n");

	if ((string)me->query("family/family_name") == "凤凰星")
	{
		if ( neili_limit <= force_limit )         
		{
			me->add("force",random(200));
			message_vision(HIY "$N吃下一尾金色鲤鱼，感到满口生津。.\n" NOR, this_player());
		}
		else
			message_vision(HIY "$N吃下一尾金色鲤鱼，但是好象没什么用.\n" NOR,  this_player());
	}
	else {
		me->receive_damage("sen", 200);
		me->receive_damage("kee", 200);
		write(HIR "你中毒了，"HIB"感到欲火焚身很想和人........！\n"+
		HIW "一个声音笑到..哈哈！..哈哈！..哈哈！\n" NOR);
		return 1;
	}        
	destruct(this_object());
	return 1;
}
