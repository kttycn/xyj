// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(YEL "��Ԫ��ɢ" NOR, ({"zhending san", "san"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ɫ�ķ�ĩ�������������Ч����\n");
                set("unit", "��");
                set("value", 50000);
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
                                    "zzfen"    : 1,
                                    "xuelian"  : 1,
                                    "lurong"   : 1, ]),
                        "neili" : 150,
                        "gin"  : 60,
                        "time"  : 5,
                        "min_level" : 120,
                        "medical" : 150,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if(! arg || arg!="zhending san")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/zhending") < 10)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_gin"] == my["max_gin"])
        {
                write("�����ھ���״̬�ܺã��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/zhending", time());

        message_vision(YEL "$N" YEL "һ���죬������" + name() +
                       YEL "������ȥ����ö��ˡ�\n" NOR, me);

        me->receive_curing("gin", 300);
        me->receive_heal("gin", 300);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
