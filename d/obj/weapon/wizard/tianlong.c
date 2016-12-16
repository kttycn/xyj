#include <weapon.h>

inherit HALBERD;

void create()
{
	set_name("天龙戟", ({ "tianlong ji", "halberd" ,"ji"}));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "大圣国师王菩萨成名兵器。\n");
		set("value", 20000);
		set("material", "blacksteel");
	}
	set("wield_msg", "寒光一现，只见$N手上闪出一把雪亮的$n。　\n") ;   
	set("unwield_msg", "$N放下手中的$n。\n");
	init_halberd(140);
	setup();
}

