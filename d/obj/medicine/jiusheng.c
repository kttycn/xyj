//jiusheng.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIB"��ʥɢ" NOR, ({"jiusheng san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ǳɫҩƬ������һ�ֵ�������ɫ��\n");
                set("base_unit", "��");
                set("base_value", 15000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "huangbo"   : 1,
                                    "xingren"   : 1,
                                    "bohe"      : 1,
                                    "ruxiang"   : 1,
                                    "moyao"     : 1,         
                                 ]),
                        "neili"                 : 40,
                        "jing"                  : 35,
                        "time"                  : 1,
                        "min_level"             : 40,
                        "medical"               : 60,
                               ]));
        }
        setup();
}

int do_effect(object me)
{
        mapping my;

        my = me->query_entire_dbase();

        if (time() - me->query_temp("last_eat/jss") < 20)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if ( my["eff_qi"] == my["max_qi"] )
        {
                write("��������ɫ�ܺã��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/jss", time());

        message_vision(HIW "$N" HIW "����һ��" + name() +
                       HIW "����ʱ��ɫ�ÿ��˲��١�\n" NOR, me);

        me->receive_curing("qi", 100);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}

