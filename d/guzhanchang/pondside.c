//stone 20020611
///d/guzhanchang/pondside.c 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "潭边小路");
	set("long", @LONG

潭边是一片深红色的土地，一眼望去仿佛是一块厚厚的红色大地毯。
此处怪石鳞峋，寸草不生，连一棵矮松，枯草也瞧不到。周围死一
样的寂静，看不见飞鸟走兽，你隐隐约约感到似乎有什么不妥，但
又说不上来什么，顿时心中涌起了一丝不安。

LONG);
	set("exits", ([
		"east" : __DIR__"lukou0",
		"west" : __DIR__"shuitan",
	]));
	set("outdoors", "guzhanchang");
	replace_program(ROOM);
	setup();
}
