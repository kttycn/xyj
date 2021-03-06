#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object where=environment(me);

	if( where->query("no_fight") )
		return notify_fail("安全区内不能引动九天灵气！\n");
	if( !me->is_fighting() )
		return notify_fail("倒转乾坤只能在战斗中使用。\n");
	if( me->query("family/family_name")!="武圣门"
	&& !me->query("guild") )
		return notify_fail("「倒转乾坤」是武圣门的不传之秘！\n");
	if( (int)me->query("force") < 3000 )
	if( me->query_temp("wusheng-qiankun") )
		return notify_fail("你刚使完「倒转乾坤」的绝招，目前气血翻涌，无法再次运用！\n");
		
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了。\n");
	if( (int)me->query_skill("xiantian-force", 1) < 290)
		return notify_fail("你的先天乾坤功修为还不够，使用这一招会有困难！\n");
                
	me->set_temp("wusheng-qiankun", 1);
	message_vision(HIB "\n$N飞身而上，屏气凝神，双手对天一指，引动出九天灵气归于己用！\n\n"NOR, me);

	me->start_busy(3);
	if(me->query("force")>3000)
		call_out("perform1",3, me,target);
	else
		return notify_fail("你的内力不够。\n");
	return 1;
}

int perform1(object me, object target)
{
	message_vision(HIB "\n渐渐地天昏地暗，日月无光，天地颠倒！\n\n"NOR, me);
	me->start_busy(4);
	call_out("perform2",4, me,target);
	return 1;
}

int perform2(object me, object target)
{
	object *ob, where;
	int i, skill, damage, force;

	where=environment(me);
	skill = me->query_skill("force");
	force = me->query("max_force");
	me->set("force", 0);
	me->receive_damage("kee", 500);

	message_vision(HIY "\n忽然$N双手一推，只见风云色变，神泣佛悲！\n好一招灭绝众生的「倒转乾坤」！\n\n"NOR, me);
	ob = all_inventory(environment(me));
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
	call_out("remove_effect",me->query_spi(), me); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) 
		return;
	me->delete_temp("wusheng-qiankun");
	tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「倒转乾坤」的绝招了。\n"NOR); 
}
