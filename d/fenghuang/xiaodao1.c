#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
����ƽʱ�˼��������Ӳݴ�������Ŀ�������Ӳ�������
����ɢ����һЩ��ɫ����������ϸһ������Ȼ��һЩ
ʬ�ǲк����㲻���ĵ�����һ�ɺ��������˸���ս��
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"xiaodao",
		"north"  : __DIR__"xiaodao2"
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

