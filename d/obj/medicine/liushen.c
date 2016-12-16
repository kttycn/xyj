//liushen.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIB"������" NOR, ({"liushen wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ֺܳ�����ҩ�裬�������Ʒ��ա�\n");
                set("base_unit", "��");
                set("unit", "��");
                set("value", 5000);
                set("base_weight", 50);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang"  : 1,
                                    "xiongdan"  : 1,
                                    "chansu"    : 1,
                                    "bingpian"  : 1,
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


int do_eat(string arg)
{
        int duration;
        object me=this_player();
        mapping my;

        if ( !arg || arg != "liushen wan" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }

        duration = me->query_condition("ill_zhongshu");
 
        my = me->query_entire_dbase();

        if ( duration = 0 )
        {
                write("�����ھ���״̬�ܺã��������" + name() + "��\n");
                return 1;
        }


        message_vision(HIW "$N" HIW "����һ��" + name() +
                       HIW "����ʱ���������˲��١�\n" NOR, me);

        me->apply_condition("ill_fashao", 0);

        me->receive_curing("kee", 50);
        me->receive_heal("gin", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
