#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name(CYN"青索剑"NOR, ({ "qingsuo sword", "sword","qingsuo" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一柄细细的古剑,剑柄上刻有"+CYN"「青索」"NOR+"两字,剑身发出异样的青光，寒气逼人。\n");
		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
		set("no_put", 1);
		set("no_drop", "这么宝贵的东西，扔了多可惜呀！\n");
		set("no_give", "这可是神兵宝刃啊，哪能随便给人？\n");
		set("no_get", "你被剑刃上的寒气一激，一个哆嗦，手里一松，宝剑从手中滑落！\n");
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/xijian");
		set("material", "crimsonsteel");
		set("wield_msg", "只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
		set("unwield_msg", "$N左肩轻摇,"+MAG"紫郢剑"NOR+"便自行飞回鞘中。\n");
		set("weapon_prop/int", 3);
	}
	init_sword(120);
	set("is_monitored",1);
	setup();
}
