// steal.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, obj, victim;
	int sp, dp;
//2001.06.20 fei add
	if (me->is_busy() || me->query_temp("doing_xiudao") 
	|| me->query_temp("pending/exercising")
	|| me->query_temp("pending/meditating"))
   		return notify_fail("��������æ���ء�\n");
	if( !wizardp(me) && environment(me)->query("no_fight")
	||environment(me)->query("no_steal")
	||environment(me)->query("sleep_room") )
		return notify_fail("�����ֹ���ԡ�\n");

	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");
	if( me->query_temp("stealing") )
		return notify_fail("���Ѿ����һ��������ˣ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

	if( victim = present(who, environment(me))) {
		if( userp(victim)&& userp(me) && victim->query("age")<16 )
			return notify_fail("��С���ӵĶ�����͵����̫û������!\n");
	}

	if((int)me->query("friends/"+victim->query("id")) )
		return notify_fail("������ĺ�����ѽ�������Ǳ�����壡\n");

	if (userp(victim) && !query_heart_beat(victim))
	{
		write("�����һ�㣬�ǲ����ǻ��\n");
		return notify_fail("������������\n");
	}
	if( !victim || victim==me) return notify_fail("�������ԵĶ��������\n");
	if(!valid_kill(me,victim,0)) return 0;

	if(me->query("daoxing")<100000 && userp(victim))
  		return notify_fail("��ĵ�����ô�����ȥ͵���˵Ķ�����\n");

	if(me->query("combat_exp") <= 100000 && userp(victim))
		return notify_fail(HIR"������ô�����ѧ��͵������?\n"NOR);

	set_to_killer(me,victim);

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");

	if(victim->query("disable_type")=="<˯����>")
		return notify_fail("���˼�˯����ʱ�����֣��ٺ٣���Ҳ̫ȱ���ˣ�\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲôֵǮ�Ķ�����͵��\n");
		ob = inv[random(sizeof(inv))];
	}
	sp = (int)me->query_skill("stealing",1) * 5 +((int)me->query("kar")+(int)me->query("age"))*2
		- (int)me->query("thief") * 20;
	if( sp < 1 ) sp = 1;
	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = ((int)victim->query("sen")+(int)victim->query("age")+(int)victim->query_kar())*2+(int)ob->weight()/25;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");

	me->set_temp("stealing", 1);
	me->add("steal_times",1);
	call_out( "complete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void complete_steal(object me, object victim, object ob, int sp, int dp)
{
    int no_steal;

        if(!me || !victim) return;
	me->delete_temp("stealing");

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
		return;
	}

        if(!ob) {
	  tell_object(me, "��Ҫ͵�Ķ��������ˡ�\n");
	  return;
        }

	no_steal=(ob->query("no_give")) ||
	         (ob->query("no_drop")) ||
	         (ob->query("keep_this",1)) ||
		 (ob->query("no_get"));

	if( (!living(victim) || (random(sp+dp) > dp)) &&
	 !no_steal ) {
		if( !ob->move(me) ) {
			tell_object(me, "������һ" + ob->query("unit") + ob->name() 
				+ "�����Ƕ������̫���ˣ����ò�������\n");
			return;
		}
		tell_object(me, HIW "�����ˣ�\n\n" NOR);
		tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");
		message("channel:chat",HIR"��ҥ������ĳ�ˣ�"+"�����ۿ��� "HIY+me->query("name")+HIR" �������ش� "
		HIY+victim->query("name")+HIR" ����͵���� "HIW"һ"+ ob->query("unit")+ ob->name()+" \n"NOR,users());
		me->add("thief", 1);

		if( living(victim) )
			me->improve_skill("stealing", random(me->query("int")));
		if( random(sp) < dp/2 )
			message("vision", "�㿴��" + me->name() + "�������ش�"
				+ victim->name() + "����͵����һ" + ob->query("unit")
				+ ob->name() + "��\n", environment(me), ({ me, victim }) );
	} else {
		if( random(sp) > dp/2 || no_steal ) {
			tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
				"���ã�û�б����֡�\n");
			return;
		}
		tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
		message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
			+ "$N�ȵ�������ʲô����\n\n", victim, me);
		me->improve_skill("stealing", 1, 1);
		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(5);
		me->add("thief", 1);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, ������ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
