#include <ansi.h>

inherit CITY;

void create ()
{
	reload("erengu");
	set ("short", "���˹�");
	set ("long", @LONG

����û����û������Ҳû����դ�����Ǹ�ɽ��ģ����һ�������ݣ�
�ڵƻ����ҫ�£����Ե���ô������ƽ�͡�һ��ʯ�����ڵ��ԡ�
����д�ţ��������ȣ�����Ϊū����

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"shanlu3",
	]));
	set("no_clean_up", 1);

	setup();
}

int clean_up()
{
      return 0;
}

int valid_leave(object me, string dir)
{
    if (dir == "out" && query("attacker") == me->query("id"))
		return notify_fail("�����ڹ����أ��������Ӳ�̫�ðɣ�\n");
	return ::valid_leave(me, dir);
}
