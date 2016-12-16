// pepsi.c  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����", ({"pepsi"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һƿ���������еİ��¿���.\n");
		set("unit", "ƿ");
		set("value", 100);
		set("max_liquid", 50);
	}

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "���¿���",
		"remaining": 15,
		"drunk_supply": 10,
	]));
}
