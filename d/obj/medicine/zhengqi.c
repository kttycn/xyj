#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "����ˮ" NOR, ({"zhengqi shui", "shui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�ֺ����ص���ҩ����������������\n");
                set("unit","��");
                set("value", 100000);
                set("weight", 80);
              }
        setup();
}

void init()
{
        add_action("do_apply","apply");
}
int do_apply(string arg)
{
        mapping my;
        object me=this_player();

        object shibing=present("shi bing",environment(me));


        if( !arg || arg != "zhengqi shui" )
        {
                write("��Ҫʹ��ʲôҩ��\n");
                return 1;
        }

        if( !shibing )
                return notify_fail("����û��ʿ���ɡ�\n");

        if (time() - me->query_temp("last_eat/zhengqi") < 20)
        {
                write("����ҩû���𵽶����ô���\n");
                return 1;
        }

        me->set_temp("last_eat/zhengqi", time());

        message_vision( HIG "ֻ��$N��" + name() +"��ʿ����һ�����漣�����ˣ�
        �����е������������ˣ�\n", me);

        shibing->add("number",100+random(50));
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
