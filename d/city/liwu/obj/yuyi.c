// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIW"羽衣"NOR, ({ "yu yi", "yi" }));
	set("long", "这是一件由七彩羽毛制成的丝衣，虽然极薄，却特别暖活。\n");
	set_weight(0);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("wear_msg", HIW "只听「刷」的一声，$N展开一件白色的羽衣身上。\n" NOR);
		set("remove_msg", HIW "$N将羽衣从身上脱了下来，折叠成小小的一团。\n" NOR);
		set("armor_prop/armor", 200);
		set("armor_prop/dodge", 50);
		set("replace_file", "/d/obj/cloth/bai");
		set("armor_prop/personality", 10);
		set("value", 1000000);
		set("female_only", 1);
	}
	set("no_sell",1);
	set("no_give", 1);
	set("no_get", 1);
	set("no_put",1);
	set("is_monitored",1);
	setup();
}

void init()
{
	cloth::init();
	unique::init();
}
