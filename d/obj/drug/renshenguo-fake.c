#include <ansi.h>

inherit ITEM;
int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "�˲ι�" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "�װ����ֵ�һö�˲ι�����ǧ��һ��������ǧ��һ���������ǧ��ŵ��죬ʵ����ؼ���鱦��\n");
		set("drug_type", "��Ʒ");
	}

//	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if(environment(me)->query("alternative_die"))
		return notify_fail("�㲻���������"+name()+"��\n");

	message_vision(HIW "$N���˲ι�������һ����ȴʲô��ӳҲû�У������Ǹ����˲ι���\n" NOR, me);
	return 1;
}
