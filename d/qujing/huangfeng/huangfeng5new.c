//Cracked by Roath

inherit ROOM;

void create ()
{
	set ("short", "山路");
	set ("long", @LONG

走到山路上，看着远方的丛山，你觉得此山真是个险啊，山峰迭障
不断，山路起浮崎岖，路旁尽是些奇石怪木，远远的看到北边影影
的有灯火光明，只是奇怪刚才怎么没有看到这条路？

LONG);

	set("exits", ([
		"southwest" : __DIR__"huangfeng4",
		"north" : __DIR__"outdoor",
	]));
	set("outdoors","hfd");
	setup();
}
