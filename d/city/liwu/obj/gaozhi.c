

#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIW "��ҳ��ֽ" NOR, ({"gao zhi", "zhi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ҳ��ɮ�ù��ĸ�ֽ��������������(lingwu)��ʲô��\n");
                set("value", 20000);
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
	int exper,improve=0, kar;
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ����ʲô��\n"); 

	exper = me->query("combat_exp");
	kar = me->query("kar");
	
	if (exper<100000)
		improve = (10000*kar/20)+random(exper/50)+100;
	else if (exper<500000)
		improve = (10000*kar/20)+random(exper/100)+100;
	else if (exper<1000000)
		improve = (exper*kar/1000)+random(exper/200)+100;
	else
		improve = 100000+random(exper/500)+100;
     
	me->add("combat_exp",improve);
	message_vision(HIY"$N����һ�����ֽ��������ѧ�����������\n"NOR,me);
	destruct(this_object());
	return 1;	
}


