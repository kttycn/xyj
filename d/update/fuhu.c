//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,j,k,damage,p;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("［降龙伏虎］只能对战斗中的对手使用。\n");

	if(me->query("family/family_name")!="南海普陀山"
	&& !me->query("guild") )
		return notify_fail("不是佛门弟子不能用「降龙伏虎」！\n");
// 佛门杀气高？好象不符合现实，所以设定这杀气条件
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("你的杀气太重，无法施展佛门绝技。\n");

	extra = me->query_skill("lunhui-zhang",1)/10+me->query_skill("staff",1)/10;
		if ( extra < 20) return notify_fail("你的轮回杖法与基本杖法还不够纯熟，怕是无法运用！\n");

	if(me->query_skill("lotusforce",1) < 100)
		return notify_fail("你的内功底子不足，无法运杖如风，施展不出降龙伏虎。\n");

	if((string)me->query_skill_mapped("force")!="lotusforce")
		return notify_fail("降龙伏虎必须以莲台心法为底子。\n");

	if(me->query("max_force") < 1000)//原来500
		return notify_fail("你的内力不足，难以随意挥动一把禅杖。\n");
	if(me->query("force") < 1000 )
	   	return notify_fail("你当前内力不足，难以随意挥动一把禅杖。\n");
	i=(int)me->query("combat_exp");
	j=(int)target->query_("combat_exp");
	k=(int)me->query_skill("lunhui-zhang",1);

	weapon = me->query_temp("weapon");
me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIY"\n$N身型闪动，地面随之起伏一降狂风，手中"+weapon->name()+NOR+HIY"，也有如狂风暴雨般地向$n卷来！\n"NOR,me,target);
	
	  if (random(i)>random(j)) {
		damage=k/200+(int)me->query("str")/2;//原来是k,*7
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/8
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "砸伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
	if( (int)me->query("force", 1) < 1000 )
	    message_vision(HIY"$N仗招渐见涩滞，刚才一杖拍出竟然软弱无力，原来是真气不足了！\n"NOR,me);

	if (random(i)> random(j)) {
		message_vision(HIY"\n$N一杖拍出，马上又是一杖，刺向$n！\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")/2;//原来是K
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/6
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "刺伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
}
	if( (int)me->query("force", 1) < 1000 )
	        message_vision(HIY"$N仗招渐见涩滞，刚才一杖刺出竟然软弱无力，原来是真气不足了！\n"NOR,me);
		   
	if (random(i)> random(j)) {
		message_vision(HIY"\n$N一杖使尽，忽然反手，又是一杖向$n轮去！\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")/2;//k+random(k)*2+(int)me->query("str")*8
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/8
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "砸伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
	if( (int)me->query("force", 1) < 1000 )
	    message_vision(HIY"$N仗招渐见涩滞，刚才一杖轮出竟然软弱无力，原来是真气不足了！\n"NOR,me);
	   
	if (random(2)) {
		message_vision(HIY"\n$N使完最后一击，突然大吼一声：降龙伏虎，将全身内力注入手中兵器向$n砸去！\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")*1;//damage=k+random(k)*3+(int)me->query("str")*8;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/5
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "砸伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
/*	message_vision(HIY"\n$N一枪方回，飞身跃起，又是一枪刺向$n！\n"NOR,me,target);
	damage=k+random(k)*4+(int)me->query("str")*10;
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/5);
	p = (int)target->query("kee")*100/(int)target->query("max_kee");
	msg = damage_msg(damage, "刺伤");
	msg += "( $n"+eff_status_msg(p)+" )\n";     
	message_vision(msg, me, target);
//	COMBAT_D->do_attack(me, target, weapon);

	me->receive_damage("sen", 100 );
	me->add("force", -100-(int)me->query("force_factor"));
	me->receive_damage("kee", 30); 
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(7);
	return 5;
}
	msg = HIY  "$N身型闪动，地面随之起伏一降狂风，手中"+ weapon->name()+  "也有如狂风暴雨般地向$n卷来！" NOR;

	message_vision(msg,me,target);
*/
	me->add_temp("apply/attack",extra/4);
	me->add_temp("apply/damage",extra/4);
	lmt = 9;
	for(i=6;i<=lmt;i++)
	{
		me->set_temp("FMZ_perform",i);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->receive_damage("sen", 200 );
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
//	me->add("force",-extra*5);
	me->delete_temp("FMZ_perform");
	me->start_busy(3+random(4));
	return 4;
//}
}