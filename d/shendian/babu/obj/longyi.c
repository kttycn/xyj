//copy from bone by repoo

#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"����"+HIB"֮��"NOR, ({HIR"long yi"NOR,"yi"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ϵĳ��\n");
		set("unit", "��");
		set("material", "cloth");
		set("value", 0);
		set("replace_file", "/d/obj/armor/tenjia");
		set("wear_msg", "ֻ����ˢ����һ����$N�ӱ�����ȡ��һ��$n�������ϡ�\n");
//		set("remove_msg", "$N�����ϵ�$n�����������۳�һ�ţ�������\n");
		set("unequip_msg", "$N�����ϵ�$n�����������۳�һ�ţ�������\n");
		set("armor_prop/armor", 150);
		set("armor_prop/dodge", 100);
	}
	set("is_monitored",1);
	setup();
}
void init()
{
	check_owner();
}

