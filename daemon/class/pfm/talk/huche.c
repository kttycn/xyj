#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;
	
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս���в���ʹ�á�\n");

	if( (int)me->query_skill("talk", 1) < 50 ) 
		return notify_fail("�����Ϊ�������ʹ������һ�У�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ���æ�ˣ���˵����Ư��Ҳ����ע�⵽��\n");

	message_vision(HIW"$N�ſ����죬�������������ģ��������������ģ�$n������գ�\n\n"NOR,me, target);

	mypot=(int)me->query_skill("literate");
	if(mypot >100)mypot =3;
	if(mypot >200)mypot =2;

	
        if ( random(5) > mypot ) {
                message_vision(HIR"$Nɵɵ�����㣬ͻȻѪ����ӿ���ۣ����³�һ����Ѫ��\n"NOR,target);
                target->set("kee",-1);
		me->set("kee",0);
	}else {
	message_vision(HIR"$N�ٺ�Ц���������������������ᣬ�����Ҷ�������ˣ�\n"NOR,target,me);
                me->start_busy(5+random(5));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}

