// changan wusheng
// uptree.c

inherit ROOM;

void create()
{
	set ("short", "������");
	set ("long", @LONG

վ��������Ķ��ˣ�ɽ�����󣬿������£���ɽ����������
Լ����һƬ������һ�ɵ�������������֮�£�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"down": __DIR__"shijie8"
	]));
	set("objects", ([
		__DIR__"obj/guoshi": 1]));
	set("no_clean_up", 0);
	set("outdoors", "wusheng");
	setup();
	replace_program(ROOM);
}


