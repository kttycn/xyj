#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int cast(object me, object target)
{
	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
        return notify_fail("�㲻����ɽ���ɵ��ӣ������á�������Ԫ����\n");

	if( (int)me->query_skill("taoism",1)<30)
		return notify_fail("�����ʦ�ɷ���Ϊ̫ǳ������ʹ�á�������Ԫ����\n");

	if( (int)me->query_skill("zixia-shengong",1)<30)
		return notify_fail("�����ϼ����Ϊ̫ǳ������ʹ�á�������Ԫ����\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("mana") < 500 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	message_vision( HIW "$N������֮��Ϊ���ã�����������Ϊ֮һ��\n" NOR, me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/5 );
	me->add("force", -50);
	me->add("mana", -500);
	me->set("force_factor", 0);
	me->set("mana_factor", 0);

	return 1;
}
