#include <room.h>

inherit ROOM;
void create()
{
	set("short", "��ʥ��");
	set("long", @LONG
�����Ǵ�ʥ�õ���������Ƿ��Ů��ĵ��񡣵����๩���ŷ����
�ĹŴ���ʥ�����˵��ˣ��������������Ϲ��Ͼ���հ�����ݡ�
LONG );
	set("no_fight", "1");
	set("no_steal", "1");

	set("objects", ([
		__DIR__"obj/shen" : 1
	]));

	set("exits", ([
		"north" : __DIR__"zhongxin",
	]));
	setup();
	replace_program(ROOM);
}


