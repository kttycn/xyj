inherit ROOM;

void create ()
{
	set ("short", "�ʹ�����");
	set ("long", @LONG

�ʹ�����ׯ�����£���ڻԻͣ���ǽ������ߴ���ΰ����
������������߰��������ûʡ��˿̹��Ž��գ���ǰ����
�ż�λ�����ʿ��

LONG);

	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/weishi" : 3,
		__DIR__"npc/xuerengui" : 1,
	]));
	set("outdoors", 1);
	set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"chaoyangmen",
		"north" : __DIR__"guangchang",
		"northeast" : __DIR__"yhy3b.c",
		"northwest" : __DIR__"yhy3a.c",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("quest/reward"))
		return ::valid_leave(me, dir);
	if (dir == "north" ) {
		if (me->query_temp("dianmao") || wizardp(me) )
			return ::valid_leave(me, dir);
		if (objectp(present("xue rengui", environment(me))))
			return notify_fail("Ѧ�ʹ���ǹһ�ᣬ�ȵ������˻ʹ������У�\n");
		if (objectp(present("wei shi", environment(me))))
			return notify_fail("�����ʿ�������Ҽҽ������ڣ�С�˲��ҷ�����ȥ��\n");
	}
	return ::valid_leave(me, dir);
}

 
