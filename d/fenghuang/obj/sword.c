// ZHANGM 1999/12/18 
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC "����"NOR, ({"sword", "jian"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ɫ�Ĺ⽣������͸������������\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", HIW "ֻ���׹�һ����$N�����ж���һ������ɫ��$n��\n"NOR);
		set("unwield_msg", HIW "$N����һ�$n������Ӱ��\n"NOR);
	}
	init_sword(40);
	setup();
}

