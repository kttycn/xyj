// huojin.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(MAG "�����Ѫ��" NOR, ({"huojin wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ҩ�裬���ֳ������ķ�ɫ������Ч����Ϊ����\n");
                set("base_unit", "��");
                set("value", 2000);
                set("unit","��");
                set("weight", 60);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "honghua"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1,
                                    "yjhua"    : 1,
                                    "heshouwu" : 1, 
                                  ]),
                        "neili"                : 80,
                        "jing"                 : 30,
                        "time"                 : 3,
                        "min_level"            : 80,
                        "medical"              : 90,
                                ]));*/
            }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if( !arg || arg != "huojin wan" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/huojin") < 80)
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

        me->set_temp("last_eat/huojin", time());

        message_vision(MAG "$N" MAG "С�ĵ�������" + name() +
                       MAG "����������������ɫ�������ö��ˡ�\n" NOR, me);

        me->receive_curing("kee", 350);
        me->receive_heal("kee", 350);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
