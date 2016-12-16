// baochi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIW "����һ����" NOR, ({"yili jin", "jin"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��Сҩ�裬���лָ�������Ч����\n");
                set("base_unit", "��");
                set("value", 10000);
                set("unit", "��");
                set("weight", 40);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang" : 1,
                                    "zhusha"   : 1,
                                    "beimu"    : 1,
                                    "hupo"     : 1,
                                 ]),
                        "neili"                : 80,
                        "jing"                 : 35,
                        "time"                 : 1,
                        "min_level"            : 50,
                        "medical"              : 80,
                                ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/ylj") < 100)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();

        if (my["kee"] >= 3*my["max_kee"]/4)
        {
                write("�������������棬�������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/ylj", time());

        message_vision(HIW "$N" HIC"��" + name() +"Ӳ������ȥ"
                       HIW "����ʱ���������������\n" NOR, me);
       
        me->set("kee","max_kee");
        me->start_busy(1);
        destruct(this_object());
        return 1;
}
