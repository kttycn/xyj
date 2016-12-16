#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白丝袍", ({"baipao", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件白色的丝绸软袍，裁剪精细，着手柔软细腻，看起来别有风姿．\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 800);
		set("armor_prop/armor", 25);
	}
	setup();
}

