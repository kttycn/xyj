//Cracked by Roath
inherit ROOM;
inherit "/d/wiz/no_get.c";

void create()
{
	set("short", "千年寒冰床");
	set("long", @LONG

一块千年寒冰做成的小床．据说在这里对内功大有裨益.
LONG
	);

	set("exits", ([
		"out": __DIR__"shishi3",
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("sleep_room",1);
	set("if_bed",1);

	setup();
}

void init() {
	add_action("do_sleep","sleep");
	::init();
}

int do_sleep()
{
	object me=this_player();
	int lvl_force, c_exp, c_skill;
	if (this_player()->query("family/family_name")!="盘丝洞")
	{
		write("你冻的全身发抖,翻来复去怎麽也睡不着。\n");
		this_player()->start_busy(1);
		return 1;
	}

	lvl_force=(int)me->query_skill("force",1);
	if(lvl_force>150) //force 大于 150
	{
		this_player()->start_busy(3);
		message_vision("$N躺上了寒玉床，开始潜运内功，使内息遍行大小周天。\n",this_player());
		if (random(20)>12) {
			message_vision("$N调息完毕，只觉得精神健旺，内息充沛欲奔腾而出。\n", this_player());
			c_exp=me->query("combat_exp");
			c_skill=me->query_skill("force",1);
			if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<250))
			{
				me->improve_skill("force", random(lvl_force));
			}
			me->receive_damage("kee",random(lvl_force/3));
		}
		else
			message_vision("$N调息完毕，站起身来，提了提内力，好象没什么长进。\n", this_player());
	}
	else {
		this_player()->start_busy(1);
		message_vision("$N躺上寒玉床，只觉得冰冷刺骨，‘啊’的一声狼狈不堪地跳了起来。\n", this_player()); }
	return 1;
}
