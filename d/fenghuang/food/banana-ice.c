// banana-ice.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�㽶�µ�", ({"banana-ice", "banana"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����㽶Ϊ��Ҫ�ɷֵı���ܡ�\n");
		set("unit", "��");
		set("value", 800);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
