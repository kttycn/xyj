//  ����֮�� ������
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "����");
	set("long", @LONG
����һ���տ��ĵ�·���Ա���ˮ��������ɽ��ɽ��ˮ�㣬
��Ҷ������ض��ǣ��������Ľ��ţ��㲻���е������ر�
�ĺá�
LONG);
	set("exits",([
		"westup": __DIR__"shanlu1",
	]));
	set("outdoors", "jz");
	setup();
	replace_program(ROOM);
}
