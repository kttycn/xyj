//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·��������ի����
��ʱ��Ʈ��һ���㡣
LONG);

	set("outdoors", "shushan");
	set("exits", ([     
       "north" : __DIR__"westway3",
       "south" : __DIR__"westway1",
        "west" : __DIR__"zhaifang",
       ]));

	setup();
}
