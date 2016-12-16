// dieda.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(CYN "����������" NOR, ({"dieda gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�齺״�Ķ���������Ч���Ƚ�ҩҪ��һЩ��\n");
                set("unit","��");
                set("base_unit", "��");
                set("value", 10000);
                set("unit", "��");
                set("base_weight", 50);
                set("mixture", ([
                                    "chuanwu"  : 1,
                                    "honghua"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1, ]));
        }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
        my = me->query_entire_dbase();

        if(! arg || arg != "gao")
                {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/dieda") < 10)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if (my["eff_kee"] == my["max_kee"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/dieda", time());

        message_vision(CYN "$N" CYN "�ſ��죬�͵�������" + name() +
                       CYN "������ĺ���һ����\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
