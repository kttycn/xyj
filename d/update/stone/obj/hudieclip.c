// hudieclip.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
	set_name(HIG"蝴蝶玉夹"NOR, ({"hudie jia", "hudie clip","clip"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", HIG"那蝴蝶玉夹，样式古朴，发出一片淡绿光华，两眼却迸出
两点红光，栩栩如生，一看就知道是一件价值连城的宝物。\n"NOR);
		set("value", 10000000);
		set("material", "plant");
		set_weight(10);
		set("armor_prop/armor", 30);
		set("armor_prop/personality", 5);
		set("wear_msg", "$N轻轻地把一只$n扣在左鬓边，恰似一只大蝶落在美人云鬓。\n");
		set("unequip_msg", "$N轻轻地把$n从左鬓边摘了下来。\n");
		set("female_only", "就是女人家的饰物，你一个大男人也想戴，羞不羞？");
	}
	set("is_monitored",1);
	setup();
}
