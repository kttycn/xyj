// xuelianzhi.c ��֥
// stone 20020415
//add force +3
//add mana  +3
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//                set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
//		set("no_give","��ô����ҩ�����������ˣ�\n");
		set("no_drop","��ô�����ѩ���ӣ����˶��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"ѩ����" NOR, ({"lian zhi","xuelian zhi","lianzhi"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", WHT"һ�ž�ӨԲ���ѩ���ӣ����Դ�ѩɽ�������ǧ��ѩ��
����Ĺ�ʵ��ʮ�ֺ��������ĵķ���һ��������Ƣ�����㡣\n"NOR);
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

	me->add_maximum_force(3);
	me->add_maximum_mana(3);

	message_vision("$N������Ƥ��С�İ�"+YEL"ѩ����"NOR"������У����̸е���ƽ���ͣ�����Ŀ����\n" NOR, me);
        tell_object(me, "ֻ��һ���������뵤�����̨......\n" NOR);
	destruct(this_object());
	return 1;
}

