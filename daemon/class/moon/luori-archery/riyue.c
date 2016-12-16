// counterattack.c
#include <ansi.h>
#include "/daemon/skill/eff_msg.h";

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg, skill_type1, skill_type2, wp_name1, wp_name2;
	int ap,dp,p;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һ�������£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int)me->query_skill("luori-archery", 1) <160)
		return notify_fail("������ռ�����򻹲�����\n");
/*	if (me->query_skill_mapped("force")!="dragonforce")
		return notify_fail("���ռ���������������񹦲���ʹ�á�\n");
	if (me->query_skill_mapped("dodge")!="dragon-steps")
		return notify_fail("���ռ��������������������ʹ�á�\n");
	if((int) me->query_skill("dragonforce",1) < 100)
		return notify_fail("��ģ������񹦣ݻ��������������ܷ�����һ�������£ݡ�\n");
	if((int) me->query_skill("dragon-steps",1) < 100)
		return notify_fail("��ģ��������ݻ��������������ܷ�����һ�������£ݡ�\n");
*/
	if (!target->is_fighting(me))
		return notify_fail("����û���ڴ�ܣ�\n");
	if (!target->is_killing(me->query("id")))
		return notify_fail("�ö˶˵ı��䣬�α������ಫ��\n");
	if (me->query("force")<600)
		return notify_fail("���������̣�������������㡣\n");
	if (me->query("kee") < me->query("eff_kee")*90/100
	&& me->query("sen") < me->query("eff_sen")*90/100)
		return notify_fail("���״�����ã�ǿҪʹ�ã�һ�������£ݻ��߻���ħ�ġ�\n");

	if( objectp( weapon = target->query_temp("weapon")) )
		skill_type2 = weapon->query("skill_type");
	else
		skill_type2 = "unarmed";

	ap = me->query_skill("luori-archery", 1) + me->query_str();
	dp = COMBAT_D->skill_power(target, skill_type2, SKILL_USAGE_DEFENSE)+
		COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	wp_name1 = me->query_temp("weapon")->query("name");

	me->receive_damage("kee", me->query("eff_kee")/10); 
	me->receive_wound("kee", me->query("eff_kee")/10); 
	me->receive_damage("sen", me->query("eff_kee")/10); 
	me->receive_wound("sen", me->query("eff_kee")/10); 
	me->add("force",-500);
	message_vision(HIR"$N����$n�����һ����"HIW"��һ�������£�"HIR"�����������£�һ����$n��ȥ��\n"NOR,me,target);
	if( random(ap+dp) > dp/2 && random(2)>0)
	{
		if(me->query("force") > target->query("force")*2)
		{
			if(!weapon->query("name"))
			{
				msg = HIR"ֻ��һ�����졣$n��$l��"+wp_name1+"�ᴩ��\n"NOR;
				target->receive_damage("kee", ap+random(ap)); 
				target->receive_wound("kee", ap+random(ap)); 
				p = (int)target->query("kee")*100/(int)target->query("max_kee");
				msg += damage_msg(ap+random(ap), "����");
				msg += "( $n"+eff_status_msg(p)+" )\n";     
			} else
			{
				wp_name2 = weapon->query("name");
				if(weapon->query("rigidity") >=8 ){ // �ж�����Ӳ��
					target->start_busy(1);
					weapon->move(environment(target)); // weapon->move(me)��ʲ��Ч���أ�
					target->receive_damage("kee", ap/2+random(ap)); 
					target->receive_wound("kee", ap/2+random(ap)); 
					msg = RED"ֻ�����䡱��һ����$n���е�"+wp_name2+RED+
						"�ѱ�"+wp_name1+RED"��ɣ�����Ҳ��"+wp_name1+"������ײ�������ѣ�\n"NOR;
//					msg = replace_string(msg, "$w1", weapon2->name());
//					msg = replace_string(msg, "$w2", weapon1->name());
					p = (int)target->query("kee")*100/(int)target->query("max_kee");
					msg += damage_msg(ap/2+random(ap), "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";     

				}
				else{
//					if (!random(3))
//					{
					target->start_busy(1);
					target->receive_damage("kee", ap);
					target->receive_wound("kee", ap);
					weapon->unequip();
					weapon->move(environment(target));
					weapon->set("name", "�ϵ���"+weapon->query("name"));
					weapon->set("value", 0);
					weapon->delete("long");
					weapon->set("weapon_prop", 0);
					msg = HIW"ֻ����ž����һ����$n���е�"+wp_name2+HIW+"�ѱ�"+wp_name1+HIW+
					"��Ϊ���أ�\n"NOR;
					p = (int)target->query("kee")*100/(int)target->query("max_kee");
					msg += damage_msg(ap, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";     
//					msg += HIR+target->query("name")+"������˼�����ֻ����ͷһ�𣬡��ۡ���һ�����³�һ����Ѫ��"NOR;
				}
//					else { 
//						msg = MAG"ֻ��һ�����죬"+target->query("name")+
//							"���е�$w1"MAG"��$w2"MAG"�ĳ���²�ס��������Щ���֣�\n" NOR;
//							msg = replace_string(msg, "$w1", weapon2->name());
//							msg = replace_string(msg, "$w2", weapon1->name());
//					}
//				}
			}
		}
		msg = HIM"$n�ۼ���һ������̫�����ͣ����޴��ɱܣ��������е�"+wp_name2+"��ȥ��\n"+
			"ֻ���á��䡱��һ����$n��"+wp_name1+"�ĳ���£�������˼��������ۡ���һ�����³�һ���ʡ�\n"NOR;
//			msg = replace_string(msg, "$w1", weapon2->name());
//			msg = replace_string(msg, "$w2", weapon1->name());
			target->receive_damage("kee", ap/4+random(ap)); 
			target->receive_wound("kee", ap/4+random(ap)); 
			p = (int)target->query("kee")*100/(int)target->query("max_kee");
			msg += damage_msg(ap/4+random(ap), "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";     
	}
	else msg = HIM"$n�ۼ���һ��̫�����գ�����ȥ�ӣ��͵�����һ�������յض������ǰ��һ����\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(1+random(3));

	return 1;
}
