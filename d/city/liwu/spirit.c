// by night
// fid �޸�

inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", HIY"����¥"NOR);
	set ("long", @LONG
��ҹ�����������ٴ��ĵ��������ɺ�ë̺��¥��������������Ǯ
��������ʯ���Ǯ����������ɫ��Ǯ�������졣������һ��÷��ʽ
����С������������ƿ���㱸������һ�������������ӡ�
LONG);

	set("exits", ([
                "down" : __DIR__"happyjie",
	]));
	set("objects", ([
//		__DIR__"obj/xiang" :  1,
		__DIR__"npc/spiriter.c" : 1,//�����·�����Զ��塣
	]));

	setup();
}

//��������mud��һ�����ܣ��������ߵ�ʱ�����֧��1 gold.����ȥ��...
/*
int valid_leave (object who, string dir)
{
	if (dir != "up")
	return ::valid_leave (who, dir);

	if (! who->query_temp("kaifeng_donate_silver"))
		return notify_fail ("���(donate)һ���ƽ�������\n");

	return ::valid_leave (who, dir);
}
*/
