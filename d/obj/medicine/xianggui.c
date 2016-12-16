// xianggui.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( GRN "����Ѫ��" NOR, ({"xianggui gao", "gao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ������Ȼֲ���Ƴɵĸ�ҩ��\n");
                set("unit", "ƿ");
                set("value", 15000);
                set("weight", 60);
set("base_unit","ƿ");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "juhua"      : 1,
                                    "taoxian"    : 1,
                                    "bingpian"   : 1,
                                    "gancao"     : 1,
                                    "moyao"      : 1,
                                    "chenpi"     : 1, 
                                  ]),
                        "neili"                  : 90,
                        "jing"                   : 50,
                        "time"                   : 3,
                        "min_level"              : 20,
                        "medical"                : 50,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="xianggui gao")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/xgg") < 20)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("�����ھ���״̬�ܺã��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/xgg", time());

        message_vision(HIG "$N" HIG "��" + name() +"�������ϣ�"
                       HIG "˳���˿ڷ�����ȥ\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
