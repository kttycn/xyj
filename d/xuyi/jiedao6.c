// 神话世界·西游记之（世纪）
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
	set ("short", "街道");
	set ("long", @LONG

一条整洁的碎石路面，路面虽然不是很宽，但是街道旁店铺林立，长街故
朴，屋舍鳞次栉比，道上人来车往，依然是一片太平热闹景象。街北隐隐
有虹光闪耀，通往水母娘娘府邸的宫门。

LONG);

	set("exits", ([
		"east"   : __DIR__"jiedao5",
		"north"   : __DIR__"jiedao2",
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}
