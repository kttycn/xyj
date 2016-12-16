// lingzhi.c ��֥
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//   set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
		set("no_give","��ô����ҩ�����������ˣ�\n");
		set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(MAG "��֥��" NOR, ({"lingzhi","ling zhi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "ǳ��ɫ��һ����֥�ݣ�ɢ�������˵���Ϣ��\n");
		set("value", 5000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	me->set("food", (int)me->max_food_capacity());

	me->add_maximum_force(5);
	me->add_maximum_mana(5);

	message_vision(HIG "$N����һ��"+MAG"��֥��"+HIG"���е�ȫ������˻����� \n" NOR, me);
  
	destruct(this_object());
	return 1;
}

