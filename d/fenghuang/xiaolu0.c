#include <ansi.h>
inherit ROOM;

int do_go();

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��С·����֪ͨ��ʲô�ط�����һֱ����ȥ��
����������벻���ķ��֡�
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"xiaolu",
		"north"  : __DIR__"huayuan2",
	]));
	set("no_fly",1);
	setup();
}

void init()
{
	add_action("do_go","go");
}

int do_go()
{
	if(random(30)){
		this_player()->move(this_object());
		return 1;
	}
}
