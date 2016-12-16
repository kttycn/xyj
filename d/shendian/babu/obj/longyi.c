//copy from bone by repoo

#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"龙神"+HIB"之翼"NOR, ({HIR"long yi"NOR,"yi"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一对龙神背上的翅膀。\n");
		set("unit", "对");
		set("material", "cloth");
		set("value", 0);
		set("replace_file", "/d/obj/armor/tenjia");
		set("wear_msg", "只听「刷」的一声，$N从背包中取出一件$n披在身上。\n");
//		set("remove_msg", "$N将背上的$n拿了下来，折成一团，放入包里。\n");
		set("unequip_msg", "$N将背上的$n拿了下来，折成一团，放入包里。\n");
		set("armor_prop/armor", 150);
		set("armor_prop/dodge", 100);
	}
	set("is_monitored",1);
	setup();
}
void init()
{
	check_owner();
}

