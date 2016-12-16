
#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIR "�����κ�ɢ" NOR, ({"wulibahan san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һƬ��ɫ��ҩƬ�������ɢ������Ѫֹʹ�Ĺ�Ч��\n");
                set("base_unit", "Ƭ");
                set("value", 5000);
                set("weight", 50);
                set("unit","Ƭ");
        }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="wulibahan san")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/bahan") < 100)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }



        if ( !(me->query_condition("ill_shanghan")) )
         {
                write("��û�е��˺����������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/bahan", time());

        message_vision(HIW "$N" HIW "����һƬ" + name() +HIW "֮�󣬿���ȥ����ö��ˡ�\n" NOR, me);

        me->apply_condition("ill_shanghan", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
