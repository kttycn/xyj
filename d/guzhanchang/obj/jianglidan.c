// jianglidan1.c ������
//By tianlin@Mhxy for 2002.1.27.���������

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô����Ľ���������������! \n");
       
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIM "������" NOR, ({"jiangli dan", "dan"}));        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���������������ܹ�������,���ѵõ��鵤��ҩ!\n");
                set("value", 100);
        }

        set("is_monitored", 1);
        setup();
}
                       
int do_eat(string arg)
{
        object victim = this_player();

        if( (int)victim->query("combat_exp")+(int)victim->query("daoxing") > 0 )
        {
                message_vision(HIG "\n$N����һ��������,��Ȼ�е�һ��θ���Ͳ�û�ѳ���Ҳ���³���!\n\n" NOR, victim);
                destruct(this_object());                
                return 1;        }


        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query("tianlin-kof") >=1 )
        return notify_fail("�ٺٺٱ������ˣ�\n");

        victim->add("combat_exp", 38000+(int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points")+40000 );
        victim->skill_death_recover();

   victim->add("daoxing",14500+victim->query("death/dx_loss"));
        victim->save();

        if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N����һ��������,������һ����Ϣ����ȫ��,��ʱ�������,��������!\n\n" NOR, victim);
        this_player()->add("tianlin-kof",1);
        destruct(this_object());    
    return 1;
}