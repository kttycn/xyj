//u/stone/d/jianshenfang.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","石头的洗手间");
	set ("long", @LONG
	
这是巫师石头的洗手间，地上铺着精美光纹的大理石，东墙角有
一个大大的高级澡缸，西墙角有一座洁白的马桶，北墙面上镶着
一面明亮的镜子，旁边的各种盥洗用品一应具全。
东面面是石头的工作室。
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
		"northwest" : "/d/update/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	setup();
}