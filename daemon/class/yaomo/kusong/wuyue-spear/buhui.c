#include <ansi.h>

inherit SSERVER;
//inherit F_CLEAN_UP;

int perform(object me, object target)
{
        object weapon;
int i,j,k,damage;
weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ����˭��\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");
		   if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("�����ڡ�ֻ�л��ƶ����˲ſ����ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("pingtian-dafa", 1) < 100)
        	return notify_fail("���ƽ��󷨵ȼ�����������ʹ����һ�У�\n");
	i=(int)me->query("combat_exp");
       j=(int)target->query_("combat_exp");
            k=(int)me->query_skill("spear");
                  if(k<100)        
                return notify_fail("��� ǹ�����𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");
message_vision(HIM"\n$Nһͦ����"+weapon->name()+NOR+HIB"ֱ��$n��\n"NOR,me,target);
if (random(i)>random(j)) {
            damage=k+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(i)> random(j)) {
              message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
            damage=k+random(k)+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(i)> random(j)) {
              message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
              message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
damage=k+random(k)*2+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(2)) {
              message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
              message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
            message_vision(HIM"\n$Nһͷ��Ȼײ�գ���$nҲ����ƴ���ľٶ�����һ����\n"NOR,me,target);
     	target->start_busy(5);
}
else {
              message_vision(HIM"\n$Nһǹ�̿գ�����һ�⣬�Ի���$n��\n"NOR,me,target);
              message_vision(HIM"\n$Nһ���ֿգ����Բ����ţ�һͷײ��$n��\n"NOR,me,target);
            message_vision(HIW"\n$n������Ц��ֻ��ƥ��ֻ�����к��ã����ɱܿ�\n"NOR,me,target);
}

me->receive_damage("sen", 50);
        me->add("force", -100-(int)me->query("force_factor"));
	me->receive_damage("kee", 30); 
if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
}
me->start_busy(1+random(2));
        return 1;
}
