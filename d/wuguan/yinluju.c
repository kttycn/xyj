//Cracked by Roath
// yinluju.c
//written by kittt

inherit ROOM; 
#include <ansi.h>

void create() 
{
	set("short", "���̾�"); 
	set("long",@LONG
������һ�����ݣ��Ĵ������ƣ��������ƣ�������һ��СϪ
��������Ӵ˴�����һ�ֳ������ף����½����ĸо��� 
LONG);
	set("exits",([
		"north" : __DIR__"bridge",
		])); 
	
	set("no_fight",1);
	
	setup(); 
} 
