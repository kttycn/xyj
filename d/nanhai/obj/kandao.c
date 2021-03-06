#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("砍刀", ({"kan dao"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 50);
		set("material", "steel");
		set("wield_msg", "$N把$n握在手中．\n");
	}
	init_blade(10);
	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	object me=this_player(), weapon;

	if(!me->query("nanhai/zhulan"))
		return notify_fail("您来干什么？\n");
	if(!arg || arg != "bamboo" )
		return notify_fail("你要砍什么？\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "kan dao")
		return notify_fail("你不拿着砍刀怎么砍竹子？\n");

	if(environment(me)->query("short")!="紫竹林")
		return notify_fail("您在这儿乱砍什么？\n");

	if((int)me->query("kee") <80)
		return notify_fail("你太累了，歇歇吧！\n");

	message_vision("$N走到一棵紫竹跟前，抡起砍刀，开始砍竹子。\n", me);
	me->start_busy(8);
	call_out("kan1",2,me);
	call_out("kan2",4,me);
	call_out("kan3",6,me);
	call_out("finish_kan",8,me);

   return 1;
}

void kan1(object me)
{
	message_vision("看来竹子质地坚硬,半天也只砍开一点!\n");
	message_vision("$N擦了擦头上的汗水，继续干了起来。\n", me);
}

void kan2(object me)
{
	message_vision("$N歇了一会儿，望着面前快断的翠竹，微微一笑。\n", me);

}

void kan3(object me)
{
	message_vision("快要结束了，$N顾不得擦头上的汗水，迅速挥动着砍刀。\n", me);
}

void finish_kan(object me)
{
	object where=environment(me);

	message_vision("$N抹了一把汗，得意的看着砍下的翠竹笑了笑。\n", me);
	me->receive_damage("kee", 60);
	me->delete("nanhai/zhulan");
	tell_object(me,"你觉得在劳累之余也有所收获。\n");
	tell_object(me,"你的经验和扑击格斗之术提高了\n");
	me->improve_skill("unarmed",random(me->query("int")),1);
	me->add("faith",1);
	me->add("combat_exp",9);
	me->add("potential",3);
	this_object()->move(find_living("daza xiaoseng"));
}
