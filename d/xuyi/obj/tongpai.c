#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(CYN "ͭ��" NOR, ({ "tongpai", "pai" }));
	set("long", @LONG
����һ��������ͭ�ƣ�����д�š��������ơ��ĸ�С�֡��
LONG);
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "ͭ");
		set("armor_prop/armor", 1);
	}
	setup();
}

