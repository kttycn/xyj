// jinqiang.c
// updated 5-30-97 pickle


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
	set_name(HIW "��Ȫǹ" NOR, ({ "liquan spear","qiang","spear" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "gold");
		set("long", "�ഫ��ǹΪ����������ͨ��������覡�\n");
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
		set("unwield_msg", "$N��$n���뱳���С�\n");
	}
	init_spear(160);
	setup();
}

