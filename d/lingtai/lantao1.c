// Room: some place in ��ţ����
// forrest.c

inherit ROOM;

void create()
{
	set ("short", "������");
	set ("long", @LONG

����֮�зǳ��İ�������ȫ����ɡ��ǵ���֦��ס�����²�
����֦��ÿ��һ�����ᷢ���ܴ����������
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"lantao",
		"southdown" : __DIR__"forrest",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "fangcun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}


