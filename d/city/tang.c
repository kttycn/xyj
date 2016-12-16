//By waiwai@sjmd 2000/10/07
//设置了两种减杀人数值的方式
//可以根据需要进行实际的调整
//设置

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HBRED HIY" 恩 怨 堂 "NOR);
	set("long", 

"\n堂正中檀木香案，案上燃着几炷香，整间屋檀香袅袅。凡是入\n"+
"此堂的人，都愿把以往恩怨一笔勾消。如果你有愧你的所作所\n"+
"为想重新作人，忘记已往的恩恩怨怨,只需在这里跪下 "+HIR"(kneel) \n\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"sanhua",
	]));
	set("no_fight",1);
	set("no_magic",1);
	set("no_kill",1);

	setup();
}

void init()
{
	add_action("do_kneel", "kneel");
}

int do_kneel(string arg)
{
	object me;
	int pk,dx,exp,j;
	me = this_player();
	pk = (int) me->query("PKS");
	dx = (int) me->query("daoxing");
	exp = (int) me->query("combat_exp");

	if((int)me->query("balance")<100000) 
		return notify_fail(HIC"你钱庄存款不足！\n"NOR);

	if(me->query("bellicosity") <= 0)
		return notify_fail(CYN"你没杀过人不用跪拜......\n"NOR);

 	me->set("bellicosity",0);
	me->add("balance",-1000000);

	message_vision(HIY"$N跪倒在地，决定忘记以前所有的仇家.......\n"NOR,this_player());
	return 1;
}
