#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name( HIY"��ԯ��"NOR , ({ "xuanyuan sword", "sword" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
HIY"����һ���ƽ�ɫ֮ǧ��Ž�����˵��������������ԯ�Ƶۻ���
���֮�����񽣣������̲�����֮����Ϊն����ħ��������\n" NOR
);
//              set("value", 0);
          	set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
		set("no_put", "����Ž�װ����������ȥ��\n");
		set("no_drop", "��ôϡ�������������������˶��ϧѽ��\n");
		set("no_give", "�����������а������������ˣ�\n");
		set("no_get", "�����������ͻȻ��ԯ���ֳ������⣬������һ����æ�������˻�ȥ��\n");
                set("material", "gold"); 
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg",HIY "ͻȻ���ܽ���ʢ���·��ɫ���⣬�������ǣ�����ϸ����ֻ��$N�����Ѷ���һ��$n��\n" NOR);
                set("unwield_msg", "���˲�䰵��,$N�����е�"HIY"$n"NOR+"��������Ľ��ʡ�\n");
                set("weapon_prop/personality", 8);
                set("male_only", 1);
        }

        set("is_monitored", 1);
        init_sword(180); 
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"YEL"��ԯ��"NOR+"���ڵ��ϣ�˲�����ʢ��ͻȻ����ʧ�ˡ�\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="����")) return 0;
        if (random(8)<2) return 0;
        if ( !((string)victim->query("gender")=="Ů��")){
    victim->busy(random(1));
//    return HIY "��ԯ���������ҫ�۵Ľ�⣬�����$N����������$n���ɵ�ս�ľ���\n" NOR;
    return HIY "$N������ԯ�������϶������ص�һ�ӣ���ԯ�����ֳ������ɫ��â�������������������$n��
��â����֮���·��������˵ľ����Ƶģ�$n�е�һ��ѣ�Ρ�\n" NOR;
//    return HIY "��â����֮�����·������˾���㣬$n������ս�ľ���\n" NOR;
			
			}
    return 0;
}
 

