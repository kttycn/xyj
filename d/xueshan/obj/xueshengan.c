#include <ansi.h>
inherit ITEM;

int do_eat(string);
void destroy();
void init();

void init()
{
	if(this_player()==environment())
		add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"千年雪参干"NOR, ({"shen gan","xueshen gan", "gan"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", HIY"这是一根淡黄色的千年雪参干，根须皆以枯萎。乃新鲜的千年雪参干枯后形成，功效大打折扣。\n"NOR);
		set("value", 900000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if ((string)environment(me)->query("short")=="禹王林" )
		return notify_fail("这里这么危险还吃什么东西啊？\n");

	me->set("food", (int)me->max_food_capacity());
	me->add_maximum_mana(25);
	me->add_maximum_force(25);
	message_vision(YEL"$N小心地捏碎雪参干，缓缓放入口中。$N的脸色瞬时变得雪白，正疑惑时，$N的脸色又逐渐恢复了红润。\n" NOR, me,);
//	me->unconcious();
	destruct(this_object());
	return 1;
}


