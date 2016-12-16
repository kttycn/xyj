//hammer.c
//created by vikee
//2000.10

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_sanqing, skill_sword, skill_force,attack_amount,dodge_amount,skill_dodge;

        skill_dodge=me->query_skill("dodge");
		
     if(me->query("family/family_name") != "��ׯ��"
	&& !me->query("guild") )
                return notify_fail("[����Ϊ��]����ׯ�۲���֮�ܣ�\n");
		if(	!me->is_fighting())
			return notify_fail("������Ϊ����ֻ����ս���в���ʹ�á�\n");

		skill_sanqing = me->query_skill("sanqing-jian");            
        if (skill_sanqing<40)
			return notify_fail("�����彣���ȼ���������\n");

        if (me->query_skill_mapped("force")!="zhenyuan-force")
            return notify_fail("������Ϊ�������������Ԫ�񹦲���ʹ�á�\n");
               
        if((int)me->query_skill("kaishan-chui", 1) < 80)
            return notify_fail("��Ŀ�ɽ�����𻹲�����ʹ����һ�л������ѣ�\n");


        skill_force=me->query_skill("zhenyuan-force");        
        if (skill_force<40)
			return notify_fail("�����Ԫ�񹦲������졣\n");

        skill_sword=me->query_skill("sword");
        if (skill_sword<40) 
            return notify_fail("��Ļ�������̫��ˡ�\n"); 
        
                if( (int)me->query("force") < 50 )      
            return notify_fail("�������������\n");
        
		if( (int)me->query_temp("powerup") )
            return notify_fail("���Ѿ�����Ϊ���ˡ�\n");
        
        me->add("force", -50);
        message_vision(
                HIY"$N��ʽһת�����н�Խ��Խ�죬����Ϊ�������е�����\n" NOR, me);
         
        attack_amount=skill_sanqing/2;					//added by vikee . hmm... perhaps the 
		                                                //the damage is wrong.you can modify it
		                                                //as your wish.
        
		dodge_amount=skill_dodge*random(6)/10;

		me->add_temp("apply/damage",attack_amount);  
		me->add_temp("apply/dodge",-dodge_amount);      //use this perform ,reduce your effect dodge :P added by vikee
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me,dodge_amount,attack_amount:), skill_sanqing/20);
 
         return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
        me->add_temp("apply/damage", -attack_amount);
        me->add_temp("apply/dodge",dodge_amount);
		me->delete_temp("powerup");
		message_vision(
			HIY"$N������һ����,������ʽ.\n"NOR,me);
}

