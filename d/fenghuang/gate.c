#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "宗主府大门");
	set("long", @LONG
这里是宗主府的大门。正前方红墙金瓦，雕龙飞檐，正中一道二丈来
宽，三丈来高的朱红杉木包金大门(gate)。上方一块大匾，龙飞
凤舞地书着『宗主府』三个大字。门上贴着一幅对联，听说是宗主亲自
写的。
　　　　　
                      顺 昌 逆 亡
                   

             逆                            屠
             天                            神
             睇                            灭
             地                            佛
             唯                            看
             我                            朕
             独                            一
             尊                            统
             宇                            天
             内                            下

LONG );
	set("exits", ([
		"north" : __DIR__"qianyuan",
		"south" : __DIR__"bjie3",
	]));

	set("objects", ([
		__DIR__"npc/weishi1" : 4,
		__DIR__"npc/tongling" : 2,
		__DIR__"obj/shishi" : 2,
	]));
//   set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
