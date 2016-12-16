inherit F_CLEAN_UP;
#include <ansi.h>

void remove_effect(object me, int amount);

int exert(object me, object target)
{  
	int skill;
	object room;
	me = this_player();

	if( (string)me->query("family/family_name") != "凤凰星" 
	&& !me->query("guild") )
		return notify_fail("你并非凤凰城中人，不能运用铜墙铁壁。\n");

	if (me->query_temp("防御"))
		return notify_fail("你刚刚已经使用过了铜墙铁壁！\n");
	if (me->query("force")<100)
		return notify_fail("你的内力不够！\n");
	if (me->query_skill("wuzu-xinfa", 1)<40)
		return notify_fail("你的无祖心法的级别不够！\n");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功级别不够！\n");
	message_vision("$N口中阵阵有词，顿时一阵白烟笼罩了$N，久久不散！\n",room);
	message_vision("你觉得自己的防御力增加了！\n",me);
	me->start_busy(3);
	me->set_temp("防御",1);
	me->add_temp("apply/armor", me->query("wuzu-xinfa")/3+me->query("spells")/5+random(50));
	me->add_temp("apply/dodge", me->query("wuzu-xinfa")/3+me->query("spells")/5+random(50));
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
	return 1;
}
void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("防御");
	tell_object(me, "你的铜墙铁壁运行完毕，将气息收回丹田。\n");
} 
