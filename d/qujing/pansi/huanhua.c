#include <ansi.h>

inherit CITY;

void create ()
{
	reload("huanhua");
	set ("short", "佻���");
	set ("long", @LONG

���·ת��������һ��СС�ĳǱ�����ɽ��Ұ���ǳ�����л�Ļ�
��Ķž黨����ɽ��ҲͽȻ�������Ǳ���ɽ��ˮ��������������
�����������������������������������֡�

LONG);

	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"ling2",
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
