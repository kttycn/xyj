//Cracked by Roath
// yinluju.c
//written by kittt

inherit ROOM; 
#include <ansi.h>

void create() 
{
	set("short", "饮绿居"); 
	set("long",@LONG
这里是一处竹屋，四处绿竹环绕，鸟鸣悠悠，屋旁有一条小溪
流过，身居此处，有一种超凡脱俗，世事皆忘的感觉。 
LONG);
	set("exits",([
		"north" : __DIR__"bridge",
		])); 
	
	set("no_fight",1);
	
	setup(); 
} 
