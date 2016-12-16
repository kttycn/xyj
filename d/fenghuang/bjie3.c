inherit ROOM;
void create()
{
	set("short", "宗府大道");
	set("long", @LONG
这是一条用白玉铺成的大道，可见宗主府的奢侈，大道两边站满
士兵，威武森严，一般人是不敢随便进入这里的，否则宗主会杀
无赦，北面就是凤凰城的平民闻之色变的宗主府邸了！你越走越
心寒了，不由的想回去，但是宗主府的旷世武功又吸引你向前走
已经渐渐的看到宗主府的大门了。
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
	    "north" : __DIR__"gate",
	    "south" : __DIR__"bjie2",
	]));
	set("objects", ([
		__DIR__"npc/weishi" : 4,
		__DIR__"npc/weishi1" : 2,
	]));
//      set("no_clean_up", 0);
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


