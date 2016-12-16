#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, object city, object who, int duration)
{
	if( duration < 1 )
	{
		tell_object(me, HIC "���һ�ֹ����Ѿ��������Ǳ����ɿ�Ȼ������\n" NOR );
		me->delete("attacking");
		city->delete("attacker");
		city->delete("receive_attack");
		return 0;
	}
	message_vision("�Ǳ��������ˣ�"+city->set("owner")+"���id��"+me->query("id")+"\n",who);
//	if( city->set("owner")!=me->query("id") ) {
	message_vision("$N��ʼ��$n�����˵�"+chinese_number(9-duration)+"�ν�����\n",
		me->query("name"),city->query("short"));
		COMBAT_D->do1_attack(me, city, who);
//	}
//	else {
//		return 0;
//	}

   me->apply_condition("fight_city", duration - 1);

   return CND_CONTINUE;
}
