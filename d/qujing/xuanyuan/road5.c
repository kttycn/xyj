inherit ROOM;
void create()
{
	set("short","[1;36m兵器库");
	set("long",@LONG

	 这里面存放着当年妲己修练时造就的一些兵器，每
一件都让你爱不释手。

LONG);
	set("exits", ([
		"south" : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"obj/needle1" : 2,
	]) );
	setup();
}

