#include <weapon.h>

inherit BOW; 

void create()
{
	set_name("Ǭ����", ({"qiankun gong", "qiankungong", "bow", "gong", "qiankun"}));
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	    set("long","Ǭ�������Ǻ��൱����������֮������\n");
		set("rigidity", 5);
		set("unit", "��");
		set("value", 30000);
		set("wield_msg", "$Nץ��һ��$n���������е�������\n");
		set("material", "steel");
	}

	init_bow(1);
	setup();
}

