// baoming.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "����������" NOR, ({"baoming dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ŵ��̵ĵ�ҩ�裬������������ҩ����Ч�����ޱȡ�\n");
                set("base_unit", "��");
                set("unit","��");
                set("value", 8000);
                set("weight", 80);
/*                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tianqi"   : 1,
                                    "xuejie"   : 1,
                                    "xuelian"  : 1,
                                    "lurong"   : 1,
                                    "xiefen"   : 1,
                                    "honghua"  : 1,
                                    "moyao"    : 1,
                                    "zzfen"    : 1,
                                    "heshouwu" : 1,
                                    "renshen"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,]),
                        "force" : 300,
                        "gin"  : 50,
                        "time"  : 5,
                        "min_level" : 140,
                        "shenlong-mixin" : 200,
                ]));
*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if( !arg || arg != "baoming dan" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/baoming") < 120)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        me->set_temp("last_eat/baoming", time());

        message_vision(HIG "$N" HIG "����һ��" + name() +
                       HIG "���۾�ֱð�̹⣡\n", me);
        tell_object(me, HIG "��һ�����ֻ���þ��������������㣬��������֮����\n" NOR);

        log_file("static/using", sprintf("%s(%s) eat ���������� at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        my = me->query_entire_dbase();
        my["eff_gin"] = my["max_gin"];
        my["gin"] = my["max_gin"];
        my["eff_kee"] = my["max_kee"];
        my["kee"] = my["max_kee"];
        if (my["force"] < my["max_force"])
                my["force"] = my["max_force"];

        me->start_busy(3);
        destruct(this_object());
        return 1;
}
