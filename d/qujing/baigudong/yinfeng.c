#include <ansi.h>

inherit CITY;

void create ()
{
	reload("yinfeng");
	set ("short", "����ɽ");
	set ("long", @LONG

��Ȼ����̹ǣ�ԭ����������ɽ����ɽ��Ұ���ǹ»�Ұ��ɽ��
�վ����ζ఼͹���������룬����®�ң�ԶԶ��ȥ�����Թ����
�졣

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"shanlu8",
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
