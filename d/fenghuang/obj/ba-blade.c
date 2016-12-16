#include <weapon.h>
#include <ansi.h>
//inherit SSERVER;
inherit BLADE;

void create()
{
	set_name( HIY"霸"HIM"者"HIW"之"HIC"刃"NOR,({"bazhe dao","blade","dao"}) );
	set("long",
		"由孤魂野鬼的怨气所打造出的，神兵利器。据说拥有强大的魔性。"
	);
	set("no_drop","宝物是扔不了的，也不能给别人。");
	set("no_give",1);
	set("no_put",1);
	set("no_sell",1);
	set_weight(500);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("value",100000);           
		set("material", "gold");
	}
	init_blade(100);
	setup();        
}

