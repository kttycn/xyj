// guoshi.c ����������

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( "������"YEL"�޻���"NOR, ({"bad wuhua guo", "bad guo"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���Ѿ������˵��޻�����\n");
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
	message_vision(HIR "$N����һ�Ż������޻����ͽ��������£����ۡ���һ�������˳�����\n" NOR, this_player());
	destruct(this_object());
	return 1;
}

