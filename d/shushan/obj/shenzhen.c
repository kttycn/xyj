//shushan2 by yushu 2000.12
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("��Ӱ����", ({"wuying shenzhen", "shenzhen", "zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("base_unit", "��");
                set("long",    "һ��ϸС����Ӱ���룬������ž綾��\n");
                set("base_weight", 5);
                set("value",10000);
        }
        set_amount(random(10)+1);
        init_throwing(40);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 0 ) return 0;
   victim->apply_condition("shenzhen_poison", 3);
   message_vision("$N������Ӱ�����ϵľ綾��\n", victim);
}

