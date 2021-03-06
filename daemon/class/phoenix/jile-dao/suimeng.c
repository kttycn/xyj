//stone created 20020307
//碎梦一刀。
inherit SSERVER;

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//inherit F_CLEAN_UP;

//int exert(object me, object target)
int perform(object me, object target)
{
	object weapon;
	object where=environment(me);
	int dayphase;
	dayphase =NATURE_D->query_current_day_phase();

	if( where->query("no_fight") )
		return notify_fail("安全区内不能引动九天灵气！\n");
	if (dayphase > 6)
		 return notify_fail("碎梦一刀只有白天才能施展！\n");
	if( !me->is_fighting() )
		return notify_fail("碎梦一刀只能在战斗中使用。\n");
	if( me->query("family/family_name")!="凤凰星"
	&& !me->query("guild") )
		return notify_fail("「碎梦一刀」是凤凰星的不传之秘！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("force") < 3000 )
	if( me->query_temp("phoenix-suimeng") )
		return notify_fail("你刚使完「碎梦一刀」的绝招，目前气血翻涌，无法再次运用！\n");
		
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了。\n");
//	if( (int)me->query("max_force") < 1200 )
//		return notify_fail("你现在内力不足，使不出碎梦一刀！\n");
	if( (int)me->query_skill("jile-dao", 1) < 290)
		return notify_fail("你的极乐刀法修为还不够，使用这一招会有困难！\n");
                
	me->set_temp("phoenix-suimeng", 1);
	message_vision(HIC "\n$N仰天一声长啸，龙吟般的音韵直插云霄。\n刀身如同蟠龙般游踪不定。虽不动，却已包含了千万次的剧动。\n\n"NOR, me);

	me->start_busy(3);
	if(me->query("force")>3000)
		call_out("perform1",3, me,target);
	else
		return notify_fail("你的内力不够。\n");
	return 1;
}

int perform1(object me, object target)
{
	message_vision(HIY "\n$N手中亮起一团柔和的光华，紧紧的包围着刀刃。\n\n"NOR, me);
	me->start_busy(4);
	call_out("perform2",4, me,target);
	return 1;
}

int perform2(object me, object target)
{
//	object *ob, where;	
	int i, skill, damage, force;
	object *ob
//	where=environment(me);
	skill = me->query_skill("force");
	force = me->query("max_force");
	me->set("force", 0);
	me->receive_damage("kee", 500);

	message_vision(HIY "\n忽然$N劈出了「碎梦一刀」\n这聚合了天地霸气的一刀，也是融会了宇宙灵慧的一刀。\n无处不在的空气在刀气的刺激之下也退避三舍。\n"NOR, me);
	message_vision(HIR "$p的鲜血已染满了刀刃。\n"NOR, me);
	message_vision(HIM"慢慢的一道美丽的虹升起，很迷人，和梦中见过的那道一模一样。\n\n"NOR, me);
//	ob = all_inventory(environment(me));
	ob = target
	for(i=0; i<sizeof(ob); i++) {
		if( !living( ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

		damage = ( skill + force) * 10 - ((int)ob[i]->query("max_force") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("sen", damage, me);
			if( (int)ob[i]->query("force") < skill * 2 )
				ob[i]->receive_wound("sen", damage/10, me);
				tell_object(ob[i], "你觉得眼前一阵金星乱冒，浑身痛得像是要裂开一样！\n");
		}
		COMBAT_D->report_sen_status(ob[i]);		
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	call_out("remove_effect",me->query_spi(), me); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) 
		return;
	me->delete_temp("phoenix-suimeng");
	tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「碎梦一刀」的绝招了。\n"NOR); 
}
