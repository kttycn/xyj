#include <ansi.h>
inherit ITEM;
void create()
{
	set_name( HIW "ʯʨ"NOR, ({ "shi shi" }) );
	set_weight(50000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "stone");
	}
	setup();
}

