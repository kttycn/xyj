// 剑鞘.c 钢剑

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
//inherit HANDS;
inherit SWORD;

void create()
{
	set_name(YEL"剑鞘"NOR, ({ "xianyuan jianqiao", "jianqiao", "sword" }));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", YEL"这是千年古剑轩辕剑的剑鞘，笼罩在淡淡的金黄色光芒之中。
剑鞘系一种金黄色的金属制成，上包蚊皮，蚊皮上缀着明珠
数百颗，全用金黄色的天蚕丝交织而成，光华闪闪，巧夺天工。
传说由轩辕剑童幻化而成，危急时刻，你可以召唤(zhaohuan)
他来保护自己。\n"NOR);
		set("rigidity",100);
		set("no_put", 1);
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_drop", 1);
		set("no_get", YEL"你刚摸轩辕剑鞘，突然金黄色的光芒笼罩住你，你只觉得灵台清明，神清气爽。\n"NOR);
		set("no_give", "轩辕剑鞘哪能随便给人！\n");
		set("value", 300000);
/*		set("armor_prop/strength",3);
		set("armor_prop/courage",3);
		set("armor_prop/composure",3);
		set("armor_prop/intelligence",3);
		set("armor_prop/spirituality",3);
		set("armor_prop/constitution",3);
		set("armor_prop/personality",15);
		set("armor_prop/karma",3);*/
		set("material", "steel");
		set("wield_msg", "$N抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回身后。\n");
	}
	set("is_monitored",1);
	init_sword(50);
	setup();
}

