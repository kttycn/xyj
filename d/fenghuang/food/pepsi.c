// pepsi.c  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("百事", ({"pepsi"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一瓶现在正流行的百事可乐.\n");
		set("unit", "瓶");
		set("value", 100);
		set("max_liquid", 50);
	}

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "百事可乐",
		"remaining": 15,
		"drunk_supply": 10,
	]));
}
