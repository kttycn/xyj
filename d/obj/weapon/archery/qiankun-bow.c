#include <weapon.h>

inherit BOW; 

void create()
{
	set_name("乾坤弓", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	    set("long","乾坤弓乃是后羿当年射日所用之弓。。\n");
		set("rigidity", 5);
		set("unit", "张");
		set("value", 30000);
		set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
		set("material", "steel");
	}

	init_bow(1);
	setup();
}

