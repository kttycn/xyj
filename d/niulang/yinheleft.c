// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
	set("short", "��������");
	set("long", @LONG

���������������֯Ů�����غ���������ţ�ɸ���������
��ϧ�м�������޷��ɹ������ӡ�        
        
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"yinhe",
	]));
	set("objects", ([
		__DIR__"npc/zhinu":1,
	]) );
	setup();
}
