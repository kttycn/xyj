// zaizao

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( "[1;32m��[33m��[35m��[36m��[37m��[m", ({"zaizao wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ɫ���ͷ׵�ҩ�裬���ҩЧһ�������ء�\n");
                set("unit", "��");
                set("value", 1200);
                set("weight", 80);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "renshen"    : 1,
                                    "xuejie"     : 1,
                                    "heshouwu"   : 1,
                                    "shexiang"   : 1,
                                    "xiefen"     : 1,
                                    "fangfeng"   : 1,
                                    "moyao"      : 1,
                                    "dahuang"    : 1,
                                    "juhua"      : 1,
                                    "sanjia"     : 1,
                                    "dangui"     : 1,
                                    "gancao"     : 1 ]),
                        "force" : 300,
                        "gin"  : 50,
                        "time"  : 5,
                        "min_level" : 140,
                        "medical" : 200,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="zaizao wan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/zaizao") < 120)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        me->set_temp("last_eat/zaizao", time());

        message_vision(HIG "$N" HIG "����һ��" + name() +
                       HIG "��ֻ�����Լ��������һ���ˡ�\n", me);

        log_file("static/using", sprintf("%s(%s) eat �˲������� at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        my = me->query_entire_dbase();
        my["eff_sen"] = my["max_sen"];
        my["sen"] = my["max_sen"];
        my["eff_kee"] = my["max_kee"];
        my["kee"] = my["max_kee"];
        if (my["force"] < my["max_force"])
                my["force"] = my["max_force"];
        if (my["mana"] < my["max_mana"])
                my["mana"] = my["max_mana"];
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
