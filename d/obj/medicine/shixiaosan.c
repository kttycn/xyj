//ʧЦɢ

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIR "ʧЦɢ" NOR, ({"shixiao san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ֺ������ҩƬ����˵��������\n");
                set("unit", "Ƭ");
                set("value", 200000);
                set("weight", 50);
set("base_unit","Ƭ");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ 
                                    "shancha"  : 1,
                                    "xiefen"   : 1,
                                    "sumu"     : 1,
                                    "duhuo"    : 1,
                                    "gancao"   : 1,
                                    "heshouwu" : 1,
                                    "taoxian"  : 1,
                                  ]),    
                        "force"                : 200,
                        "jing"                 : 100,
                        "time"                 : 5,
                        "min_level"            : 100,
                        "medical"              : 190,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="shixiao san")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/shixiao") < 120)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }
        my = me->query_entire_dbase();

        if (my["max_kee"] >= 800 )
        {
                write("���Ѿ�����Ҫ�ٷ���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/shixiao", time());

        message("channel:chat", HIC+"������������"+my["name"]+"["+my["id"]+"]����Ҫ��ͣ��Ц������������������\n"+NOR, users() );
        message("channel:chat", HIC+"������������"+my["name"]+"["+my["id"]+"]����Ҫ��ͣ��Ц������������������\n"+NOR, users() );

        log_file("static/using", sprintf("%s(%s) eat ʧЦɢ at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        me -> unconcious();
        me->add_maximum_force( 5 );        
        me->start_busy(2);
        destruct(this_object());
        return 1;
}
        
