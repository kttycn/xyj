// toptenadd.c
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*astr, msg;
	int i;
	seteuid(geteuid(me));
	if (!arg||arg=="")
	{
		msg = HIY+"【 "+CHINESE_MUD_NAME+" 】"HIC"　目前有以下排行榜\n"NOR+
			HIM"────────────────────────────────"NOR+
			HIR"\n　　■ "+HIC+RICH_B+"　　　rich"+
			HIR"\n　　■ "+HIC+PKER_B+"　　　pker"+
			HIR"\n　　■ "+HIC+MASTER_B+"　　　master"+
			HIR"\n　　■ "+HIC+EXP_B+"　　　exp"+
			HIR"\n　　■ "+HIC+DX_B+"　　　dx"+
			HIR"\n　　■ "+HIC+KILL_B+"　　　killer"+
			HIR"\n　　■ "+HIC+SPELLS_B+"　　　spells"+
			HIR"\n　　■ "+HIC+FORCE_B+"　　　force"+
			HIR"\n　　■ "+HIC+PER1_B+"　　　per1"+
			HIR"\n　　■ "+HIC+PER2_B+"　　　per2"+
			HIR"\n　　■ "+HIC+AGE_B+"　　　age"+
			HIR"\n　　■ "+HIC+QUESTS_B+"　　　quests"+
			HIR"\n　　■ "+HIC+TASK_B+"　　　task"+
			HIM"\n────────────────────────────────"NOR;
		write ( msg+"\n");
		return 1;
	}
	str=TOPTEN_D->topten_query(arg);
	write(str+"\n");
	return 1;
}
/*
int help(object me)
{
write(@HELP
指令格式 : topten <类型> <玩家ID>
	类型：rich(十大富翁)|per1(十大白马王子)|per2(十大梦中情人)|spells(十大魔法高手)|  pker(十大杀人狂)|age(十大老不死)|exp(十大高手)|force(十大内力高手)|kill(十大魔头)
HELP
    );
    return 1;
}
*/
