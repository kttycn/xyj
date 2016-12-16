#include <ansi.h>
inherit ITEM;
//inherit F_AUTOLOAD;  

int do_locate(string arg);
int do_task();

void create()
{
	set_name(HIB"水晶球"NOR, ({"shuijing qiu","qiu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一件用于寻找失物的"HIB"水晶球"NOR"，它具有非凡的魔力。\n"+
			"能用(task)列出所有丢失的物品，用(locate)命令找到物品的大概位置！\n");
		set("unit", "件");
		set("value", 50000);
	}
	setup();
}

void init()
{
	object ob = this_player();

	add_action("do_locate","locate");
	add_action("do_task","task");
}

int do_task()
{
	string output;
	output=HIB"水晶球"NOR"里突然映现出一篇蝇头小字：\n\n"+TASK_D->dyn_quest_list();
	this_player()->start_more(output);
	return 1;
}

int do_locate(string arg)
{
	if ( ! arg)
		return notify_fail("locate <物品>\n");
	else
		TASK_D->locate_quest(this_player(),arg);
   this_player()->add("sen",-5);
   return 1;
}

//int query_autoload() { return 1; }
