// hugu.c   �����˺���Ӧ�üӴ��˺���Σ����

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( GRN"���Ǿ�" NOR, ({"hugu jiu", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ɫ�Ļ��Ǿƣ��������˺������ƺܼ���Ч��\n");
                set("base_unit", "ƿ");
                set("value", 5000);
                set("unit","ƿ");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "hugu"      : 1,
                                    "renshen"   : 1,
                                    "duhuo"     : 1,
                                    "fangfeng"  : 1,
                                    "dangui"    : 1,
                                    "goujuzi"   : 1, 
                                 ]),
                        "neili"                 : 80,
                        "jing"                  : 35,
                        "time"                  : 1,
                        "min_level"             : 50,
                        "medical"               : 80,
                                ]));*/
             }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
       
        if ( !arg || arg != "hugu jiu" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/hugu") < 20)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();

       
        if ( !( me->query_condition("ill_shanghan")) )
        {
                write("������û���˺����������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/hugu", time());

        message_vision(HIW "$N" HIW "��ཹ�ཱུع�������" + name() +
                       HIW "������ȥ����ö��ˡ�\n" NOR, me);

        me->apply_condition("ill_shanghan", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
