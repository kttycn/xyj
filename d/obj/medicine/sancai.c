// sancai.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"���ŷ��赤" NOR, ({"sancai dan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʮ������ҩ�裬�����ӹ��������洦��\n");
                set("unit", "��");
                set("value", 6000);
                set("weight", 50);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tiandong"  : 1,
                                    "renshen"   : 1,
                                    "gancao"    : 1,
                                    "guiwei"    : 1,
                                    "dangui"    : 1,
                                    "huangbo"   : 1,
                                 ]),
                        "force"                 : 150,
                        "jing"                  : 205,
                        "time"                  : 4,
                        "min_level"             : 150,
                        "medical"               : 180,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="sancai dan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query("last_eat/sancai") < 900)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["combat_exp"] <= 100000 )
        {
                write("�����ھ���̫�٣�����" + name() + "Ҳ��û�á�\n");
                return 1;
        }

        me->set("last_eat/sancai", time());

        message_vision(CYN "$N" CYN "����" + name() +
                       CYN "����ʱ������\n" NOR, me);

        me->add_maximum_force(3);
        me->add_maximum_mana(3);
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
