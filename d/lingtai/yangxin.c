// Room: /d/lingtai/yangxin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�侲�ң��������ŵ�ǽ��д��һ������ľ��֡�
����ǽ�ڵ������Ͼ����������ĸ���ʿ���·��ڱ�Ŀ
����
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang",
	]));
	set("objects",([
		__DIR__"npc/guanghe" : 1,      
		__DIR__"npc/guangji" : 1,
		__DIR__"npc/guangwen" : 1,
		__DIR__"npc/guangxin" : 1,
	]));

	set("no_fight",1);
	set("no_magic",1);
	setup();
}

