// ZHANGM 1999/12/18 
#include <ansi.h>
inherit BANK;

void reset_balance(object me);

void create()
{
	set("short", HIY "凤凰大银号" NOR);
	set("long", @LONG
这是一家老字号的银号，已有近千年的历史，在凤凰星各各个卫星城都有分店。它发
行的电子信用卡信誉非常好，而且非常方便，通行全国。
    在对面的墙上的电子屏幕(pingmu)上显示着这里新办业务。
LONG );
	set("exits", ([
		"south" : __DIR__"eshangjie1",
	]));
	set("item_desc", ([
		"pingmu" : @TEXT
       本银行提供以下服务：
       转帐      zhuanzhang <某人> <黄金数量>
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/banker" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
}
