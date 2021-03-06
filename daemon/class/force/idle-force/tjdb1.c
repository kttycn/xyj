#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object where=environment(me);

	if( where->query("no_fight") )
		return notify_fail("安全区内不能引动三界灵气！\n");
	if( !me->is_fighting() )
		return notify_fail("天惊地变只能在战斗中使用。\n");
//	if( me->query("family/family_name")!="武圣门"
//	&& !me->query("guild") )
//		return notify_fail("「天惊地变」是武圣门的不传之秘！\n");
	if( (int)me->query("force") < 3000 )
	if( me->query_temp("qiankun-tjdb") )
		return notify_fail("你刚使完「天惊地变」的绝招，目前气血翻涌，无法再次运用！\n");
		
	if( (int)me->query("kee") < 500)
		return notify_fail("你的力气不够了。\n");
	if( (int)me->query_skill("idle-force", 1) < 290)
		return notify_fail("你的回天神决修为还不够，使用这一招会有困难！\n");
                
	me->set_temp("wusheng-qiankun", 1);
	message_vision(HIB "\n$N双手擎天，渐渐天空中，浓云密罩、雷电交加、风云变色，万籁穹苍也似要裂开。\n\n半空之上，重云密怖，而更奇怪的是，天上竟凝聚了一团耀目光球。\n"NOR"\n"HIC"那光球环绕着闪烁电光，啪勒作响，凝在半空中，诡异非常。\n"NOR, me);
//	message_vision(HIB "\n半空之上，重云密怖，而更奇怪的是，天上竟凝聚了一团耀目光球。\n"NOR);
	message_vision(HIC "\n那光球环绕着闪烁电光，啪勒作响，凝在半空中，诡异非常。\n"NOR);
	
	me->start_busy(5);
	if(me->query("force")>3000)
		call_out("perform1",3, me,target);
	else
		return notify_fail("你的内力不够。\n");
	return 1;
}

int perform1(object me, object target)
{
	message_vision(HIR "\n$N运功已到最后阶段，身体竟冉冉上升，浑身笼罩着一团红光。\n$N身上的红光更盛，一道七色光华透过沉厚云层射在$N身上。\n"NOR, me);
	message_vision(RED "\n		“   叱！”!\n\n$N怒喝一声，天上的雷电光球似有所感应，从天上猛然坠下，犹如一颗流星，飞坠到$N双掌之上。\n\n"NOR, me);
//	message_vision(RED "\n		　　“   叱！”!\n"NOR);
//	message_vision(RED "\n$N怒喝一声，天上的雷电光球似有所感应，从天上猛然坠下，犹如一颗流星，飞坠到$N双掌之上。$N身上的红光更盛，一道七色光华透过沉厚云层射在$N身上。\n\n"NOR);
	me->start_busy(4);
	call_out("perform2",4, me,target);
	return 1;
}

int perform2(object me, object target)
{
//	object *ob, where;
	target = offensive_target(me);;
	int i, skill, damage, force;

//	where=environment(me);
	skill = me->query_skill("force");
	force = me->query("max_force");
	me->set("force", 0);
	me->receive_damage("kee", 500);
	message_vision(HIY "\n忽然$N狂吼，双掌托着雷电光球，以开天劈地之势，狂轰向一切！！！\n好一招毁天灭地，威力无俦的「天惊地变」！"NOR, me);
//	message_vision(HIC "\n忽然$N狂吼，双掌托着雷电光球，以开天劈地之势，狂轰向一切！！！\n好一招毁天灭地，威力无俦的「天惊地变」！\n\n"NOR, me);
	ob = offensive_target(me);
//	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
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
	me->start_busy(3);
	call_out("remove_effect",me->query_spi(), me); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) 
		return;
	me->delete_temp("qiankun-tjdb");
	tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「天惊地变」的绝招了。\n"NOR); 
}
