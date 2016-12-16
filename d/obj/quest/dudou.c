inherit ITEM;
#include "task.h"

void create()
{
	set_name("¶Ç¶µ", ({"du dou", "dou"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ºìº¢¶ù´©µÄ¶Ç¶µ¡£\n");
		set("unit", "¼þ");
		set("owner_name","ºìº¢¶ù");
		set("owner_id","honghai er");
	}
}
