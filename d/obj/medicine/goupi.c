//������Ƥ�ࣺ��Ʒ�������ڡ���ܺ��Ǽ����ϡ���ɽ�ס�Ѫ�ߡ����㡢ûҩ��
//��ʮ������ҩ�Ƴɡ��������ɢ�����澭��Ѫֹʹ�Ĺ��ܡ����η�ʪ��ʹ������
//��ľ����Ѫ��ʹ��֢�����������Է�ʪ�Լ����ʪ�Թؽ��ס��������˵ȡ�

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( YEL "��Ƥ��ҩ" NOR, ({"goupi gaoyao", "gaoyao"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ں����Ķ�������ҩ������ʮ�ֳ�����\n");
                set("base_unit", "��");
                set("value", 12000);
		set("unit","��");
                set("weight", 60);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "duanxu"           : 1,
                                    "shanjia"          : 1,
                                    "fangfeng"         : 1,
                                    "moyao"            : 1,
                                    "ruxiang"          : 1, 
                                 ]),
                        "neili"                        : 80,
                        "jing"                         : 50,
                        "time"                         : 3,
                        "min_level"                    : 20,
                        "medical"                      : 50,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
	object me=this_player();
	if( !arg || arg != "goupi gaoyao" )
	{
		write("��Ҫ��ʲôҩ��\n");
		return 1;
	}
        if (time() - me->query_temp("last_eat/goupi") < 20)
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

        me->set_temp("last_eat/goupi", time());

        message_vision(HIG "$N" HIG "��" + name() +"�������ϣ�"
                       HIG "˳���˿�������ȥ\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
