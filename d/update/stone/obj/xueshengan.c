#include <ansi.h>
inherit ITEM;

int do_eat(string);
void destroy();
void init();

void init()
{
	if(this_player()==environment())
		add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"ǧ��ѩ�θ�"NOR, ({"shen gan","xueshen gan", "gan"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ������ɫ��ǧ��ѩ�θɣ�������Կ�ή�������ʵ�ǧ��ѩ�θɿݺ��γɣ���Ч����ۿۡ�\n"NOR);
		set("value", 900000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if ((string)environment(me)->query("short")=="������" )
		return notify_fail("������ôΣ�ջ���ʲô��������\n");

	me->set("food", (int)me->max_food_capacity());
	me->add_maximum_mana(25);
	me->add_maximum_force(25);
	message_vision(YEL"$NС�ĵ�����ѩ�θɣ�����������С�$N����ɫ˲ʱ���ѩ�ף����ɻ�ʱ��$N����ɫ���𽥻ָ��˺���\n" NOR, me,);
//	me->unconcious();
	destruct(this_object());
	return 1;
}


