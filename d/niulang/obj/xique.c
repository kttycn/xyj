//By canoe 2001.03.26
// �ܳԣ�����
#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIC"ϲȵ"NOR, ({"xique"}));
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һֻ�ܺ��������ϲȵ��\n");
		set("unit", "ֻ");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
}
