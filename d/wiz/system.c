// Room: /d/wiz/system.c

inherit ROOM;
#include <ansi.h>

void create()
{
  set ("short","ϵͳ������");
	set("long", @LONG

����һ�����ͨ�ķ��䣬��������һЩ�й�����������Ѷ��

LONG
	);
set("item_desc" , ([ /* sizeof() == 1 */
"east": "�������������ƣ�ʲôҲ���������\n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/wiz/wizroom",
  "west" : "/d/wiz/entrance",
]));
  set("objects", ([ /* sizeof() == 1 */
//  "/d/wiz/obj/xmastree" : 1,
//  "/u/vikee/table" : 1,
]));
        set("no_time",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_magic", 1);
	set("post_limit", 1);

	setup();
	call_other("/obj/board/system_b", "???");
}


int valid_leave(object me, string dir)
{
//		if(me->query("id")=="beavis") return ::valid_leave(me, dir);
		  //temp access for future wiz.

		if( dir=="east" && !wizardp(me) )
			return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
		return ::valid_leave(me, dir);
}


