#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", 
"���������������µ����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ谵�ĵ�
������ǿ�ֱ淽��ǽ�����������ʯ���������ģ��Ӻϵ�����������
�����Դ����ҳ�һ˿��϶���������аڷ���һ��"HIY"����"NOR"(jinpen)��һ��
а�����ص���˫�������ڽ����У�����Ѫ�죬ԭ�����������������������ҡ�\n");

	set("exits", ([
		"west" : __DIR__"mishi5",
		"out" : __DIR__"qianyuan",
		"down" : __DIR__"mishi7",
	]));

	set("objects", ([
		__DIR__"npc/chenxin" : 1,
	]));
	set("item_desc", ([
		"jinpen" : "����һ���ûƽ����ɵ����ӣ�����ʢ����"HIR"Ѫ��ɫ��Һ�塣\n"NOR,
	]));
	setup();
	replace_program(ROOM);
}

