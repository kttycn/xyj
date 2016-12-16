#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIC"青龙偃月刀"NOR, ({"dragon blade", "dao","blade"}));
	set_weight(22000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "昔日武圣关云长之随身兵器，重八十二斤，锋利无比。据说还关系到绝世武功「倾国倾城」的秘密。\n");
		set("value", 25);
		set("wield_msg", "$N「唰」地一声飞出一把$n握在手中，刹时间$N的脸色现出红光，转瞬即逝。\n");
		set("unwield_msg", "$N冷哼一声，$n转眼已经不见了。\n");
		set("weapon_prop/courage", 15);
	}
	init_blade(160);
	setup();
}
