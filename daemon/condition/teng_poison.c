#include <ansi.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
	me->receive_wound("sen", 20);
	me->receive_damage("kee", 20);
	me->apply_condition("teng_poison", duration - random(5));
	tell_object(me, HIG "���е�" HIR "Ѫ���ٶ���" HIG "�����ˣ�\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}

