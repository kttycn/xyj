inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ�˾�У��ʳ�ã���ѧ�����ò͵ĵط������ʳ�úܴ�
����ذڷ���һ��һ�ŵ����Ρ�������������������������
���ż���ѧ���������ò͡�
LONG
	);
	set("exits",([
		"east" : __DIR__"jiaoxue",
	]));
	set("objects", ([
		__DIR__"npc/dashifu" : 1,
		__DIR__"food/jiuhu" : 1,
	]));
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));

	set("no_clean_up", 0);
	setup();
}

int valid_leave()
{
	if((present("hefan", this_player())))
		return notify_fail("����з�������\n");
	if((present("jiuhu", this_player())))
		return notify_fail("�㲻�ܰѾƺ����ߣ�\n");
	return ::valid_leave();
}

