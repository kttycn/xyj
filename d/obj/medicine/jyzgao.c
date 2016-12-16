// jyzgao.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIY "��ӣ�Ӹ�" NOR, ({"jinyingzi gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ֽ��ɫ�ĸ�ҩ�������������ˡ�\n");
                set("base_unit", "ƿ");
                set("base_value", 11000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "jinyingzi"  : 1,
                                    "water"      : 1,
                                 ]),
                        "neili"                  : 70,
                        "jing"                   : 25,
                        "time"                   : 1,
                        "min_level"              : 50,
                        "medical"                : 80,
                               ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/jyz") < 80)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/jyz", time());

        message_vision(CYN "$N" CYN "���˴�ͿĨ��һЩ" + name() +
                       CYN "����ʱ����һ������ֱͨ��Ƣ��\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
