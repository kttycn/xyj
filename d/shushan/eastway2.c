//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·�������һЩ����
��״��ʯ�񡣶����Ǳ�����,�����������ñ�����
LONG);

	set("outdoors", "shushan");
	set("exits", ([     
       "north" : __DIR__"eastway3",
       "south" : __DIR__"eastway1",
        "east" : __DIR__"bingqiku",
       ]));

	setup();
}
