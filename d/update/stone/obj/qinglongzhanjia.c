#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_UNIQUE;

void create()
{
	set_name(HIC "青龙战甲" NOR, ({ "qinglong zhanjia", "zhanjia" ,"armor"}) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		 set("long", HIC"一件用东方圣兽青龙之鳞所制的战甲，寒光闪闪。\n"NOR);
    		set("material", "gold");
    		set("unit", "件");
    		set("value", 0);
    		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
    		set("no_put", "这青龙战甲装不进容器里去。\n");
    		set("no_drop", "这么稀世难求的宝甲圣衣，扔了多可惜呀！\n");
    		set("no_give", "这可是宝甲圣衣啊，哪能随便给人？\n");
    		set("no_get", HIC"你刚摸到青龙战甲,突然青龙战甲中现出青色的东方圣兽青龙，张牙舞爪，你不由胆战心惊。\n"NOR);
    		set("armor_prop/armor", 100);//参考锦衣披风60set("unit", "件");
		set("armor_prop/dodge", -2);
	}
	set("is_monitored",1);
	setup();
}


