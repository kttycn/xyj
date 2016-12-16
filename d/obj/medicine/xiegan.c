// xiegan.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "����к����" NOR, ({"xiegan wan", "wan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ��ҩ�裬�������ܿࡣ\n");
                set("unit", "��");
                set("value", 20000);
                set("weight", 60);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "lanhua"   : 1,
                                    "xuejie"   : 1,
                                    "yjhua"    : 1,
                                    "sumu"     : 1,
                                    "shancha"  : 1,
                                    "tiankee"   : 1,
                                    "lingxian" : 1,
                                 ]),
                        "neili"                : 100,
                        "gin"                 : 50,
                        "time"                 : 3,
                        "min_level"            : 70,
                        "medical"              : 100,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="xiegan wan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/xiegan") < 20)
        {
                write("���ǲ��ǲ�Ҫ���ˣ��ղŲ��ǲ�й����\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["food"] <= my["max_food_capacity()"]/4 && my["water"] <= my["max_water_capacity()"]/4)
        {
                write("�����ڼ���µµ�����ﻹ����ʲô" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/xiegan", time());
        message_vision(HIG "$N" HIG "һ�ھͰ�" + name() +"������ȥ��˵�����Ч"
                       HIG "$N����������й������\n" NOR, me);
        
        my["eff_kee"] = my["max_kee"];
        my["eff_gin"] = my["max_gin"];

        me->set("food", 10);
        me->set("water",10);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}
