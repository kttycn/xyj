#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIR "凤凰军校毕业证"NOR, ({ "biye zheng" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 2);
		set("material", "paper");
	}
	setup();
}
int query_autoload()
{
	return 1;
}

