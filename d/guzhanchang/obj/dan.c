// lingzhi.c ǧ�����
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
        set_name(HIR"���ϰ�ҩ"NOR, ({"bai yao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ������������ϰ�ҩ����˵��һ�ÿɵ�3wǱ�ܡ�\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query("tianlin-yao") >=1 )
        return notify_fail("�ٺٺٱ������ˣ�\n");

        this_player()->add("potential", 30000);
        message_vision("$N����һ�����ϰ�ҩ��ֻ�����Լ���������һЩ !\n", this_player());
        this_player()->add("tianlin-yao",1);
        destruct(this_object());
        return 1;
}


