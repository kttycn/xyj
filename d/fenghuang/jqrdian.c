inherit ROOM;
void create()
{
	set("short", "电信公司");
	set("long", @LONG
这是一家私人经营的电信公司，琳琅满目的通讯设备让你眼花缭乱，
看起来都不便宜哦。还是问问这个店员吧！墙上有一块招牌(zhaopai)。
LONG);
	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向店员购物。\n",
	]));
	set("exits", ([
		"south" : __DIR__"shangjie2",
//		"up" : __DIR__"youju",
	]));
	set("objects", ([
		__DIR__"npc/dianyuan": 1,
	]));
	setup();
}


