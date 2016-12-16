//by fly 6-6-2000

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

string *xue_name = ({ 
	HIR"�͹�Ѩ"NOR,HIR"����Ѩ"NOR,HIR"����Ѩ"NOR,
	HIG"��ԪѨ"NOR,HIG"����Ѩ"NOR,HIG"�м�Ѩ"NOR,
	HIY"�н�Ѩ"NOR,HIY"��ͻѨ"NOR,HIY"�ٻ�Ѩ"NOR,
	HIM"����Ѩ"NOR,HIM"����Ѩ"NOR,HIM"���Ѩ"NOR,
	HIW"�Ϲ�Ѩ"NOR,HIW"��ԨѨ"NOR,HIW"�쾮Ѩ"NOR,
	HIC"��ȪѨ"NOR,HIC"����Ѩ"NOR,HIC"����Ѩ"NOR,
}); 
string *weapon1_name = ({ HIR"����"NOR,HIR"���ֽ�"NOR,HIG"�콣"NOR}); 
string *weapon2_name = ({ HIW"���ֽ���"NOR,HIB"һ������"NOR,HIR"���ν���"NOR}); 
string *weapon3_name = ({ HBRED"��������"NOR,HBGRN"һ������"NOR,HBBLU"��������"NOR}); 

int perform(object me, object target)
{
	int damage, p;
	string msg, dodge_skill,*limbs;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("["+HIR"��â������"NOR+"]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->query("family/family_name") != "��ׯ��"
	&& !me->query("guild") )
		return notify_fail("[��â������]����ׯ�۲���֮�ܣ�\n");
	if( (int)me->query_skill("sanqing-jian", 1) < 180 )
		return notify_fail("������彣������������������ʹ��"+HIR"��â������"NOR+"�ԵУ�\n");
	if( (int)me->query_skill("sword", 1) < 180 )
		return notify_fail("��Ľ���������죬ʹ����"+HIR"��â������"NOR+"��\n");
	if( (int)me->query_skill("force", 1) < 180 )
		return notify_fail("����ڹ�������죬ʹ����"+HIR"��â������"NOR+"��\n");
	if( (int)me->query_skill("parry", 1) < 180 )
		return notify_fail("����мܲ�����죬ʹ����"+HIR"��â������"NOR+"��\n");
	if(! me->query_temp("weapon") )
		return notify_fail("������ý�����ʹ�á�"+HIR"��â������"NOR+"����\n");
	if (me->query_skill_mapped("sword") != "sanqing-jian" || me->query_skill_mapped("parry") != "sanqing-jian")
		return notify_fail("��Ľ����мܼ�������׼ȷ,ʹ����"+HIR"��â������"NOR+"��\n");
	if( (int)me->query("max_force") < 2500 )
		return notify_fail("������������Ϊ���㣬ʹ����"+HIR"��â������"NOR+"��\n");     
	if( (int)me->query("force") < 1000 )
		return notify_fail("�������������㣬ʹ����"+HIR"��â������"NOR+"��\n");     
/*
	 if( me->query_temp("sqj_jianmang"))
		  return notify_fail("���ʹ�꡸"+HIR"��â������"NOR+"����Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
*/
	message_vision(HIR "\n$Nһ����Ц,���г���бָ����,�����³�һ�ų������â,�������԰���������!\n"NOR, me, target); 
	msg = HIG"ͻȻ֮�䣬$N�������֣�����һ�����������Σ�ֱ����$n,"NOR+xue_name[random(sizeof(xue_name))]+HIG"����ɭɭ������\n"NOR;
	me->set_temp("sqj_jianmang", 1);
	if (random(me->query_skill("force")) > random(target->query_skill("force") /4)&&
	    random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){		     
		me->start_busy(1);
		target->start_busy(1); 
		msg += CYN"$n���һ�������в�����$w��������"NOR+xue_name[random(sizeof(xue_name))]+CYN"�Դ���������������һɢ��\n"NOR;
		damage = (int)me->query_skill("sword", 1);       
		damage = damage + random(damage/2);
		if(damage>1100) damage=1100;
		if(me->query_skill("zhenyuan-force",1) > target->query_skill("zhenyuan-force",1)
		&& me->query("force") > random(target->query("force"))  ) 
			       damage += random(damage*3/2);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/3);
		p = (int)target->query("kee")*100/(int)target->query("max_kee");

		msg += "( $n"+eff_status_msg(p)+" )\n";
		msg = replace_string(msg, "$w", weapon1_name[random(sizeof(weapon1_name))]);   
		message_vision(msg, me, target);
	       target->set_temp("last_damage_from", me);
		me->add("force", -(int)me->query_skill("sword", 1)/2);
		remove_call_out("perform2");
		call_out("perform2", 0, me, target);  

	      } 
	else {
		me->start_busy(2+random(2));
		msg += HIY"\n$nȴʶ�����Ž�â������,����ԶԶ����һ��.\n" NOR;
		message_vision(msg, me, target);
/*
		remove_call_out("remove_effect");
		call_out("remove_effect", 2, me);
*/
	      }

	return 1;
}

int perform2(object me, object target)
{
	int damage,p;
	string msg, dodge_skill,*limbs,force_skill,force_skill_name,wep;
	if (!me) return 1;
       if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){
	   if(!wep)msg = HIY"$N����������ʧ��Բת��������Ҳ��֮��ɢ��$n�������˿�����\n"NOR;
	   else  msg = HIY"$N����"+wep->name()+HIY"��ֹͣ׷����$n�����ܲ��Ľ�ĻҲ��֮��ɢ��ѹ����Ȼ���ᣡ\n"NOR;
	   message_vision(msg, me, target);
	   if(target->is_busy()) target->start_busy(1);
	   me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   return 1;
	   } 
       if (userp(me) && (me->query_skill_mapped("sword") != "sanqing-jian" || me->query_skill_mapped("parry") != "sanqing-jian")){
	   message_vision(HIY"$NͻȻ���У����ƽ�Ļ��ʹ�������彣����ȫ��ͬ����������\n"NOR,me);
	   if(target->is_busy()) target->start_busy(1);
	 me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	      return 1;
	    }
	    if(!target)
	    	return 1;
	if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
	   if(!living(target)) msg = HIY"$N��м������$nһ�ۣ�������"+wep->name()+HIY"һ���ڣ�������ɢ���Ľ�Ļ��\n"NOR;
	   else msg = HIY"$N������"+wep->name()+HIY"���һ�ڣ���Բ��һ��ֹͣ�˹�����\n"NOR;
	   if(target->is_busy()) target->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   message_vision(msg, me, target);
	   return 1;
	   }	   
	if(!living(target)) 
	  return notify_fail("�����Ѿ�������ս���ˡ�\n");
	if( (int)me->query("force", 1) < 1000 )
	   {message_vision(HIY"$N���н���ɬ�ͣ��ղ�һ���̳���Ȼ����������ԭ�������������ˣ�\n"NOR,me);
	 if(target->is_busy()) target->start_busy(1);
	   me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   return 1;
	  }
	force_skill = target->query_skill_mapped("force");
	if( !force_skill ) force_skill_name = "�����ڹ�";
	else    if( force_skill=="huntian-qigong" ) force_skill_name = "��������";
	else    if( force_skill=="lengquan-force" ) force_skill_name = "��Ȫ��";
	else    if( force_skill=="moonforce" ) force_skill_name = "�¹��ķ�";
	else    if( force_skill=="lotusforce" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="wuxiangforce" ) force_skill_name = "С���๦";
	else    if( force_skill=="dragonforce" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="tonsillit" ) force_skill_name = "������";
	else    if( force_skill=="ningxue-force" ) force_skill_name = "��Ѫ��";
	else    if( force_skill=="huomoforce" ) force_skill_name = "��ħ�ķ�";
	else    if( force_skill=="zhenyuan-force" ) force_skill_name = "��Ԫ��";
	else    if( force_skill=="zixia-shengong" ) force_skill_name = "��ϼ��";
	else    if( force_skill=="jiuyin-xinjing" ) force_skill_name = "�����ľ�";
	else    if( force_skill=="xiantian-force" ) force_skill_name = "����Ǭ����";
	else    if( force_skill=="guiyuanforce" ) force_skill_name = "��Ԫ��";
	else    if( force_skill=="wuzu-xinfa" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="xuanhu-xinfa" ) force_skill_name = "�����ķ�";
	else    force_skill_name = "�����ڹ�";    
	msg = HIG "\n���ţ�$N��ʽһת���ҿ�һ������ؽ�������,��������ǧ���򻯣��������ء�\n"NOR;	
	if (random(me->query_skill("force")) > random(target->query_skill("force") /3)&&
	    random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){	    
		me->start_busy(1);
		target->start_busy(1);
		msg += CYN"ֻ��$nһ���Һ�,��â��"NOR+xue_name[random(sizeof(xue_name))]+CYN"�ӹ���$n����"NOR+HIR+force_skill_name+NOR+CYN"����Ѫ��Ȼ�޷����ۡ�\n"NOR;
		damage = (int)me->query_skill("sword", 1);       
		damage = damage*3/2 + random(damage);
		if(damage>2000) damage=2000;
		if(me->query_skill("zhenyuan-force",1) > target->query_skill("zhenyuan-force",1)
		&& me->query("force") > random(target->query("force"))  ) 
		damage = damage*3/2 + random(damage/2);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/3);
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += "( $n"+eff_status_msg(p)+" )\n";		
		msg = replace_string(msg, "$w", weapon2_name[random(sizeof(weapon2_name))]);
		me->add("force", -(int)me->query_skill("sword", 1)/2);   
	       target->set_temp("last_damage_from", me);
		message_vision(msg, me, target);    
	if( (int)me->query_skill("parry", 1) > 199 &&
	    (int)me->query_skill("force", 1) > 199 &&
	    (int)me->query_skill("sword", 1) > 199 &&
	    (int)me->query_skill("sanqing-jian", 1) > 199 &&
	    (int)me->query_skill("force", 1) > 199 ) {
		remove_call_out("perform3");
		call_out("perform3", 0, me, target); 
		}
	} 
	else 
	{
		me->start_busy(2+random(2));
		msg += HIY"\n$n˳��������ת������һ������Ȼ�������"NOR+HIR"���ֽ�"NOR+HIY".\n" NOR;
		me->add("force", -(int)me->query_skill("sword", 1)/2);     
		message_vision(msg, me, target);    
	}

	return 1;
}
int perform3(object me, object target)
{
	int damage , p;
	string msg, weapon,dodge_skill,*limbs,force_skill,force_skill_name;
	if (!me) return 1;
       if(!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"){
	   if(!weapon)msg = HIY"$N����������ʧ��Բת��������Ҳ��֮��ɢ��$n�������˿�����\n"NOR;
	   else  msg = HIY"$N����"+weapon->name()+HIY"��ֹͣ׷����$n�����ܲ��Ľ�ĻҲ��֮��ɢ��ѹ����Ȼ���ᣡ\n"NOR;
	   message_vision(msg, me, target);
	   if(target->is_busy()) target->start_busy(1);
	   me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   return 1;
	   } 
	    if(!target)
	    	return 1;
       if (userp(me) && (me->query_skill_mapped("sword") != "sanqing-jian" || me->query_skill_mapped("parry") != "sanqing-jian")){
	   message_vision(HIY"$NͻȻ���У����ƽ�Ļ��ʹ�������彣����ȫ��ͬ����������\n"NOR,me);
	   if(target->is_busy()) target->start_busy(1);
	 me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	      return 1;
	      }
	if(!me->is_fighting(target) && !me->is_killing(target->query("id"))){
	   if(!living(target)) msg = HIY"$N��м������$nһ�ۣ�������"+weapon->name()+HIY"һ���ڣ�������ɢ���Ľ�Ļ��\n"NOR;
	   else msg = HIY"$N������"+weapon->name()+HIY"���һ�ڣ���Բ��һ��ֹͣ�˹�����\n"NOR;
	   if(target->is_busy()) target->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   message_vision(msg, me, target);
	   return 1;
	   }	   
	if( (int)me->query("force", 1) < 1000 ){
	   message_vision(HIY"$N���н���ɬ�ͣ��ղ�һ���̳���Ȼ����������ԭ�������������ˣ�\n"NOR,me);
	 if(target->is_busy()) target->start_busy(1);
	   me->start_busy(1);
	   me->delete_temp("sqj_jianmang");
	   return 1;
	  }
	if(!living(target))
	      return notify_fail("�����Ѿ�������ս���ˡ�\n");
	force_skill = target->query_skill_mapped("force");
	if( !force_skill ) force_skill_name = "�����ڹ�";
	else    if( force_skill=="huntian-qigong" ) force_skill_name = "��������";
	else    if( force_skill=="lengquan-force" ) force_skill_name = "��Ȫ��";
	else    if( force_skill=="moonforce" ) force_skill_name = "�¹��ķ�";
	else    if( force_skill=="lotusforce" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="wuxiangforce" ) force_skill_name = "С���๦";
	else    if( force_skill=="dragonforce" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="tonsillit" ) force_skill_name = "������";
	else    if( force_skill=="ningxue-force" ) force_skill_name = "��Ѫ��";
	else    if( force_skill=="huomoforce" ) force_skill_name = "��ħ�ķ�";
	else    if( force_skill=="zhenyuan-force" ) force_skill_name = "��Ԫ��";
	else    if( force_skill=="zixia-shengong" ) force_skill_name = "��ϼ��";
	else    if( force_skill=="jiuyin-xinjing" ) force_skill_name = "�����ľ�";
	else    if( force_skill=="xiantian-force" ) force_skill_name = "����Ǭ����";
	else    if( force_skill=="guiyuanforce" ) force_skill_name = "��Ԫ��";
	else    if( force_skill=="wuzu-xinfa" ) force_skill_name = "�����ķ�";
	else    if( force_skill=="xuanhu-xinfa" ) force_skill_name = "�����ķ�";
	else    force_skill_name = "�����ڹ�";    
	weapon = me->query_temp("weapon");  
	msg = HIW "\n�����ţ�$N������ǰ��������һ�����õĹ�ȦһȦһȦ��$nȫ���ѱ�������\n"NOR;	
	if (random(me->query_skill("force")) > random(target->query_skill("force") /3)&&
	    random(me->query("combat_exp")) > random(target->query("combat_exp") /4) ){   
		me->start_busy(1+random(2));
		target->start_busy(1+random(3));
		msg += weapon3_name[random(sizeof(weapon3_name))]+WHT"�̴�$n��"NOR+HIR+force_skill_name+NOR+WHT",����һ��$n��"NOR+HIM"�ֱ�"NOR+WHT"��Ȼ�ʶϣ�"NOR+xue_name[random(sizeof(xue_name))]+WHT"���Դ�������\n"NOR;
		damage = (int)me->query_skill("sword", 1);       
		damage = damage*2 + random(damage*2);
		if(damage>4000) damage=4000;
		if(me->query_skill("zhenyuan-force",1) > target->query_skill("zhenyuan-force",1)
		&& me->query("force") > random(target->query("force"))  ) 
		damage = damage*3/2 + random(damage*3/2);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/2);
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		 msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		limbs = target->query("limbs");
		msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
		msg = replace_string(msg, "$w", weapon->name());   
	       target->set_temp("last_damage_from", me);
		me->add("force", -(int)me->query_skill("sword", 1)/2);
	} else 
	{
		me->start_busy(2+random(3));
		target->start_busy(1);
		msg += HIY"\n$nȴʶ�����Ź�Ȧ������,�й�ֱ�룬��������\n" NOR;
		me->add("force", -(int)me->query_skill("sword", 1)/2);
	}
	message_vision(msg, me, target); 
	me->start_busy(5);
	return 1;
}
void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("sqj_jianmang");
	tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ��"NOR+HIR"��â������"NOR+"�ˡ�\n"NOR); 
}

