// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//
inherit SSERVER;
#include <ansi.h>;
int cast(object me, object target)
{
	if( !target ) target = offensive_target(me);

     if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("����ݡ�ֻ�л��ƶ����˲ſ����ã�\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");
	if( (int)me->query("sen") < 100 )
		return notify_fail("��ľ����޷����У�\n");
	message_vision(HIR"$NĬ�˻�ħ�ķ�,��������ת��,������ɫͨ��,�ſ����һ���һ�\n"NOR, me);
	if(me->is_fighting() ) {
		if(random((int)me->query("max_mana")) >(int)target->query("max_mana")/2)
		{
			message_vision(HIR"$N�����һ�,����һ�����,Ʈ����������ȥ������\n"NOR, me);
			me->receive_damage("sen", 100);
			me->move("/d/city/kezhan");
		}
		else
			message_vision(HIY"$N����仯���ǻ����������Ϩ��!!\n"NOR, me, target);
		me->receive_damage("sen", 100);
	}
	if(!me->is_fighting() )
	{
		message_vision(HIR"$N�����һ�,����һ�����,Ʈ����������ȥ������\n"NOR, me);
		me->receive_damage("sen", 100);
		me->move("/d/city/kezhan");
	}
//        me->start_busy(1+random(2));
	return 5+random(5);
}

