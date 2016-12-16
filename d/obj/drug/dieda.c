// jinchuang.c 金创药

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("跌打丸", ({"dieda wan", "wan", "yao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("base_unit", "颗");
		set("unit", "些");
		set("long", "这是一颗治伤的跌打药。\n");
		set("value", 1500);
		set("drug_type", "良药");
	}
	set_amount(1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	else {
		this_player()->receive_curing("kee", 30);
		message_vision("$N吃下一颗跌打丸，气色看起来好多了。\n",this_player());
		add_amount(-1);
		return 1;
	}
}

