#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name( WHT"ˮ�½�"NOR , ({ "water sword", "sword" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ�������������£�������ˮ����ˮĸ�����֮�\n"
);
                set("value", 0);
                set("material", "steel"); 
                set("value", 30000);     set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�������ˮ������������\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/personality", 4);
                set("female_only", 1);
        }

    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
    set("is_monitored", 1);
        init_sword(80); 
        set("is_monitored",1);
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"WHT"ˮ�½�"NOR+"���ڵ��ϣ�ת�˼���Ȧ�ӣ���Ȼ��ʧ�ˡ�\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="Ů��")) return 0;
        if (random(8)<5) return 0;
        if ( !((string)victim->query("gender")=="Ů��")){
    victim->busy(random(1));
    return HIC "���������£�ӳ��$N�����绨��$n���ɵó��ˡ�\n" NOR;
      }
    return 0;
}
 

