// thousand.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(HIR"һ��Ԫ��Ӱ��"NOR, ({"renminbi", "rmb money"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "rmb");
		set("long", "һ����ֵΪһ��Ԫ����Ӱ�ң���ֵʮ���ƽ�\n");
		set("unit", "��");
		set("base_value", 100000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

