#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
	set_name(HIW "ƒ‹¡ø∆¡’œ"NOR, ({ "shell lace", "lace" }));
	set("weight", 500);
	if (clonep())                
		set_default_object(__FILE__);
	else {
		set("unit", "¥Æ");
		set("value", 50000);
		set("armor_prop/armor", 30);
	}
	setup();
}       

