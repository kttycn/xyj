//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short", "����");
	set ("long", @LONG

��������ɽ���ɵ��������������Ƕ���һЩ��é�ݣ���һʯ����
����һ��¯����������,����Сͯ����������
LONG);

	set("exits", ([
		"east"    : __DIR__"westway4",
	]));
	set("objects", ([
		__DIR__"obj/danlu"    : 1,
		__DIR__"npc/heer"    : 1,
		__DIR__"npc/zhuiyunzi" : 1,
	]));
	setup();
}

