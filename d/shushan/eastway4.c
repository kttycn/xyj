//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·�������һЩ����
��״��ʯ�񡣶����ǲؾ�����˵��������źܶ����õ��顣
LONG);

	set("outdoors", "shushan");
	set("exits", ([     
       "north" : __DIR__"houlang1",
       "south" : __DIR__"eastway3",
        "east" : __DIR__"cangjingge",
       ]));
        setup();
}
