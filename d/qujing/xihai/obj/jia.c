//EDIT BY LUCAS
#include <ansi.h>;
#include <armor.h>;
inherit EQUIP;


void create()
{
        set_name(HIW"��Ƥ��"NOR, ({"long pijia", "pijia"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"���ǵ��갽˳��פ����֮ʱ,�����̾��ڴ˵Ķ�����ս��Ʒ.\n"NOR);
                set("material", "cloth");
                set("armor_type", "cloth");
                set_weight(10); 
                set("armor_prop/armor", 10);
                set("armor_prop/force", 10); 
                set("armor_prop/dodge", 10); 
                set("no_put", 1); 
                set("wear_msg", HIY"$N����$n��"HIY"ͻȻ������Ѫ���ȣ�һ�������ӵ���������ȫ��\n"NOR);  
                set("unequip_msg", HIC"$N����$n."HIC"ֻ��ȫ�������ޱȣ�һ����ˬ��\n"NOR); 
        }
        setup();
}


