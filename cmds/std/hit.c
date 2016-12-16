// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;//, old_target;

	if (userp(me) && !query_heart_beat(me))
	{
		"/cmds/usr/quithy"->main(me);
		return notify_fail("������û�������������µ�½!!\n");
	}

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if (userp(obj) && !query_heart_beat(obj))
	{
		write("�����һ�㣬�ǲ����ǻ��\n");
		return notify_fail("������������\n");
	}
	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( me->query_temp("hitting") )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n"); 

	if(obj==me)	return notify_fail("���Լ�������ô�벻����\n");

	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("������ĺ�����ѽ�������Ǳ�����壡\n");

	if( userp(obj) ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N����$n���һ�������У�\n\n", me, obj);

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>
 
���ָ������ֱ����һ��������С���������ʽ��ս���Ǽ�ʱ�ģ�ֻҪ���һ
��������ս���ͻῪʼ��ֱ��ĳһ������50% ����Ϊֹ�����ָ�����Щ��
ϲ��fight��NPC�����ã���Ϊ�ܶ�ʱ����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: fight, kill

HELP
    );
    return 1;
}
 
