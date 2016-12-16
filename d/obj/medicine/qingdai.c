// qingdai.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "����ɢ" NOR, ({"qingdai san", "san"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ŵ���ɫҩ�裬����һ�ִ̱ǵ�ζ����\n");
                set("unit", "��");
                set("value", 15000);
                set("weight", 70);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "qingdai"   : 1,
                                    "bohe"      : 1,
                                    "bingpian"  : 1,
                                    "ercha"     : 1
                                  ]),
                        "neili"         : 100,
                        "jing"          : 60,
                        "time"          : 8,
                        "min_level"     : 100,
                        "medical"       : 100,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="qingdai san")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/qingdai") < 40)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        me->set_temp("last_eat/qingdai", time());

        message_vision(HIR "$N" HIR "����һ������ɢ��һ����������Ѩ������\n" NOR, me);

        my = me->query_entire_dbase();
        my["kee"] = my["max_kee"]*2;

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
