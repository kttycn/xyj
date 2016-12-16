//Cracked by Roath

//Ansi 99.8
//fei 2001.2
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int cast(object me, object target)
{
	string msg;
	object *ob;
	int i, skill, damage, spells, success_adj, damage_adj;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("��Ҫ��˭ʩ�����񡹣�\n");
	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
        return notify_fail("�㲻����ɽ���ɵ��ӣ�������������񡹡�\n");
	if( !me->is_fighting() )
		return notify_fail("ֻ����ս�����ٻ�����\n");
	if(me->query("shushan/jiushen_cast")!=1)
		return notify_fail("�㻹û��ᡸ���񡹣�\n");

	if((int)me->query_skill("taoism", 1) < 150 )
		return notify_fail("�����ʦ�ɷ���򲻹����Ŀ��ܺ����������񡹣�\n");

	if((int)me->query("mana") < 200+(int)me->query("mana_factor") )
		return notify_fail("��ķ������������ƾ����Ӧ������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("���������ǲ��壬��MM������ʶ������˵�Ǿ����ˣ�\n");

	me->add("mana", -200-(int)me->query("mana_factor"));
	me->receive_damage("sen", 100);
	me->apply_condition("drunk", 0);

	if( random(me->query("max_mana")) < 100 ) {
		message_vision(HIR "\n$N��Ȼһ�ſڣ��������һ�ھ���\n
ֻ�������л���һ�����Σ�̽��̽ͷ�����������ɢ��ȥ��n\n"NOR, me);
		return 1;
	}

	message_vision(HIR"\n$N��Ȼһ�ſڣ��������һ�ھ���\nֻ�������л���һ�����Σ�ƾ�մ����һ�����ף������ڳ���ÿһ���ˣ�\n\n"NOR,me);
//	msg = HIR "\n$N��Ȼһ�ſڣ��������һ�ھ���\nֻ�������л���һ�����Σ�ƾ�մ����һ�����ף������ڳ���ÿһ���ˣ�\n\n"NOR;
	ob = all_inventory(environment(me));
	msg = MAG "\n        
                      ��#
                      @  @_                  
                    ��    @    
                     @     @    
                     _*****_   
                   ��   ��  @  
                   @         @   
                   @    ɽ   @  
    ________________@______@_______           *****
  ��_______________________________@�� iiiiii)*****  
                              ^^^^^           *****
                                           \n"NOR;

	skill = me->query_skill("spells",1);
	spells = me->query("max_mana",1);

	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;
		damage = skill + random(skill)+spells/10 - ((int)ob[i]->query("max_mana") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("kee", damage);
			if( (int)ob[i]->query("mana") < skill * 2 )
			ob[i]->receive_wound("kee", damage/2);
			ob[i]->apply_condition("drunk",50);
			msg += RED "���"+ob[i]->query("name")+"�������񡹻������ţ�\n" NOR;
		}
		COMBAT_D->report_status(ob[i]);         
		if( userp(ob[i]) )
			ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) )
			ob[i]->kill_ob(me);
		me->kill_ob(ob[i]);
	}
	message_vision(msg, me, target);
	me->receive_wound("sen", 10);
	me->start_busy(2+random(2));
	return 1;
}

int clean_up()
{
	return 0;
}
