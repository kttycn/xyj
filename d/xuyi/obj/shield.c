// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("天龙盾", ({ "tianlong dun", "dun","shield" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 10000);
		set("material", "skin");
		set("armor_prop/armor", 50);
		set("armor_prop/dodge", -10);
	}
	setup();
}



