inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
	int mymana=me->query("mana"), cost=200, cure,spell;
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");
	if(me->is_busy())
		return notify_fail("����æ���أ������������ɣ�\n");
	spell=me->query_skill("spells")/2 + me->query_skill("buddhism");
	if(spell < 40)
		return notify_fail("��Ĵ�˷���Ч�ȼ���������\n"); //enable buddhism > 40

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("�㾫��ʵ�ڲ��ã�ֻ��һ�˷�����������Σ�գ�\n");
    
	if( mymana ) < 50)
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("��ľ����޷����У�\n");

	message_vision(HIW"$N�����˼��������ϥ���£���ʼ�������\n"NOR, me);
  
	cure=10 + (int)me->query_skill("spells")/5;
	if (me->query("eff_sen") < me->query("max_sen"))
	{
		if (cure > (me->query("max_sen") - me->query("eff_sen")))
			cure = me->query("max_sen") - me->query("eff_sen");
	}
	else cure=0;

	me->receive_curing("sen", cure);
    me->add("mana", -cost);
	return 1;
}

