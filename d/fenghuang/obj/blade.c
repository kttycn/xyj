// ZHANGM 1999/12/18 
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(RED "������"NOR, ({"dao", "blade"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ɫ�������䵶������͸��һ��ɱ����\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", HIR "ֻ�����һ����$N�����ж���һ������ɫ��$n��\n"NOR);
		set("unwield_msg", HIY "$N����һ�$n������Ӱ��\n"NOR);
	}
	init_blade(40);
	setup();
}

