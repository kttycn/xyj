//Cracked by Roath
//Jiz
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object *inv, obj;
	int i, mypot,tapot,temp_dodge,temp_spells;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С���Ԫһ�ơ���\n");
	if(me->query("family/family_name") != "��������"
	&& !me->query("guild") )
		return notify_fail("���Ǵ�����͵ѧ���ģ�\n");

	if(!me->is_fighting())
		return notify_fail("����Ԫһ�ơ�ֻ����ս����ʹ�ã�\n");

	if((int)me->query("max_force") < 200 )
		return notify_fail("�������������\n");

	if((int)me->query("force") < 200 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 200 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("huntian-hammer", 1) < 30)
		return notify_fail("��Ļ��촸���𻹲�����ʹ����һ�л������ѣ�\n");

message_vision(HIC"\n$N���㾫�񣬴��һ��������$n������ȫ��һ����\n"NOR, me, target);

	mypot=(int)me->query_skill("hammer");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot+(int)target->query_skill("dodge")/10;
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

//	write("mypot " + mypot + ", tapot " +tapot+ "\n");

	if( random( mypot+tapot ) > tapot ) {

		inv = all_inventory(target);
		i = sizeof(inv);

		if ( i < 1 ) {
			message_vision(HIR"$N������������������ţ�\n"NOR, target);
			target->receive_damage("kee",
random((int)me->query("max_force")/50+(int)me->query("force_factor")));
			COMBAT_D->report_status(target);
		} else {
			if(target->query_temp("armor")||target->query_temp("weapon")) {
				if( target->query_temp("armor") ) {
 					for (i=1; i < sizeof(inv); i++ ) {
						obj = inv[i];
						if( obj->query("equipped") != "worn" ) continue;
						obj->delete("equipped");
						obj->set("value", 0);
						obj->set("No_Wear", 1);
						message_vision(HIY"$N���ϵ�$n����ķ��飡\n"NOR, target,obj);
						//here is added by vikee 2000-12-2 0:59
						//��ֹbreak����Ч�Ṧ�ͷ�������ʧ.
						temp_dodge=(int)obj->query("armor_prop/dodge",1);
						temp_spells=(int)obj->query("armor_prop/spells",1);
						if (temp_dodge)
						target->add_temp("apply/dodge",-temp_dodge);
						if (temp_spells)
						target->add_temp("apply/spells",-temp_spells);
												
						obj->set("name", "�����"+obj->query("name"));
						call_out("remove_broken_cloth",random(300)+60,obj);
						obj->move(environment(target));
					}
				}
				if (target->query_temp("weapon")) {
					obj=target->query_temp("weapon");
					obj->unequip();
					obj->set("value", 0);
					message_vision(HIW "ֻ������ž����һ����$N���е�" + obj->name()+ "�Ѿ���Ϊ���أ�\n" NOR, target);
					obj->set("name", "�ϵ���" + obj->query("name"));
					obj->set("weapon_prop", 0);
					obj->set("armor_prop", 0);						  		
					obj->move(environment(target));
					call_out("remove_broken_cloth",random(300)+60,obj);
				}
			target->delete_temp("armor");
			target->delete_temp("apply");
			} else {
				message_vision(HIR"$N������������������ţ�\n"NOR, target);
		       		target->receive_damage("kee",
random((int)me->query("max_force")/50+(int)me->query("force_factor")));
		       		COMBAT_D->report_status(target); 
			}
		}
	} else {
	message_vision(HIC"ȴ��$N�㿪�ˣ�\n"NOR, target);
	}

	me->add("force", -150);
	me->receive_damage("sen", 50);

	target->kill_ob(me);

	me->start_busy(3+random(5));
	return 1+random(5);
}

void remove_broken_cloth(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),
      "һ��΢�紵����"+obj->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(obj);
  }
}
