
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������졹?\n");
        weapon = me->query_temp("weapon");
        if(!me->is_fighting(target))
                return notify_fail("��������졹ֻ����ս����ʹ��!\n");
	if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�"
	&& !me->query("guild") )
	    return notify_fail("�㲻��������壬������͵���Ĺ���\n");

        if((int)me->query("max_force") < 1500)
                return notify_fail("�������������\n");

   if((int)me->query("force") < 500 )
     return notify_fail("����������㣡\n");

if (!weapon || weapon->query("skill_type") != "sword"  )
    return notify_fail("�������ʹ�ñ���ʱ����ʹ�ã�\n");

        if((int)me->query_skill("qixiu-jian", 1) < 120)
        return notify_fail("������޽��ȼ�������!!\n");


    msg = MAG
"\n$N����һЦ,���е�"+weapon->name()+""+MAG"����һ��,��ʱ��ɳ��ʯ,����ֱ�����!!\n"NOR;
message_vision(msg, me, target);
   me->delete("env/brief_message");
   target->delete("env/brief_message");
        me->set_temp("QXJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));



        me->delete_temp("QXJ_perform");

        //me->receive_damage("sen", 100);
        me->add("force", -150);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(1));
        return 1;
}

