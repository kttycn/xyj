// shire.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "ʪ��������" NOR, ({"shire wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����ֻ��СС��һ��ҩ�裬�����������Ǻ���Ч�ġ�\n");
                set("unit", "��");
                set("value", 10000);
                set("weight", 50);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "honghua"  : 1,
                                    "dingxiang": 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1, 
                                  ]),
                        "neili"                : 70,
                        "jing"                 : 25,
                        "time"                 : 1,
                        "min_level"            : 50,
                        "medical"              : 80,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="shire wan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/shire") < 20)
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

        me->set_temp("last_eat/shire", time());

        message_vision(CYN "$N" CYN "�ſ��죬�͵�������" + name() +
                       CYN "������ĺ���һ����\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
