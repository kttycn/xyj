// zhuanhuan.c

#include <skill.h>
#include <combat.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int amount, daoxing;

	seteuid(getuid());

	if( me->is_fighting() )
		return notify_fail("战斗中不能练转移潜能，会走火入魔。\n");

	if( !arg || !sscanf(arg, "%d", amount) )
		amount=50;

	if( amount < 1 ) return notify_fail("你最少要转移 1 点潜能。\n");

	if( (int)(me->query("potential")-me->query("learned_points")) < amount )
		return notify_fail("你没有这么多的潜能来转移。\n");

	if( (int)me->query("kee") < amount)
		return notify_fail("你现在精力太差了，无法凝神专一！少转点吧！\n");

	me->receive_damage("kee", amount);
        daoxing = (amount*3)/2;
	me->add("potential",-amount);
	me->add("daoxing", daoxing );

	write("ＯＫ！你把" + amount + "点潜能转换为" + COMBAT_D->chinese_daoxing(daoxing) + "道行！\n");
	log_file("cmds/zhuanhuan", sprintf("%s(%s) 将 %s 潜能转化成 %s 道行 时间 %s\n",
		me->query("name"),me->query("id"),chinese_number(amount),chinese_number(daoxing),ctime(time())));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : zhuanhuan [<耗费「潜能」的量，预设值 30>]

这个命令可以把你的潜能化为道行。
HELP
	);
	return 1;
}
 
