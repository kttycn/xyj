#include <weapon.h>

inherit FORK;

void create()
{
	set_name("������", ({ "moon fork", "fork" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���൱Ư�����������������������㣬�����������ĺܡ�\n");
		set("value", 0);
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
		set("no_sell",1);
	}
	init_fork(165);
	setup();
}
