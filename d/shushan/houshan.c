//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��ɽ·");
	set ("long", @LONG

������ͨ����ɽ�ɽ���µ�ɽ·�������·ƽ̹,�����ǳ���������
��˵��ɽ���и����������㲻����ǰȥ��һ����
LONG);

	set("outdoors", "shushan");
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"houyuan",
		"north" : __DIR__"houshan0",
	]));

	setup();
}






