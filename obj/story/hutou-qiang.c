//yitianjian.c
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
    set_name(HIY"虎头枪"NOR, ({ "hutou qiang", "qiang","spear" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "杆");
        	set("value", 20000);
//        	set("no_drop", "1");
        	set("material", "blacksteel");
        	set("long", "这是天下第一枪，秦琼秦叔宝曾用它荡平天下。\n");
        	set("wield_msg",HIC"直如矫龙吞水，长虹冠日一般，$n"HIC"已在$N手中，天地为之变色。\n"NOR);
        	set("unwield_msg", HIC"$N将$n收回枪匣，华光顿敛，天地间只闻龙鸣。\n"NOR);
	}
	init_spear(180);
	set("is_monitored",1);
	setup();
}
