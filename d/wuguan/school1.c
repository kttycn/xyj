//Cracked by Roath
// Room: /d/4world/school1.c
inherit ROOM;

void create ()
{
	set ("short", "������ݴ���");
	set ("long", @LONG

��������վ��һ���լԺ����ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ���
�࣬һ����ߺ���뵶����ײ��������Ժ���д�����ͨ���������Ͽ�
��������������µĺ������ڲ�����
LONG);

	set("light_up", 1);
	set("no_magic", 1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/guard" : 1,
	]));
	set("outdoors", __DIR__"");
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"school2.c",
		"north" : "/d/dntg/hgs/east1",
	]));
	set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" ) {
		if ( (me->query("combat_exp")<30000 || me->query("daoxing")<30000
		|| me->query("maximum_force")<900 ) || wizardp(me) )
			return ::valid_leave(me, dir);
		else if(objectp(present("guard", environment(me))))
			return notify_fail("����Ц������������Ѳ����ٽ���ʲô�ˣ���أ���ء�\n");
		return 1;
	}
	return 1;
}
