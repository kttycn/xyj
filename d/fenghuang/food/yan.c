#include "ansi.h"

inherit ITEM;
int do_eat(string);
void init();

void create(){
	set_name( HIW "巴西雪茄" NOR , ({"yan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根巴西雪茄香烟，略微能闻到些许香气。\n");
		set("value",5000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

void init(){
	if (!wizardp(this_player())) {
		set("no_get","你手里一松，香烟从指间滑落！\n");
		set("no_give","这可是宝贝啊，哪能随便给人？\n");
		set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	message_vision(HIG "$N从烟盒里拿出一根雪茄烟放在嘴边点燃，
只见$N脸慢慢变得通红,好象很爽的样子,一会儿，\n 吐出了一个烟圈！\n" NOR, me);
	destruct(this_object());
	return 1;
}
