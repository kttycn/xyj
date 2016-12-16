//stone created 20020307
//����һ����
inherit SSERVER;

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//inherit F_CLEAN_UP;

//int exert(object me, object target)
int perform(object me, object target)
{
	object weapon;
	object where=environment(me);
	int dayphase;
	dayphase =NATURE_D->query_current_day_phase();

	if( where->query("no_fight") )
		return notify_fail("��ȫ���ڲ�����������������\n");
	if (dayphase > 6)
		 return notify_fail("����һ��ֻ�а������ʩչ��\n");
	if( !me->is_fighting() )
		return notify_fail("����һ��ֻ����ս����ʹ�á�\n");
	if( me->query("family/family_name")!="�����"
	&& !me->query("guild") )
		return notify_fail("������һ�����Ƿ���ǵĲ���֮�أ�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("force") < 3000 )
	if( me->query_temp("phoenix-suimeng") )
		return notify_fail("���ʹ�꡸����һ�����ľ��У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
		
	if( (int)me->query("kee") < 200)
		return notify_fail("������������ˡ�\n");
//	if( (int)me->query("max_force") < 1200 )
//		return notify_fail("�������������㣬ʹ��������һ����\n");
	if( (int)me->query_skill("jile-dao", 1) < 290)
		return notify_fail("��ļ��ֵ�����Ϊ��������ʹ����һ�л������ѣ�\n");
                
	me->set_temp("phoenix-suimeng", 1);
	message_vision(HIC "\n$N����һ����Х�������������ֱ��������\n������ͬ��������ٲ������䲻����ȴ�Ѱ�����ǧ��εľ綯��\n\n"NOR, me);

	me->start_busy(3);
	if(me->query("force")>3000)
		call_out("perform1",3, me,target);
	else
		return notify_fail("�������������\n");
	return 1;
}

int perform1(object me, object target)
{
	message_vision(HIY "\n$N��������һ����͵Ĺ⻪�������İ�Χ�ŵ��С�\n\n"NOR, me);
	me->start_busy(4);
	call_out("perform2",4, me,target);
	return 1;
}

int perform2(object me, object target)
{
//	object *ob, where;	
	int i, skill, damage, force;
	object *ob
//	where=environment(me);
	skill = me->query_skill("force");
	force = me->query("max_force");
	me->set("force", 0);
	me->receive_damage("kee", 500);

	message_vision(HIY "\n��Ȼ$N�����ˡ�����һ����\n��ۺ�����ذ�����һ����Ҳ���ڻ���������۵�һ����\n�޴����ڵĿ����ڵ����Ĵ̼�֮��Ҳ�˱����ᡣ\n"NOR, me);
	message_vision(HIR "$p����Ѫ��Ⱦ���˵��С�\n"NOR, me);
	message_vision(HIM"������һ�������ĺ����𣬺����ˣ������м������ǵ�һģһ����\n\n"NOR, me);
//	ob = all_inventory(environment(me));
	ob = target
	for(i=0; i<sizeof(ob); i++) {
		if( !living( ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

		damage = ( skill + force) * 10 - ((int)ob[i]->query("max_force") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("sen", damage, me);
			if( (int)ob[i]->query("force") < skill * 2 )
				ob[i]->receive_wound("sen", damage/10, me);
				tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
		}
		COMBAT_D->report_sen_status(ob[i]);		
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	call_out("remove_effect",me->query_spi(), me); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) 
		return;
	me->delete_temp("phoenix-suimeng");
	tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á�����һ�����ľ����ˡ�\n"NOR); 
}
