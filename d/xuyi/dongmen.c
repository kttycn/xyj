// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
	set ("short", "����");
	set ("long", @LONG

����ϙ�Ƕ��ţ��������߾͵����̳�С·�ˡ�·������ͺ�խС�ˡ�����
�������Ǹ߸ߵ�ɽ�룬�м�һ����С��ͨ���棬��˵���Ե����ʥ��
�£��������˴�ʥ��ʦ�������;�ס�����
LONG);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/qian" : 1,
		__DIR__"npc/weishi" : 3,
	]));
	set("outdoors", 1);

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"jiedao4",
		"east" : __DIR__"xiaolu0",
		"south" : __DIR__"jiedao8",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if(!me->query_temp("xuyi/monster")) return 1;
//        if( wizardp(me)) return 1;

	if (dir == "west" || dir == "south" ) {
		return notify_fail("�������в��������������ǰɡ�\n");
	}   
	return ::valid_leave(me, dir);
}

