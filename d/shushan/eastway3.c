//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��С·");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·�������һЩ����
��״��ʯ�񡣶��������������㿴���кܶ���������������
LONG);

	set("outdoors", "shushan");
	set("exits", ([     
       "north" : __DIR__"eastway4",
       "south" : __DIR__"eastway2",
        "east" : __DIR__"liangongfang",
       ]));
        setup();
}
