//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·��������˯����
һ�����������˯���д�����
LONG);

	set("outdoors", "shushan");
	set("exits", ([     
       "north" : __DIR__"westway4",
       "south" : __DIR__"westway2",
        "west" : __DIR__"shuifang",
       ]));

	setup();
}
