// guoshi.c ����������

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIM"����"NOR+HIG"������"NOR , ({"wuming guo", "guo", "guoshi"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������Ͻ���������Ĺ�ʵ��\n");
		set("value", 8000);
		set("no_sell", 1);
		set("drug_type", "��Ʒ");
	}
	setup();
	call_out ("becoming_old",300);
}

void becoming_old ()
{
	object me = this_object();
	object where = environment (me);
	object dan = new (__DIR__"danbad");

	dan->move(where);
	destruct (me);
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();
	if (arg!="wuming guo" && arg!="guo") 
	return 0;
  
	me->set("food", (int)me->max_food_capacity()*3+random(120));
	me->set("water", (int)me->max_water_capacity()*3+random(120));
	message_vision(HIG "$N����һ�������������ͽ��������¡�\n" NOR, me);
	tell_object(me, "��ʱ����ø������ȣ�ƮƮ���ɣ�\n");
	destruct(this_object());
	return 1;
}

