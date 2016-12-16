#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j,damage;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ����˭��\n");

	if(me->query("family/family_name")!="�Ϻ�����ɽ"
	&& !me->query("guild") )
		return notify_fail("���Ƿ��ŵ��Ӳ����á������������\n");

	if(!me->is_fighting())
		return notify_fail("����û���ڴ�ܣ�\n");

	if((int)me->query("max_force") < 800 )
		return notify_fail("����ڹ�̫�\n");

	if((int)me->query("force") < 200 )
		return notify_fail("����������㣡\n");
//	if (!objectp(weapon = me->query_temp("weapon"))
//        || (string)weapon->query("skill_type") != "staff")
//                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if((int)me->query("sen") < 500 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("buddhism", 1) < 60)
		return notify_fail("��Ĵ�ɷ𷨵ȼ�����������ʹ����һ�У�\n");
	i=(int)me->query_skill("lunhui-zhang",1)+me->query_skill("staff",1)/2;
	j=(int)me->query_skill("lunhui-zhang",1);
	if(i<60 || j<1)        
		return notify_fail("����ֻ��ȼ��𻹲�����ʹ����һ�л������ѣ�\n");
	
	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIY"\n$N���з�ţ���ȫ����ע������"+weapon->name()+NOR+HIY"��ʱ��ϼ�����䣬�յ�$n�������ۣ�\n\n"NOR,me,target);
	damage=me->query_skill("buddhism")/2 + me->query_skill("staff")/2 + me->query_skill("lunhui-zhang") + me->query("max_force");
	target->receive_damage("kee",damage/15);
	me->receive_damage("sen", 100);
	me->add("force", -200);
	me->receive_damage("kee", damage/10+random(3));
	COMBAT_D->report_status(target);
	COMBAT_D->report_status(me);
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	me->start_busy(3);
	return 1;
}
