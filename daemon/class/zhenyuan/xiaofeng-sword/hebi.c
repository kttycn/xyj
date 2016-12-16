// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// ˫�����

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, object victim, int amount);
int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
   int skill, skill1, skill2;
   object weapon, victim = offensive_target(me);
   if ((string)me->query("class")!="xian"
	&& !me->query("guild") )
   return notify_fail("ֻ���ɼҵ��Ӳ���ʹ��˫�����!\n");
   if (!victim) return notify_fail("�����˭���С�˫����赡���\n");

   if( !target )
     return notify_fail("������˭���С�˫����赡���\n");
   if( target->query("id") == me->query("id") )
     return notify_fail("�������Լ����С�˫����赡���\n");
   if( victim->query("id") == target->query("id") )
     return notify_fail("��������Ķ��ֽ��С�˫����赡���\n");
   if( !victim->is_character() || !me->is_fighting(victim) )
     return notify_fail("ֻ�ܶ�������ս���еĶ���ʹ�á�˫����赡���\n");
   if( !target->is_fighting(victim) )
     return notify_fail("��Ĵ���������ս���С�\n");
   if( !objectp(weapon=target->query_temp("weapon")) ||
     (weapon->query("apply/skill_type") != "sword" &&
     weapon->query("skill_type") != "sword" ) || 
     target->query_skill_mapped("sword") !="snowsword" )
     return notify_fail("��Ĵû����ʹ�÷��ѩ�轣��\n");
   if( (int)target->query_temp("qifei") )
     return notify_fail("���ͬ���Ѿ����㡸˫����赡��ˡ�\n");
   if( (int)me->query_temp("qifei") )
     return notify_fail("���Ѿ���ͬ�顸˫����赡��ˡ�\n");
   if((int)me->query("force") < 25+(int)me->query("force_factor") )
     return notify_fail("�������������\n");
   if((int)me->query("kee") < 100 )
     return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
   if((int)target->query("force") < 25+(int)me->query("force_factor") )
     return notify_fail("��Ĵ����������\n");
   if((int)target->query("kee") < 100 )
     return notify_fail("��Ĵ��Ѫ���㣬û����ʩ���⹦��\n");

   if( !(int)target->query_temp("qifei_request") ) {
     me->set_temp("qifei_request", 1);
     tell_object(target, me->query("name")+"���㷢����˫����赡�����\n");
     return 1;
   }
   target->delete_temp("qifei_request");

   me->add("force", -25-(int)me->query("force_factor"));
   target->add("force", -25-(int)me->query("force_factor"));
   me->receive_damage("kee", 100);
   target->receive_damage("kee", 100);

   skill1 = target->query_skill("xiaofeng-sword", 1);
   skill2 = me->query_skill("snowsword", 1);
   skill = (skill1 + skill2);
   message_vision(HIY
     "$N��$n���б����໥һ������Χ����һƬ��Ӱ��ѹ��"
     + victim->query("name") + "��������������������ȫ��ʧȥ���·���\n"
     NOR, me, target);
   me->add_temp("apply/attack", skill);
   me->add_temp("apply/dodge",  skill);
   me->set_temp("hebi", 1);
   target->add_temp("apply/attack", skill);
   target->add_temp("apply/dodge",  skill);
   target->set_temp("hebi", 1);

//   me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill :), 1);
   call_out("check_fight", 1, me, target, victim, skill);

   return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
   object weapon;

   if( !living(victim) || !present(victim->query("id"), environment(me)) ) 
     remove_effect(me, target, amount);

   else if(   !present(victim->query("id"), environment(me)) 
     || !target->is_fighting(victim)
     || !present(target->query("id"), environment(me)) 
     || !me->is_fighting(victim) ) 
     remove_effect(me, target, amount);

   else if( !objectp(weapon=me->query_temp("weapon")) ||
     (weapon->query("apply/skill_type") != "sword" &&
     weapon->query("skill_type") != "sword" ) || 
     me->query_skill_mapped("sword") != "xiaofeng-sword" )
     remove_effect(me, target, amount);

   else if( !objectp(weapon=target->query_temp("weapon")) ||
     (weapon->query("apply/skill_type") != "sword" &&
     weapon->query("skill_type") != "sword" ) || 
     target->query_skill_mapped("sword") != "snowsword" )
     remove_effect(me, target, amount);

   else call_out("check_fight", 1, me, target, victim, amount);
}

int remove_effect(object me, object target, int amount)
{
   me->add_temp("apply/attack", -amount);
   me->add_temp("apply/dodge", -amount);
   target->add_temp("apply/attack", -amount);
   target->add_temp("apply/dodge", -amount);
   me->delete_temp("hebi");
   target->delete_temp("hebi");
   message_vision(GRN"$N��$n�ġ�˫����赡���ʽһ�գ���һ���ŵ�ɱ����ʱ��ʧ����Χ����Ҳ������һ������\n"NOR, me, target);
   return 0;
}

