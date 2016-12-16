// jpgp.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"��Ƣ��Ƭ" NOR, ({"jianpi gaopian", "gao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���Ƭ���Ե�����Ϣ�кܺõ��ô���\n");
                set("base_unit", "��");
                set("value", 7000);
		set("unit","��");
                set("weight", 60);
                set("only_do_effect", 1);/*
                set("mixture", ([
                        "herb" : ([ "baishu"  : 1,
                                    "lianzi"  : 1,
                                    "gancao"  : 1,
                                    "chenpi"  : 1, 
                                 ]),
                        "neili"               : 90,
                        "gin"                : 70,
                        "time"                : 4,
                        "min_level"           : 60,
                        "medical"             : 80,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
          object me=this_player();

        if( !arg || arg != "jianpi gaopian" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if ( time() - me->query_temp("last_eat/gaopian") < 60 )
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

        me->set_temp("last_eat/gaopian", time());

        message_vision(YEL "$N" YEL "ҧ��һ��" + name() +
                       YEL "����һ�ᣬ��ɫ�𽥺�ת��\n" NOR, me);

        me->receive_curing("kee", 60);
        me->receive_heal("gin", 60);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
