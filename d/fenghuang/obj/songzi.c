// peach.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"song zi"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ɰͰ͵����ӡ�\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
}