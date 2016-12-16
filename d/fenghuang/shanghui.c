inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"救挤商会"NOR);
	set("long", @LONG
你走到这里，发现这是一个救挤商会，虽然地方简陋，但地盘却大得不得了。
你正在到处观看时，从你后面传来一个声音：“宗主万岁！”你向后看了看，
却什么都没发现，只是看到了一块木牌(paizi)立在那儿！
LONG
	);
	set("no_fight",1);

	set("exits", ([
		"up"  : __DIR__"shangjie2",
	]));

	set("item_desc",(["paizi": "你可以说！(hou)！！！！\n",]));
	setup();
}

void init()
{
	add_action("do_hou", "hou");
}
int do_hou()
{
	object me;
	int exp;
	me = this_player();

	if ( me->query("combat_exp")>10000)
		return notify_fail("您的战斗力太高，在这里恐怕会伤害他人！\n");
	if ( me->query("sen") < 20 )
		return notify_fail("你的耐久力不够，休息一下再来吧！\n");
	if(me->is_busy() )
		return notify_fail("你现在忙着呢，哪有功夫乱喊...\n");

	me->add("sen", -10);
	if ( random((int)me->query("kar")) < 5 )
	{
		message_vision("$N喊道：宗主万岁！可是却没人理你。\n", me);
		me->start_busy(random(5));
	}

	else
	{
		message_vision("$N手中拿着麦克风抄着五音不全的嗓子痧道：宗主万岁。\n", me);
		write("有人给了你一些MONEY，心中暗叫到：“ok！”\n");
		me->add("balance",random(300));
		me->add("combat_exp",random(10));
		me->add("potential",random(5));
		me->start_busy(2+random(3));
	}
	return 1;
}

