#include <weapon.h>

inherit GUN;

void create()
{
	set_name("����ǹ", ({"gun" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ǹ���ƺ������޴�\n");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_gun(20);
	setup();
}


