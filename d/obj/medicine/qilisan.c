// qilisan.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( GRN "����ɢ" NOR, ({"qili san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��СҩƬ���������Ƶ������ˣ�������ʹ��\n");
                set("base_unit", "��");
                set("value", 12000);
		set("unit","��");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "shexiang"  : 1,
                                    "bingpian"  : 1,
                                    "moyao"     : 1,
                                    "xuejie"    : 1,
                                    "zhusha"    : 1,
                                 ]),
                        "neili"                 : 90,
                        "jing"                  : 50,
                        "time"                  : 1,
                        "min_level"             : 50,
                        "medical"               : 90,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="qili san")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/qili") < 20)
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

        me->set_temp("last_eat/qili", time());

        message_vision(CYN "$N" CYN "��" + name() +"�ŵ�����"
                       CYN "����ʱ���ͱ�ĺ��������ˡ�\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
