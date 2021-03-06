// 清心普善咒
// 专解情毒，这么好，什么时候帮我也解解，呵呵
// xintai 2/3/2001

#include <ansi.h>

int cast(object me, object target)
{
	if ( !target
	|| !userp(target)
	|| target->is_corpse()
	|| target==me)
		return notify_fail("你想替谁解除情毒？\n");
	if (!target->query_condition("xiangsi"))
		return notify_fail("那个人根本没中情毒，开什么玩笑？！\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法解毒！\n");

	if( (int)me->query("mana")  <  1200 )
		return notify_fail("你的法力不够。\n");

	if ( (int)me->query_skill("pansi-dafa") < 120)
		return notify_fail("你的盘丝大法等级不够，不要勉强啦！\n");

	message_vision(
		HIB "$N坐下来将$n默默的揽入怀中，$n感受$N爱人般的温暖，心情慢慢地平复下来。\n\n"NOR,
		me, target );
	if (random(me->query_skill("pansi-dafa", 1)-60)>10){
		target->apply_condition("xiangsi",0);
		message_vision(
		HIY "$N唱起了宁和的歌曲，$n心中既感激，又安慰，在那温柔的歌声中慢慢进入了睡乡。\n"NOR,
		me, target );
		target->set_temp("force_sleep",1);
		target->command_function("sleep");

		target->delete_temp("force_sleep");	}
	else {
		message_vision(
		HIY "$N突然脸色苍白，似乎心力有所不及，竟呕出一口血来……\n"NOR,
		 me, target );
	}	
                
	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("mana", -300);
	me->set("mana_factor", 0);

	return 1;
}
