// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name(HIY"������������"NOR, ({"busi pifeng", "pifeng", "cloth" }));
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ���÷�������ƶ��ɵ����硣\n");
		set("material", "crimsonsteel");
		set("unit", "��");
		set("value", 0);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 5);
		set("armor_prop/spells", 10);
	}
	setup();
}


