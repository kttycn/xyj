inherit ROOM;

void create()
{
	set("short", "凤凰大酒店");
	set("long", @LONG
这里就是名声远扬的凤凰大酒店了，这个高高的建筑已经成了
中心城的标志性建筑物，在这里你可以感觉到久违的家的感觉，作
为凤凰城最豪华的酒店，任何服务的收费都是惊人的，不过就算你
在它的门口站一会也会感到脸上添光不少的。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
//      set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "楼上被备有总统套房，每夜十两黄金。\n",
	]));
	set("objects", ([
		__DIR__"npc/fuwusheng" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"eshangjie2",
		"up"   : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("服务生有礼貌的拦住你道：请预定房间！\n");

	return ::valid_leave(me, dir);
}

