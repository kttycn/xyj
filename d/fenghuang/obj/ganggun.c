#include <weapon.h>

inherit STICK;

void create()
{
	set_name("�ֹ�", ({ "ganggun", "gun" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�������ƳɵĹ��ӣ��ƺ���������\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}

	init_stick(20);
	setup();
}

