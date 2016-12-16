#include <ansi.h>

int main(object me, string arg)
{
	object obj;
	int skill, count;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("����͵Ϯ˭��\n");

	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���Ѿ���ս�����ˣ�����͵Ϯ��\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "���Ѿ������ˣ��㻹�õ���͵Ϯ��\n"); 

	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");

	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("������ĺ�����ѽ�������Ǳ�����壡\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("�㲻��ɱ����ˡ�\n");

	if(obj==me)
		return notify_fail("͵Ϯ�Լ�������ô�벻����\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ�����͵Ϯ��\n");

	if(userp(obj)) {
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
	}

	tell_object(me, RED"�������������" + obj->name() +"��\n"NOR);
	tell_object(obj, CYN"\n" + me->name() + "��Ȼ����������\n\n"NOR);
	message("vision", CYN"\n" + me->name() + "��Ȼ��" + obj->name() +"��ȥ��\n\n"NOR, environment(me), ({me, obj}) );

	count = me->query_str();

	if( random(me->query("combat_exp")) < (int)obj->query("combat_exp")/2 )
	{
		me->add_temp("str", count*4);
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		me->add_temp("str", - count*4);
	}

	else
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	}

	me->start_busy(3);
	obj->kill_ob(me);

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : touxi <����>
 
���ָ�����������͵Ϯ��͵Ϯ����ʱ���������������
�ر��ʺ��ھ���͵��������ߵ����������:)

�������ָ��: fight, kill, hit
HELP
    );
    return 1;
}
