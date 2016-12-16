#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL "战甲" NOR, ({ "zhan jia", "jia" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("no_drop","宝物是扔/卖不了的，也不能给别人。");
		set("value", 50000);
		set("material", "gold");
		set("armor_prop/armor", 100);
		set("armor_prop/dodge", -2);
	}
	setup();
}


