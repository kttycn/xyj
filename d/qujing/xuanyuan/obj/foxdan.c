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
        set_name(GRN"�ɵ�"NOR, ({"fox dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ڹ�Ĺ�Ļ�¯����ȡ���ɵ���\n");
                set("no_give",1);
                set("no_steal",1);
        	set("no_sell",1);
        }
        setup();
}

int do_eat(string arg)

{

        object me = this_player();

        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if(arg=="dan")
                {
                        me->set("eff_gin",me->query("max_gin"));
                        me->set("gin",me->query("max_gin"));
                        me->set("eff_kee",me->query("max_kee"));
                        me->set("kee",me->query("max_kee"));
message_vision(HIR"$N���µ���һ�������ӵ������𣬶�ʱȫ�����������\n"NOR,me);
                }
                destruct(this_object());
                me->start_busy(2);
                return 1;
}
