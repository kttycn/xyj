//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","����");
	set ("long", @LONG
        [1;31m��ɽ����  �ƴ�����[2;37;0m
LONG);

	set("exits", ([     
        "west" : __DIR__"jby",
        "east" : __DIR__"zhenyaota/bamboo",
	]));
       set("objects", ([         
         __DIR__"npc/shouhu" : 1,
        __DIR__"npc/shouhu1" : 1,
       ]));
  
       setup();
}
int valid_leave(object me, string dir)
{
    if ( dir == "east" ) {
        if(objectp(present("shouwei dizi", environment(me))))
            return
notify_fail("��ɽ����һ������������ǰ�棬�����������ߣ�\n");
    }
    return ::valid_leave(me, dir);
}
