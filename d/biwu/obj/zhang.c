// gangzhang.c 钢杖

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit HANDS;

void create()
{
	set_name(HIY"神杖"NOR, ({ "shenstaff" }));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根象征正义的神杖，上面刻着“自古今来，邪不胜正”。你可以召唤(alert)护卫来保护自己。\n");
		set("rigidity",100);
		set("no_put", 1);
		set("no_sell", 1);
		set("no_drop", 1);
		set("value", 300000);
		set("armor_prop/strength",3);
		set("armor_prop/courage",3);
		set("armor_prop/composure",3);
		set("armor_prop/intelligence",3);
		set("armor_prop/spirituality",3);
		set("armor_prop/constitution",3);
		set("armor_prop/personality",15);
		set("armor_prop/karma",3);
		set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	set("is_monitored",1);
	setup();
}
