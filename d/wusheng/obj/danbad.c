// guoshi.c ����������

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( "������"HIM"����"NOR+HIG"������"NOR , ({"bad wuming guo", "bad guo", "badguoshi"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������Ͻ���������Ĺ�ʵ�������Ѿ������ˡ�\n");
		set("value", 0);
		set("no_sell", 1);
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	message_vision(HIR "$N����һ�Ż����������������ͽ��������£����ۡ���һ�������˳�����\n" NOR, this_player());
	destruct(this_object());
	return 1;
}

