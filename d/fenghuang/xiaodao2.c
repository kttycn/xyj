#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", 
"����ƽʱ�˼��������Ӳݴ�������Ŀ�������Ӳ�������
����ɢ����һЩ��ɫ����������ϸһ������Ȼ��һЩ
ʬ�ǲк����㲻���ĵ�����һ�ɺ��������˸���ս��\n"
BLU"һ�������������֪�����ﴫ����Ķ��ߣ���ȥ�ɣ���
ȥ�ɡ�������\n"NOR);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"xiaodao1",
		"north"  : __DIR__"houyuan",
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

