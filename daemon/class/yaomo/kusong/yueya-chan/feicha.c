#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void feicha_ok(object);
void postfeicha(object,object,object,int);

int perform(object me, object target)
{
	mapping feicha= ([
		"damage": 80,
		"dodge" : -10,
		"parry" : -10,
		"damage_type" : "����",
		"action" :  HIC"$w"+HIC"������������$n��$l��ȥ",
		"post_action" : (: postfeicha :)
	]);

	object weapon=me->query_temp("weapon");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ɲ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
     if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("���ɲ���ա�ֻ�л��ƶ����˲ſ����ã�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	if( !target || !target->is_character()||target->is_corpse()||target==me)
		return notify_fail("��Ҫ��˭ʹ��[�ɲ����]��\n");
	if (!target->is_fighting(me))
		return notify_fail("����û���ڴ�ܣ�\n");
	if (me->query_temp("no_feicha") )
		return notify_fail("������״̬���ѣ�����ʹ�÷ɲ���ա�\n");      
	if (me->query_skill("huomoforce",1)<80)
		return notify_fail("��Ļ�ħ�ķ�̫�ʹ�����ɲ���ա�\n");
	if (me->query_skill("yueya-chan",1)<80) 
		return notify_fail("������������������\n");
	if (me->query("force")<100)
		return notify_fail("���������̣�����ʹ�÷ɲ���ա�\n");
     
	me->add("force", -100);
	me->set("actions",feicha);
	message_vision(HIC"$NͻȻ��Хһ��������"+weapon->query("name")+HIC"���ֶ�����ֱ��$n��ȥ��������[�ɲ����]!"NOR,me,target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->set_temp("no_feicha",1);
	call_out("feicha_ok",2+random(2),me);
	me->reset_action();
	return 1;
}

void feicha_ok(object me)
{
	if (!me) return;
	me->delete_temp("no_feicha");
}         

void postfeicha(object me,object victim,object weapon, int damage)
{
	if (damage>0 || damage==RESULT_DODGE)
		message_vision(HIC""+weapon->query("name")+HIC"ʧȥ��ħ�ķ��Ĺ����ַɻص�$N���С�\n"NOR,me);
	else {
		message_vision(HIC""+weapon->query("name")+HIC"�޷��ܵ���ħ�ķ���֧��,���ڵ��ϡ�\n"NOR,me);
		weapon->move(environment(me));
	}
}
