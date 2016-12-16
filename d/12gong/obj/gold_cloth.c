// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
//#include "chk_owner.c"

void create()
{
	set_name(HIY"黄金圣甲"NOR, ({ "huangjin shengjia", "armor" }) );
	set("long", "这是一件由战神用五洲之金、七海之水精心打制而成的铠甲，份量极轻，\n却可挡住任何利器的攻击。\n");
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("no_sell",1);
		set("no_give",1);
		set("no_drop",1);
		set("no_get",1);
		set("no_put",1);
		set("value",10);
		set("wear_msg", HIY"只听「哗」的一声，$N从背包中取出一件$n"HIY"披在身上，全身发出淡淡的金光。\n"NOR);
		set("remove_msg", CYN"$N将$n"CYN"从身上脱了下来，仔细折成一团，放入包里，金色光芒顿时暗了下去。\n"NOR);
		set("material", "steel");
		set("armor_prop/armor",120);
	}
	setup();
}
int query_autoload() { return 1; }
