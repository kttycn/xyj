// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("Χȹ", ({ "wei qun", "qun" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��Χȹ���������Ƕ���Ľ�ӡ��\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 10000);
		set("armor_prop/armor", 10);
	}
	setup();
}
