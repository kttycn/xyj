#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("巨钟", ({ "giant bell" }) );
	set_weight(600000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "铸于何年已不可考究，口沿八唇，上铸一些看不懂的图形，好象是
星际图，重一万一千斤\n");
		set("value", 3);
		set("material", "iron");
	}
	init_hammer(650);
	setup();
}
