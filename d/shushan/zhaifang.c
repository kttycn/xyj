//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","ի��");
	set("long", @LONG

��������ɽ���ɵ�ի��,����������С·�������������к�
��óԵġ�����ӵ����տ������ܲ����������ҪЩ(yao)
�Եġ�
LONG);
        
	set("no_fight",1);
	set("exits", ([
		"east" : __DIR__"westway2",
	]));

	set("objects", ([         
		__DIR__"npc/chuzi" : 1,
		__DIR__"npc/qinger" : 1,
	]));
	set("clean_up", 1);
	set("resource", ([        
		"water" : 1,
	]));
	setup();
}
int valid_leave()
{
	if((present("gongbao jiding", this_player())))
		return notify_fail("���깬������������\n");
	if((present("jiu zhan", this_player())))
		return notify_fail("�㲻�ܰѰ����յ���ߣ�\n");
	return ::valid_leave();
}


