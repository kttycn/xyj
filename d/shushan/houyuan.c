//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short", "��Ժ");
	set ("long", @LONG

��������ɽ�ĺ�Ժ,����յ�����ʲôҲû��,ֻ����������
������վ�š��������߾�����ɽ�Ľ�����ˡ�
LONG);

	set("outdoors", "shushan");
	set("exits", 
	([    
		"northup" : __DIR__"houshan",
		"south" : __DIR__"houdian",
	]));
	set("objects", ([         
		__DIR__"npc/hdizi" : 2,
		__DIR__"npc/minger" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "northup" && !me->query_temp("shushan/ask_zuidao_go") ) {
		if(objectp(present("ming er", environment(me))) && !wizardp(me) )
			return notify_fail("����˵��:��������ɽ�������ò�Ҫȥ��\n");
		if(objectp(present("di zi", environment(me))) && !wizardp(me) )
			return notify_fail("��ɽ����˵��:��������ɽ�������ò�Ҫȥ��\n");
	}
	return ::valid_leave(me, dir);
}
