// jingping.c 净瓶 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name("净瓶", ({"jingping", "bottle"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "南海观音盛水的净瓶。\n");
		set("unit", "个");
		set("value", 5000);
		set("max_liquid", 500);
	}

	set("liquid", ([
		"type": "water",
		"name": "圣水",
		"remaining": 10,
		"drunk_apply": 20,
	]));
}
void init()
{
	add_action("do_pour","pour");
}

int do_pour(string arg)
{
	object ob = this_player();
	object where = environment(ob);

	if( ! arg || arg != "water" )
		return notify_fail("你要把什么从静瓶中倒出来？\n");
	if( !environment(environment())->query("killed") )
		return notify_fail("这里用不着净瓶。\n");                
	if( query("liquid/remaining") < 1 )
		return notify_fail("瓶子中的圣水已经被喝光了。\n");
	if( where->query("short") != "果树上" )
		return notify_fail("你别忘了自己要去干嘛的？\n");

	message_vision("$N把静瓶中的水慢慢的倒上人参果树上，奇迹发生了。\n",ob);
	message_vision(HIG"人参果树马上就发出了嫩芽。\n"NOR,ob);
	remove_call_out("reware");
	call_out("reward",3,ob);
	where->delete("killed");
	return 1;
}

void reward(object ob)
{
	int i;

	string name=ob->query("name");

	if( ob->query("obstacle/wzg") == "done" )
		return;
	if( !ob->query_temp("kill_tree") )
		return;
	if( !ob->query_temp("kill_fuxing");
		return;

	i = random(600);
	ob->add("obstacle/number",1);
	ob->set("obstacle/wzg","done");
	ob->add("daoxing",i+3000);
	who->add("score", 10);
	message("channel:chat",HIC"【闲聊】镇元大仙(Zhenyuan daxian)："+name+"五庄观救活人参果树。\n"NOR,users());
	message("channel:chat",HIW"【过关斩将】观音菩萨(Guanyin pusa)："+ob->query("name")+"闯过西行取经第九关！\n"NOR,users());
	tell_object (ob,"你赢得了"+COMBAT_D->chinese_daoxing(i+3000)+"的道行！\n");
	ob->save();
	destruct(this_object());
	return;
}
