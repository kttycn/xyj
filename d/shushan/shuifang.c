//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","˯��");
	set("long", @LONG

��������ɽ�����ڵ�˯���������е�ɣ����Ǵ�ɨ�ķǳ��ɾ���
һ�Ŵ��̿�ǽ����,���ϵ����˽�����Ϣ���Ѻ���ȥ�������ĵ�
�Ҹ�����˯��������
LONG);
	set("exits", ([
		"east" : __DIR__"westway3",
	]));

	set("sleep_room",1);  
	setup();
}

