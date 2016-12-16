#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((string)me->query("family/family_name")!="�����"
	&& !me->query("guild") )
		return notify_fail("[����]ֻ�з�������˲���ʹ�á�\n");

	if( (int)me->query_skill("wuzu-xinfa", 1) < 50 )
		return notify_fail("��������ķ���򲻹���ʹ���������򡹡�\n");

	if( (int)me->query_skill("tenglong-finger", 1) < 40 )
		return notify_fail("�������ָ��������������ʹ�ù��򡹡�\n");

	if( (int)me->query("force") < 600 )
		return notify_fail("�������������\n");

    msg = HIM "
$N��ȫ��ÿ�����������ӿ������֮һ����Ϊ�������������ֱ��У���\n"NOR+HIY"
�ۿ����������ۣ����Ե�����ȴԽ��Խ�죬�����ľ�����$N�����������������ֱ��
��Ȼ���죬��Ȼͬʱ��Ȼ�ı��ѿ����������ִ�������ʵ��һ��Ĺ�����˺�ѿռ���
��$n�񱼶�ȥ����\n"NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
		me->start_busy(5);
		damage = (int)me->query_skill("yinyang-zhang", 1)*2+(int)me->query_skill("wuzu-xinfa",1);
		damage = damage/3 + random(damage);
		msg += HIR"
�������֮�£�$n���ϱ�$N����һ����ھ�˲�����ɣ����ɹ�����Ȼ �Ļ�����$n�����ϡ�\n"NOR;
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/(random(3)+1));
		me->add("force", -400);
	} else {
		me->start_busy(3);
		msg += HIC"����$p������$P����ͼ��������һ�ߡ�\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

