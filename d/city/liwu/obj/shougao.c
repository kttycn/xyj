

#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
	set_name(HIW "��ж��ָ�" NOR, ({"shou gao", "gao","shou"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ж����ָ塣������������(lingwu)��ʲô��\n");
		set("value", 100000);
	}
	set("is_monitored",1);

	setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," �ٺ٣����ΰ�! \n");
        set("no_drop","��ô����Ķ�������������! \n");
        set("no_give","��̫�����˰ɣ�\n");
	}
	add_action("do_lingwu", "lingwu");
}

int do_lingwu(string arg)

{
	int exper, kar, improve=0;

	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ����ʲô��\n"); 

	exper = me->query("daoxing");
	if (exper<100000)
		improve = (10000*kar/20)+random(exper/50)+200;
	else if (exper<500000)
		improve = (10000*kar/20)+random(exper/100)+200;
	else if (exper<1000000)
		improve = (exper*kar/1000)+random(exper/200)+200;
	else
		improve = 100000+random(exper/500)+100;

	me->add("daoxing",improve);
	message_vision(HIY"$N���������һ���ָ壬���õ��д�������\n"NOR,me);
	destruct(this_object());
	return 1;	
}
