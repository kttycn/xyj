// whip.c

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name("��������", ({"yinsuo jinling", "whip"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ������ɫ�ĳ�����ϸ������׺���˽��壬����������Ȼ����һ��������\n");
                set("unit", "��");
//	set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 12000);
		set("wield_msg", "$N���������������һ������һ����ɫ�������˦�˳���\n");
		set("unwield_msg", "$N������$n��������\n");
		set("weapon_prop/courage", 20);
		set("no_sell",1);
		set("no_give", 1);
		set("no_put", 1);
        }
	set("is_monitored",1);
	init_whip(100);
	setup();
}
mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "��˿��"
                && me->query_skill("yinsuo-jinling",1) > 1)
    damage_bonus = me->query_skill("yinsuo-jinling",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIC"����"+HIY"����"+HIW"��ϼ��ӳ�䣡\n" NOR;

}

