#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","Բ��С��");
	set("long",
"����һ���ô���ʯ���ɵ�Բ���ε�С�ţ��Ա�����һ��
ľ�ƣ�����д�ţ�"HIR"�����˵ȣ���ֹ���ڡ�\n"NOR);
	set("objects", ([
		__DIR__"npc/lanren": 1,
	]));
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang",
		"north"  : __DIR__"xiaodao",
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

