//jyhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(  HIY"��[1;37m��[32m��[36m¶[m" NOR, ({"jinyinhua lu", "lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һƿ���ƵĽ�����¶�������ȵ���һ�㶼��������Я������ҩƷ����\n");
                set("base_unit", "ƿ");
                set("unit","ƿ");
                set("value", 5000);
                set("weight", 50);
                set("only_do_effect", 1);/*
                set("mixture", ([
                        "herb"      : ([ "jyhua"  : 1, ]),
                        "neili"     : 80,
                        "jing"      : 35,
                        "time"      : 1,
                        "min_level" : 50,
                        "medical"   : 80,
                               ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
         object me=this_player();

        if( !arg || arg != "jinyinhua lu" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/jyhua") < 20)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();

        
        if ( !(me->query_condition("ill_zhongshu")) )
        {
                write("������û������������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/jyhua", time());

        message_vision(HIW "$N" HIW "Ĩ�˵�" + name() +"��̫��Ѩ��"
                       HIW "����ʱ�ж���ˬ���ˡ�\n" NOR, me);

        me->apply_condition("ill_zhongshu", 0);
        
        me->receive_curing("kee", 30);
        me->receive_heal("kee", 30);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
