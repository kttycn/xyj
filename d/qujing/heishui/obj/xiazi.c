#include <ansi.h>
inherit ITEM; 
int do_open(string arg);

void create()
{
        set_name("�����ϻ", ({"box", "yu xia"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"����һ��ȫ������ɣ������������װ�ε���ϻ���Ǻ�ˮ����
�����õĺ������䣬����Ӧ����һ���ţ�����Դ�(open)������\n");
                set("unit", "ֻ");
                set("open_count", 1);
                set("weight", 1000);
        }
}

void init()
{
        add_action("do_open","open");
} 

int do_open(string arg)
{
        object ob, me = this_player(); 
        if (!arg || (arg != "box" && arg != "xiazi"))
                return notify_fail("��Ҫ��ʲô��\n");
        if (query("open_count") > 0)
        {
                message_vision(HIW
"$N�������ϻ������ȡ��һ��������\n" NOR, this_player());
                add("open_count", -1);
                ob = new("/d/qujing/heishui/obj/tie");
                ob -> move(me);
                return 1;
        }
        else return notify_fail("�����ϻ�Ѿ������˴򿪹��ˡ�\n");
}

