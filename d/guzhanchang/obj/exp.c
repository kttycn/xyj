// lingzhi.c ǧ�����
//����(lywin)2000/4/22
//By tianlin@Mhxy for 2002.1.27.���������

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"�Ǻ�«"NOR, ({"tang hulu", "hulu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ����������Ǻ�«����˵��һ�ÿɵ�2000��ѧ��\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query("tianlin-hulu") >=1 )
        return notify_fail("�ٺٺٱ������ˣ�\n");

        this_player()->add("combat_exp", 2000);
        message_vision("$N����һ���Ǻ�«��ֻ�����Լ���������һЩ !\n", this_player());
        this_player()->add("tianlin-hulu",1);
        destruct(this_object());
        return 1;
}


