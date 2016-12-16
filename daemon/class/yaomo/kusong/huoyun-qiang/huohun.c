//���
//requirement:huomoforce,huoyun-qiang all over 60

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_spear, skill_force, str_amount,attack_amount;

        if( !me->is_fighting() )
                return notify_fail("����꡹ֻ����ս����ʹ�á�\n");
               if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("����꡹������ϻ�ħ�ķ�����ʹ�á�\n");
     if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("����ꡱֻ�л��ƶ����˲ſ����ã�\n");
        skill_force=me->query_skill("huomoforce");        
        if (skill_force<60) return notify_fail("��Ļ�ħ�ķ��������졣\n");
        skill_spear=me->query_skill("huoyun-qiang");
        if (skill_spear<60) 
           return notify_fail("���ǹ��̫��ˡ�\n"); 
        if( (int)me->query("force") < 200 )      
                return notify_fail("�������������\n");
        if( (int)me->query_temp("huohun") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
        
        me->add("force", -100);
        message_vision(
                HIR"$N���һ����һ�ᵤ�����������ڱۣ�ǹ�ϼ�����ֻ��$N�����һ����أ�\n������һ������һ��������ǹ��,��˵������µ��ľ�����\n" NOR, me);
 
        attack_amount=skill_spear/5;
        str_amount=(skill_spear+random(skill_force))/5; 
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/strength",str_amount);    
        me->set_temp("huohun", 1);
              me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, str_amount,attack_amount:), skill_spear/5);
 
         return 1;
}
 
void remove_effect(object me, int str_amount,int attack_amount)
{
        me->add_temp("apply/strength", -str_amount);
        me->add_temp("apply/attack", -attack_amount);
        me->delete_temp("huohun");
        message_vision(HIR"$N�ջ����������һ���ľ�����ʧ�ˡ�\n"NOR,me);
}

