// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22
//By tianlin@Mhxy for 2002.1.27.���������

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"����ѩ��"NOR, ({"xue lian", "lian"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ�������������ѩ������˵��һ�ÿɵ�50�������ޡ�\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query("tianlin-xuelian") >=1 )
        return notify_fail("�ٺٺٱ������ˣ�\n");

        this_player()->add("maximum_force", 50);
        message_vision("$N����һ������ѩ����ֻ�����Լ���������������һЩ !\n", this_player());
        this_player()->add("tianlin-xuelian",1);
        destruct(this_object());
        return 1;
}


