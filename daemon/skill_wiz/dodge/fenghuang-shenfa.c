#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n一式「飞凰展翅」，前后脚脚尖脚跟相靠，身体如行云流水般滑出丈余。\n",
	"$n一式「雨燕掠波」，双臂前伸，全身贴地平飞，顿时闪过了$N的凌厉攻势。\n",
	"$n一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
	"$n一式「风驰电掣」，双脚点地，全身一道闪电，急速绕着$N飞奔。\n",
	"$n一式「孤骛落日」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
	"$n一式「鸿雁双飞」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。\n",
	"$n一式「苍龙出水」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
	"$n一式「稚凤归巢」，身体如陀螺般急转，气流形成一个个漩涡，令$N陷身其间，动弹不得。\n",
	"$n陡然使出「凤凰身法」之绝技「分身化影」，身形犹如鬼魅消失得无影无踪!\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力太差了，不练凤凰身法。\n");
	me->receive_damage("kee", 30);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60)
		return notify_fail("你现在脚下虚浮，先休息一阵吧。\n");
	if( (int)me->query("sen") < 60)
		return notify_fail("你的精神无法集中了，休息一下再进行参悟吧。\n");
	if((int)me->query("force") < 6 )
		return notify_fail("你现在内力不够，难以继续参悟下去了。\n");
	me->receive_damage("kee", 60);
	me->add("force", -6);
	return 1;
}
