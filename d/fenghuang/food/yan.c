#include "ansi.h"

inherit ITEM;
int do_eat(string);
void init();

void create(){
	set_name( HIW "����ѩ��" NOR , ({"yan"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ������ѩ�����̣���΢���ŵ�Щ��������\n");
		set("value",5000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	setup();
}

void init(){
	if (!wizardp(this_player())) {
		set("no_get","������һ�ɣ����̴�ָ�们�䣡\n");
		set("no_give","����Ǳ����������������ˣ�\n");
		set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
		set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	message_vision(HIG "$N���̺����ó�һ��ѩ���̷�����ߵ�ȼ��
ֻ��$N���������ͨ��,�����ˬ������,һ�����\n �³���һ����Ȧ��\n" NOR, me);
	destruct(this_object());
	return 1;
}
