#include <ansi.h>
//inherit SSERVER;
void select_target(object me, string name);

int cast(object me, object target)
{
	if( (string)me->query("family/family_name") != "�����" 
	&& !me->query("guild") )
		return notify_fail("�㲢�Ƿ�˳����ˣ��������÷�������\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ�÷�������\n");
	if( me->query_temp("pending/exercising") 
	|| me->query_temp("doing_xiudao") 
	|| me->query_temp("no_move") 
	|| me->is_busy() )
		return notify_fail("����һ��������û���꣬����ʹ�÷�������\n");
	if( !wizardp(me) && environment(me)->query("no_flying") )
		return notify_fail("���ﲻ׼ʩչ��������\n");

	if( (me->query("kee") < me->query("max_kee")/2)
	|| (me->query("gin") < me->query("max_gin")/2)
	|| (me->query("sen") < me->query("max_sen")/2) )
		return notify_fail("��ľ��񲻺ã������Ҵ�һ���ˡ�\n");
	if( me->query("mana") < 150 )
		return notify_fail("��ķ������㣡\n");
	if( target )
		return notify_fail("���������ܶ��Լ�ʹ�ã�\n");
	write("��Ҫ���ɡ�����һ������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{  
	int i=sizeof(name);
	object ob;
	if( !name || name=="" )
	{
		write("��ֹʩ����\n");
		return;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ��������NPC�����в����ÿո����Ч�ַ���\n");
			write("��ֹʩ����\n");
			return;
		}
	}
	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
	{
		write("���޷����ܵ�����˵ľ��� ....\n");
		write("��Ҫ���ɡ�����һ������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( userp(ob) )
	{
		write("�㲻����ʩչ�����������������ߡ�\n");
		return;
	}
	if( me->is_fighting() )
	{
		write("ս�����޷�ʹ�÷�������\n");
		return;
	}
	else
		if( me->query("mana") < 150 )
		{
			write("��ľ���������\n");
			return;
		}
	me->add("mana", -150);
	me->receive_damage("sen", 50);
	message_vision( HIW "$N˫����ӣ���������������ܶ�ʱ�������磬$N�¾�����趯����\n" NOR, me);
	if ( random( ob->query("max_mana") + (int)me->query("mana")) < 100 )
	{
		write("�Է��ľ�������ǿ�ң�����ܲ��������λ�á�\n");
		return;
	}
	if( random(me->query_skill("spells")) < (int)ob->query("mana") / 50 )
	{
		write("����Ϊ����������ʧ���ˡ�\n");
		return;
	}
	message( "vision", HIY "\nֻ��" + me->name()   + 
		"�¾����Ʈ�裬Ƭ�̼䣬��ͣ������$Nȴ��ʧ����Ӱ���٣�\n\n",    environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n������ͻȻ��������һ����Ӱ����������ǰ��\n\n" NOR,
		environment(ob), ({ me }) );
}
