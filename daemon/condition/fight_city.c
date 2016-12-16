#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, object city, object who, int duration)
{
	if( duration < 1 )
	{
		tell_object(me, HIC "你的一轮攻势已经结束。城堡依旧岿然不动！\n" NOR );
		me->delete("attacking");
		city->delete("attacker");
		city->delete("receive_attack");
		return 0;
	}
	message_vision("城堡现在主人："+city->set("owner")+"你的id："+me->query("id")+"\n",who);
//	if( city->set("owner")!=me->query("id") ) {
	message_vision("$N开始对$n发动了第"+chinese_number(9-duration)+"次进攻！\n",
		me->query("name"),city->query("short"));
		COMBAT_D->do1_attack(me, city, who);
//	}
//	else {
//		return 0;
//	}

   me->apply_condition("fight_city", duration - 1);

   return CND_CONTINUE;
}
