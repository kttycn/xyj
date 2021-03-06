//突发奇想 做此skills
//  修改于2000.6.27
//   by fly

#include <ansi.h>
inherit SSERVER;

#include "/daemon/skill/eff_msg.h";
#include "/daemon/skill/liumai_msg.h";

int exert(object me, object target)
{       
	string msg;
	int damage, p;

	if(!me->query_skill("zixia-shengong", 1)) return 0;  
	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("「六脉神剑」只能在战斗中使用。\n");

	if(me->query_skill("zixia-shengong", 1) <100)
		return notify_fail("以你现在的内功修为还使不出「六脉神剑」来。\n");        
	if(me->query_skill("yujianshu", 1) <100)
		return notify_fail("以你现在的剑法修为还使不出「六脉神剑」来。\n");        

	if( (int)me->query("max_force") < 3500 )
		return notify_fail("你的内力修为太弱，根本使不出「六脉神剑」来！\n");
	if( (int)me->query("force") < 1000 )
		return notify_fail("你的真气不够！\n");

	if( !target ) target = offensive_target(me);
	tell_object(me, HIW"\n你先行存念，然后鼓气出指，内劲真气勃发，开始运用六脉神剑！\n"NOR);
	me->set_temp("start_6mai", 1);
	remove_call_out("check_6mai");        
	remove_call_out("checking");
	call_out("check_6mai", 2, me, target);
	call_out("checking", me->query_skill("huomo-xinfa", 1), me);
	return 1;
}

int checking(object me)
{
	if(me->query_temp("start_6mai")){
		me->delete_temp("start_6mai");
		tell_object(me, HIW"\n你内劲运行一周天，将六脉神剑的招数用了一遍！\n"NOR);
	}
	return 1;
}
int check_6mai(object me, object target)
{
	string msg, *limbs, dodge_skill, str, limb;
	int lv, i, force, ap, dp, damage, p, j;
	mapping act, *action;
	object wep;
	lv = (int)me->query_skill("unarmed", 1);
       
	action = ({
	([
		"action" : liumai_msg[random(3)],
		"t_msg" : target_msg[random(2)],
		"damage" : 5,
		"lvl" : 0,
		"skill_name" : "少泽剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[3+random(2)],
		"t_msg" : target_msg[2+random(2)],
		"damage" : 6,
		"lvl" : 30,
		"skill_name" : "关冲剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[5+random(4)],
		"t_msg" : target_msg[4+random(2)],
		"damage" : 6,
		"lvl" : 60,
		"skill_name" : "商阳剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[9+random(3)],
		"t_msg" : target_msg[6+random(2)],
		"damage" : 4,
		"lvl" : 90,
		"skill_name" : "中冲剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[12+random(4)],
		"t_msg" : target_msg[8+random(2)],
		"damage" : 3,
		"lvl" : 120,
		"skill_name" : "少冲剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[16+random(3)],
		"t_msg" : target_msg[10+random(2)],
		"damage" : 7,
		"lvl" : 150,
		"skill_name" : "少商剑",
		"damage_type" : "刺伤"
	]),
	([
		"action" : liumai_msg[random(sizeof(liumai_msg))],
		"t_msg" : target_msg[random(sizeof(target_msg))],
		"damage" : 2+random(8),
		"lvl" : 200,
		"skill_name" : "六脉神剑",
		"damage_type" : "刺伤"
	]),});

	if (lv >= 200) j = 6;
	else if (lv >= 150) j = 5;
	else if (lv >= 120) j = 4;
	else if (lv >= 90) j = 3;
	else if (lv >= 60) j = 2;
	else if (lv >= 30) j = 1;
	else j = 0;
	act = action[random(j)];
	damage = act["damage"];
	msg = act["action"];
	force = (int)me->query("force");        

	if(!living(target) || !target || !me->is_fighting() || environment(me) != environment(target)){
		me->delete_temp("start_6mai");
		return 1;
	}
	if(!me->query_temp("start_6mai")){
		me->delete_temp("start_6mai");
		return 1;
	} 
	if(!living(me) || me->is_ghost()){
		me->delete_temp("start_6mai");
		return 1;
	}
	if(force < 500){
		tell_object(me,"你发现自己现在的真气太弱，已经不够使出「六脉剑气」了。\n");           
		me->delete_temp("start_6mai");
		return 1;
	}                   
	if(me->is_busy()){
		call_out("check_6mai", 2, me, target);
		return 1;
	}

	ap = me->query_skill("force") + me->query_skill("unarmed", 1) + me->query_int();
	dp = target->query_skill("force", 1) + target->query_skill("dodge") + target->query_dex();
	ap *= me->query("combat_exp")/1000;
	dp *= target->query("combat_exp")/1000;

	limbs = target->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	msg = replace_string(msg, "$l", limb);
	message_vision(msg, me, target);
	tell_object(target, HIR+act["t_msg"]+NOR); 
	wep = target->query_temp("weapon");

	if( ap > dp /3){
		me->add("force", -damage);
		damage *= lv*4;
		damage -= target->query_temp("apply/armor")/2;
		damage += me->query("force_factor")*4;
		if(force > target->query("force")*2) damage = damage*2;          
		if(damage > 5500) damage = 5500;

//the target has a weapon in hand
		if(objectp(wep) && random(2) == 1){     
			if(me->query("force") < target->query("force")){
				me->start_busy(1);
				msg = HIY"结果只听哐的一声，$n用手中$W"HIY"竟然接下了那$w！\n" NOR;                        
			}
			else if(me->query("force") >= target->query("force")*2){
				if(wep->query("rigidity") >= 3){
					me->start_busy(1);
					wep->move(environment(target));
					target->receive_damage("qi", 50);  
					target->receive_wound("qi", 25);      
					msg = HIW"结果只听啪的一声，$n拿捏不住$W"HIW"被脱手震飞，虎口也在猛烈撞击下震裂！\n" NOR;
					target->reset_action();
				}
				else{
					me->start_busy(1);
					msg = HIW"结果只听拍的一声响，$n手中$W"HIW"为$N的$w所断，化为寸许的二三十截，飞上半空，闪出点点白光！\n" NOR;
					msg = replace_string(msg, "$W", wep->name());
					wep->unequip();
					wep->move(environment(target));
					wep->set("name", wep->query("name")+"碎片");
					wep->set("value", 0);
					wep->set("unit", "些");
					wep->delete("long");
					wep->set("weapon_prop", 0);
					target->reset_action();
				}
			}       
			else {       
				if(wep->query("rigidity") >= 8){
					me->start_busy(1);
					msg = HIY"结果只听一声大响，$W"HIY"在$w的冲击下不住颤抖，飞花四溅！\n" NOR;
				}
				else{
					me->start_busy(1);
					wep->move(environment(target));  
					msg = HIW"$n慌忙举$W"HIW"一挡，当的一声后，那"+wep->query("unit")+"$W"HIW"又被震飞！\n" NOR;
					target->reset_action();
				}
			}
			msg = replace_string(msg, "$W", wep->name());
			msg = replace_string(msg, "$w", "无形剑气");          
			message_vision(msg, me, target);
			call_out("check_6mai", 2+random(8-j), me, target);
		}
		else{
			target->receive_damage("kee", damage);
			target->receive_wound("kee", damage/(2+random(4)));          
			p = (int)target->query("kee")*100/(int)target->query("eff_kee");
			msg += damage_msg(damage, act["damage_type"]);
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg = replace_string(msg, "$l", limb);
			msg = replace_string(msg, "$w", "无形剑气");          
			message_vision(msg, me, target);
			if(wizardp(me)) tell_object(me, "6mai_damage: "+damage+" \n");
			call_out("check_6mai", 2+random(8-j), me, target);                   
		}
	}
	else{
		me->start_busy(1);
//             HIY"$N全力向后一纵一闪，凶险万分地避开了那急速而来的无形剑气！\n"NOR, target);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
		call_out("check_6mai", 2+random(10-j), me, target);    
	}                               
	if(target->query("kee")*2 <= target->query("max_kee")
	&& !target->is_killing(me->query("id"))
	&& !me->is_killing(target->query("id"))){
		me->remove_enemy(target);
		target->remove_enemy(me);
		if (me->query("race") == "人类") {
			if (!me->query("mute") && target->query("mute"))
				message_vision( winner_msg[random(sizeof(winner_msg)/2)], me, target);
			if (me->query("mute") && !target->query("mute"))
				message_vision(winner_msg[sizeof(winner_msg)/2 + random(sizeof(winner_msg)/2)], me, target);
			if (!me->query("mute") && !target->query("mute"))
				message_vision( winner_msg[random(sizeof(winner_msg))], me, target);
		} else
			message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, target);
	}

	return 1;
}       

