//zhanlong.c ն����
#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
	object weapon;
	int i,j,damage,p;
	string msg;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʹ�ã�ն�����ݣ�\n");

	if(!me->is_fighting())
		return notify_fail("����û���ڴ�ܣ�\n");

	if(me->query("family/family_name")!="��ɽ����"
	&& !me->query("guild") )
		return notify_fail("������ɽ�Ĳ����á�ն��������\n");

	if((int)me->query("max_force") < 400 )
		return notify_fail("����ڹ�̫�\n");
	if((int)me->query("force") < 200 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if((int)me->query_skill("taoism", 1) < 50)
		return notify_fail("�����ʦ�ɷ��ȼ�����������ʹ�ã�ն�����ݣ�\n");
	i=(int)me->query_skill("yujianshu",1);
	j=(int)target->query_skill("dodge",1);
	if(i<75)        
		return notify_fail("��Ľ������𻹲�����ʹ����һ�л������ѣ�\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIW"\n$N����������¾������ԣ�"NOR,me,target);
	message_vision(HIW"\n�����񣬽���ף�����⣬ͬ�䳾"NOR,me,target);
	message_vision(HIW"\n���н���һ��������$n������",me,target);
	if (random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/3) {
//		message_vision(HIR"\n\n$n����΢΢һ�Σ���ɫ�԰������\n"NOR,me,target);
		damage=i+random(i);
		target->add("force",-damage);
		target->receive_damage("sen",damage);
		p = (int)target->query("sen")*100/(int)target->query("max_sen");
		msg = HIR"\n\n"+damage_msg(damage, "����")+NOR;
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		if ((int)target->query("force")<0) target->set("force",0);
		else target->add("force", -random(damage));
		if ((int)target->query("mana")<0) target->set("mana",0);
		else target->add("mana",-random(damage));
		if ((int)me->query("force")<0) me->set("force",0);
		me->receive_damage("sen", 100);
		message_vision(msg,me,target);
	}
	else {
		message_vision(YEL"\n$n����ֻ��΢΢һ�Σ��·�������\n"NOR,me,target);
	}
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(2);
	return 1;
}
