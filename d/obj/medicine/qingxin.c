// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "���Ľⶾ��" NOR, ({"qingxin wan", "wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɫ�ķ�ĩ�����ѩɽ�Ķ��кܺõ�Ч����\n");
                set("unit", "��");
                set("value", 2000);
                set("weight", 60);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "xuejie"   : 1,
                                    "yjhua"    : 1,
                                    "xiongdan" : 1,
                                    "shancha"  : 1,
                                    "gsliu"    : 1,
                                    "zzfen"    : 1, ]),
                        "neili" : 100,
                        "gin"  : 50,
                        "time"  : 3,
                        "min_level" : 80,
                        "medical" : 100,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="qingxin wan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/qingxin") < 60)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();

        me->set_temp("last_eat/qingxin", time());

        message_vision(HIG "$N" HIG "һ���죬������" + name() +
                       HIG "������ȥ�����˲��١�\n" NOR, me);

      me->apply_condition("yz_poison", 0 );
      me->apply_condition("bp_poison", 0 );
 
       me->receive_curing("gin", 150);
        me->receive_heal("gin", 150);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
