// putiguo.c �����
// stone 20020415
//add force +5-6
//add mana +5-6
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//              set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
//		set("no_give","��ô����ҩ�����������ˣ�\n");
		set("no_drop","������ѵ�һ���������������δ��̫��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"�����"NOR, ({"puti guo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�Ө������������������ɽʥ�أ���ϡ�ޱȣ�
������������֮ʵ���˷���������������\n");
		set("value", 500000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int force_add,mana_add;
	force_add = 3+random(3);
	mana_add = 3+random(3);

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	me->set("food", (int)me->max_food_capacity());

	me->add_maximum_force(force_add);
	me->add_maximum_mana(mana_add);

	message_vision("$N��"+WHT"�����"NOR"������У�����һҧ�������������㣬����ȫ������æ��Ƥ���¡�\n",me);
	tell_object(me, "��ֻ��һ������ֱ͸��֫����......\n" NOR);
  
	destruct(this_object());
	return 1;
}

