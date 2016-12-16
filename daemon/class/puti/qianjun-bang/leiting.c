void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "һ��΢�紵����"+ob->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(ob);
  }
}
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,mystr,yourstr,lvl,lv;
	object weapon;

	if( !target ) target = offensive_target(me);

	weapon = me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type") != "stick"  )
		return notify_fail("�������ʹ�ñ���ʱ����ʹ[����һŭ����\n");
	if( me->query_skill("qianjun-bang",1) < 180 )
		return notify_fail("���ǧ�������𲻹�ʹ�ã�����һŭ��\n");
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("������һŭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->query("family/family_name") != "����ɽ���Ƕ�" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á���������?\n");
	weapon = target->query_temp("weapon");
	if(!objectp(weapon)) return notify_fail("��Ķ���û���ñ�����\n");
	myexp = (int) me->query("combat_exp")/1000;
	mystr = (int) me->query("str");
	yourexp = (int) target->query("combat_exp")/1000;
	yourstr = (int) target->query("str");

	lv  = (int) me->query_skill("stick") ;
	lvl = (int) target->query_skill("dodge")+1;
   msg = YEL "$N˫�������������һ�ң�$n�ı����ϳ����������˵��£� \n" NOR;
if(objectp(weapon) )
{
	if( random(myexp * lv * mystr) > (yourexp * yourstr *lvl)/3)
		
	{
		weapon->unequip();
		weapon->move(environment(target));
		weapon->set("name","�ϳ����ص�"+weapon->query("name"));
		weapon->set("no_get",1);
		weapon->set("long","һ���ϳ����ص�"+weapon->query("name"));
	call_out("remove_broken_weapon", random(30)+60,weapon);
		message_vision(msg, me, target);
		target->start_busy(2);
	}
	else
	{
     msg=YEL"���$n������$N����ͼ���ɵض������$N�������ȣ����˸���æ���ҡ�\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
	}
		me->start_busy(2);
}
	return 1;
}
