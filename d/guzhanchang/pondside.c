//stone 20020611
///d/guzhanchang/pondside.c 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "̶��С·");
	set("long", @LONG

̶����һƬ���ɫ�����أ�һ����ȥ�·���һ����ĺ�ɫ���̺��
�˴���ʯ��ᾣ���ݲ�������һ�ð��ɣ��ݲ�Ҳ�Ʋ�������Χ��һ
���ļž����������������ޣ�������ԼԼ�е��ƺ���ʲô���ף���
��˵������ʲô����ʱ����ӿ����һ˿������

LONG);
	set("exits", ([
		"east" : __DIR__"lukou0",
		"west" : __DIR__"shuitan",
	]));
	set("outdoors", "guzhanchang");
	replace_program(ROOM);
	setup();
}
