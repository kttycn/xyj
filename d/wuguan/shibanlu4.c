//Cracked by Roath
// shibanlu4.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "ʯ��·"); 
	set("long",@LONG
����һ���Ѿ������ߵù��������ʯ��·����һ��С�Ĳ�
�Ͽ���̦��ˤ�˸�����ſ������������䳡��ʱ�����ٺٵ���
������
LONG);

	set("exits",([
		"north" : __DIR__"lianwuch2",
		"south" : __DIR__"xiwutang1",
		"west" : __DIR__"shibanlu6",
		"east" : __DIR__"shibanlu2",
		])); 
	set("no_fight",1);
	set("outdoors", __DIR__"");

	setup(); 

} 
