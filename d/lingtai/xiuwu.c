// Room: /d/lingtai/xiuwu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ϴ�ľ��ң��������ŵ�ǽ��д��һ����������֡�
�������ĸ���ʿ�����ֳ�ľ�ȣ��·��ڱȻ�ʲô��
LONG );
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("objects",([
		__DIR__"npc/guangjing" : 1,      
		__DIR__"npc/guangguan" : 1,
		__DIR__"npc/guangming" : 1,
		__DIR__"npc/guangzhi" : 1,
	]));

	set("no_fight",1);
	set("no_magic",1);
	setup();
}

