//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","����");
	set ("long", @LONG

������ʦ�������һ��С·, С·������ʯ�̳ɵأ���ɨ��
��Ϊ�ɾ�����������е��ǳ�ƽ̹��С·�������һЩ����
��״��ʯ���������߾��Ǻ���ˡ�
LONG);

	set("exits", ([     
       "south" : __DIR__"westway4",
        "east" : __DIR__"houdian",
       ]));
        setup();
}
