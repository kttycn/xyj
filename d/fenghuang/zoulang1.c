#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����һ���ú�����ʯ���ɵ����ȣ��������ź�ɫ�ĵ�̺������վ��
����������Ů���ӣ���Цӯӯ�Ŀ����㡣�㲻�������˽Ų���
LONG);
	set("objects", ([
		__DIR__"npc/shinv": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"huayuan1",
		"north"  : __DIR__"zoulang3",
	]));
	setup();
	replace_program(ROOM);
}

