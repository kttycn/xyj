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
		return notify_fail("［一箭贯日月］只能对战斗中的对手使用。\n");
	if((int)me->query_skill("luori-archery", 1) <160)
		return notify_fail("你的落日箭法火候还不够！\n");
/*	if (me->query_skill_mapped("force")!="dragonforce")
		return notify_fail("落日箭法必须配合云龙神功才能使用。\n");
	if (me->query_skill_mapped("dodge")!="dragon-steps")
		return notify_fail("落日箭法必须配合神龙步才能使用。\n");
	if((int) me->query_skill("dragonforce",1) < 100)
		return notify_fail("你的［云龙神功］还不够精纯，不能发出［一箭贯日月］。\n");
	if((int) me->query_skill("dragon-steps",1) < 100)
		return notify_fail("你的［神龙步］还不够精纯，不能发出［一箭贯日月］。\n");
*/
	if (!target->is_fighting(me))
		return notify_fail("你们没有在打架！\n");
	if (!target->is_killing(me->query("id")))
		return notify_fail("好端端的比武，何必性命相搏？\n");
	if (me->query("force")<600)
		return notify_fail("你内力不继，心有余而力不足。\n");
	if (me->query("kee") < me->query("eff_kee")*90/100
	&& me->query("sen") < me->query("eff_sen")*90/100)
		return notify_fail("你的状况不好，强要使用［一箭贯日月］会走火入魔的。\n");

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
	message_vision(HIR"$N看着$n，大喝一声："HIW"［一箭贯日月］"HIR"，弓拉如满月，一箭向$n射去。\n"NOR,me,target);
	if( random(ap+dp) > dp/2 && random(2)>0)
	{
		if(me->query("force") > target->query("force")*2)
		{
			if(!weapon->query("name"))
			{
				msg = HIR"只听一声巨响。$n的$l被"+wp_name1+"贯穿！\n"NOR;
				target->receive_damage("kee", ap+random(ap)); 
				target->receive_wound("kee", ap+random(ap)); 
				p = (int)target->query("kee")*100/(int)target->query("max_kee");
				msg += damage_msg(ap+random(ap), "刺伤");
				msg += "( $n"+eff_status_msg(p)+" )\n";     
			} else
			{
				wp_name2 = weapon->query("name");
				if(weapon->query("rigidity") >=8 ){ // 判断武器硬度
					target->start_busy(1);
					weapon->move(environment(target)); // weapon->move(me)是什麽效果呢？
					target->receive_damage("kee", ap/2+random(ap)); 
					target->receive_wound("kee", ap/2+random(ap)); 
					msg = RED"只听“轰”的一声，$n手中的"+wp_name2+RED+
						"已被"+wp_name1+RED"震飞，虎口也在"+wp_name1+"的猛烈撞击下震裂！\n"NOR;
//					msg = replace_string(msg, "$w1", weapon2->name());
//					msg = replace_string(msg, "$w2", weapon1->name());
					p = (int)target->query("kee")*100/(int)target->query("max_kee");
					msg += damage_msg(ap/2+random(ap), "内伤");
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
					weapon->set("name", "断掉的"+weapon->query("name"));
					weapon->set("value", 0);
					weapon->delete("long");
					weapon->set("weapon_prop", 0);
					msg = HIW"只听“啪”的一声，$n手中的"+wp_name2+HIW+"已被"+wp_name1+HIW+
					"断为两截！\n"NOR;
					p = (int)target->query("kee")*100/(int)target->query("max_kee");
					msg += damage_msg(ap, "内伤");
					msg += "( $n"+eff_status_msg(p)+" )\n";     
//					msg += HIR+target->query("name")+"向后连退几步，只觉喉头一甜，“哇“的一声，吐出一口鲜血。"NOR;
				}
//					else { 
//						msg = MAG"只听一声巨响，"+target->query("name")+
//							"手中的$w1"MAG"在$w2"MAG"的冲击下不住颤抖，险些脱手！\n" NOR;
//							msg = replace_string(msg, "$w1", weapon2->name());
//							msg = replace_string(msg, "$w2", weapon1->name());
//					}
//				}
			}
		}
		msg = HIM"$n眼见这一箭来得太过凶猛，竟无处可避，急用手中的"+wp_name2+"挡去。\n"+
			"只听得“轰”的一声，$n在"+wp_name1+"的冲击下，向后猛退几步，“哇”的一声，吐出一口鲜。\n"NOR;
//			msg = replace_string(msg, "$w1", weapon2->name());
//			msg = replace_string(msg, "$w2", weapon1->name());
			target->receive_damage("kee", ap/4+random(ap)); 
			target->receive_wound("kee", ap/4+random(ap)); 
			p = (int)target->query("kee")*100/(int)target->query("max_kee");
			msg += damage_msg(ap/4+random(ap), "内伤");
			msg += "( $n"+eff_status_msg(p)+" )\n";     
	}
	else msg = HIM"$n眼见这一箭太过凶险，不敢去接，就地向旁一滚，险险地躲过了眼前这一箭。\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(1+random(3));

	return 1;
}
