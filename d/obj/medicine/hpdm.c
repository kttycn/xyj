// hpdm.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG"���������" NOR, ({"duomei wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������ʧ�ߵ�ҩ��\n");
                set("base_unit", "��");
                set("value", 5000);
                set("unit","��");
                set("weight", 80);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "hupo"       : 1,
                                    "gsliu"      : 1,
                                    "hafen"      : 1,
                                    "honghua"    : 1,
                                    "dangui"     : 1,
                                    "fuzi"       : 1 
                                 ]),
                        "neili"                  : 100,
                        "jing"                   : 50,
                        "time"                   : 5,
                        "min_level"              : 80,
                        "medical"                : 100,
                                ]));*/
           }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if( !arg || arg != "duomei wan" )
         {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
          }       

        if( random(4) == 1)
        {
        tell_object(me,"�����㳤�ڷ�����������裬���ڵĻ��������ˣ�\n");
        me->unconcious();
        return 1;
        }        
       if ( time()-me->query("last_sleep" ) > 120 )
                return notify_fail("������Ͳ���Ҫ�˷�ҩ���� \n");

        message_vision(HIG "$N" HIG "����һ��" + name() +
                       HIG "��ֻ���û����˯��\n", me);
       
        tell_object(me,"����������Ҹ�����˯���ĵط�ȥ�ˡ�\n");
       
        me->delete("last_sleep");
        destruct(this_object());
        return 1;

}
