// 神话世界·西游记之（世纪）
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
	set ("short", "太和街");
	set ("long", @LONG

一条整洁的碎石路面，路面虽然不是很宽，但是人来人往的也是一片繁荣
的景象。街道是东西走向，往东是一眼清泉。北面就是城门，几个卫士在
城门下巡视，查看着来往的人们。
LONG);

	set("exits", ([
		"west"   : __DIR__"jiedao7",
		"east"   : __DIR__"qingquan",
		"north"   : __DIR__"dongmen",        
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}

