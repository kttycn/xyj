// /daemon/class/shushan/taoism/shou.c ����̽����

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	object thing,*inv;

	if( !target ) target = offensive_target(me);
	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
        return notify_fail("�㲻����ɽ���ɵ��ӣ������á�����̽���֡�?\n");
	if( (int)me->query_temp("feilong") )
		return notify_fail("���Ѿ���æ���ˡ�\n");
	if ( objectp(me->query_temp("weapon")) )
		return notify_fail("�������֡�\n");
	if( !target || !target->is_character() || !me->is_fighting(target) )
	return notify_fail("������̽���֡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("unarmed",1) < 80
	&& me->query_skill("hunyuan-zhang",1) < 50 )
		return notify_fail("��Ļ�Ԫ����Ϊ̫ǳ������ʹ�á�����̽���֡���\n");
	if( (int)me->query_skill("dodge",1) < 80
	&& (int)me->query_skill("seven-steps",1)<50 )
		return notify_fail("����Ṧ�������ݣ�����ʹ�á�����̽���֡���\n");

	if( (int)me->query("force",1)<50)
		return notify_fail("�����ڷ���̫��������ʹ�á�����̽���֡���\n");

	msg = HIM "$NͻȻ����һչ��ʹ��������̽���֡���$n������ȥ��\n"NOR;

	if(random(me->query_skill("dodge",1)+me->query_skill("unarmed",1))>target->query_skill("dodge",1))
	{
		me->start_busy(3);
		target->start_busy(random(3));
		me->add("force",-random(20));
		inv=all_inventory(target);
		if(!sizeof(inv))	{
			msg +=HIW"$n���Ͽտ���Ҳ��$NʲôҲû��̽������\n"NOR;
		}
		else {
			thing=inv[random(sizeof(inv))];
			thing->move(me);
			msg +=HIM"$Nʹ������̽���ֵľ���, $n��ʱ������ǰһ����$N���ֿտգ���$n���ϵõ�"+thing->query("unit")+thing->query("name")+"��\n"NOR;
		}
	} else 
	{
		me->start_busy(1);
		msg += HIW"����$n������$N����ͼ������һ�����˿�ȥ��\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}
