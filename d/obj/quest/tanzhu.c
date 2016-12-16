inherit ITEM;
#include "task.h"

void create()
{
	set_name("µ¯Öé", ({"tan zhu", "zhu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÁúÉÙÒ¯Ğ¡Ê±ºòÍæµÄµ¯Öé¡£\n");
		set("unit", "¿Å");
		set("owner_name","ÁúÉÙÒ¯");
		set("owner_id","long shaoye");
	}
}

