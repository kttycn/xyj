// shendan.c ǧ����ĵ�
// stone 20020415
//add force +5

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//                set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
//		set("no_give","��ô����ҩ�����������ˣ�\n");
		set("no_drop","��ôϡ���䱦ǧ����ĵ������˶��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"���ĵ�" NOR, ({"shen dan","dan","shenxin dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", YEL"һ������ɫ�ĵ�ҩ��ɢ�����ɹɲ���ζ����˵���������ɵ�
��ǧ�������̫���Ͼ�ȡ�侫�����ڰ���ҩ¯������������
������ʮ������Ƴɣ����˷��ſ��������١�\n"NOR);
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
//	me->add_maximum_mana(4);

	message_vision("$N����һ��"+YEL"ǧ����ĵ�"NOR"������������䣣������ӡ�\n",me);
        tell_object(me, "��ֻ��һ������ֱ͸����......\n" NOR);
	destruct(this_object());
	return 1;
}

