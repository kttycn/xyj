//��ţ��������:��Ʒ�ɾ����롢���硢���ɡ��ջ��������ӡ����̡��۹�����
//�ˡ��������ưء����ӡ���ơ���Ƭ����ʯ�ࡢ���ˡ����ơ����������ʲ���
//�ɡ�

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG "ţ��������" NOR, ({"shangqing wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ֳ�����ҩ�裬��������Ѫ��\n");
                set("unit", "Ƭ");
                set("value", 10000);
		set("base_unit","Ƭ");
                set("weight", 50);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "niuhuang"  : 1,
                                    "bohe"      : 1,
                                    "juhua"     : 1,
                                    "gancao"    : 1,
                                    "liankeeao"  : 1,
                                    "fangfeng"  : 1,
                                    "bingpian"  : 1,
                                    "huanglian" : 1,
                                  ]),
                        "neili"                 : 90,
                        "jing"                  : 65,
                        "time"                  : 1,
                        "min_level"             : 40,
                        "medical"               : 70,
                               ]));*/
        }
        setup();
}

int do_eat(string arg) 
{
	object me=this_player();
	if( !arg || arg !="shangqing wan" )
	{
		write("��Ҫʹ��ʲôҩ��\n");
		return 1;
	}
        if (time() - me->query_temp("last_eat/nhsq") < 20)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if (time() - me->query_temp("last_eat/nhsq") < 20)
        {
                write("�����ھ���״̬�ܺã��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/nhsq", time());

        message_vision(HIW "$N" HIW "����һƬ" + name() +
                       HIW "֮�󣬿���ȥ����ö��ˡ�\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
