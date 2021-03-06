// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"unarmed":	"拳脚",
	"sword":	"剑法",
	"blade":	"刀法",
	"stick":	"棍法",
	"staff":	"杖法",
	"throwing":	"暗器",
	"force":	"内功",
	"parry":	"招架",
	"dodge":	"轻功",
	"spells":	"法术",
	"whip" :	"鞭法",
	"spear":	"枪法",
	"axe":      "斧法",
	"mace":     "锏法",
	"fork":		"叉法",
	"rake":		"钯法",
	"archery":	"弓箭",
	"hammer":	"锤法",
	"halberd":  "戟法",
	"literate": "读书识字",
	"needle":   "针法",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;
	string check;
	object who;

	seteuid(getuid());
	if (!arg)
		return notify_fail("请正确使用命令：enable2 <id>\n");
	
	who = present( arg, environment(me) );

	if (!who) me = LOGIN_D->find_body(arg);
	if (!who) return notify_fail("没有这个人。\n");

	map = who->query_skill_map();
	if( !mapp(map) || sizeof(map)==0 )
		return notify_fail(who->query("name")+"现在没有使用任何特殊技能。\n");

	skill = keys(valid_types);
	write("以下是"+who->query("name")+"目前使用中的特殊技能。\n");
	for (i=0; i<sizeof(skill); i++) {
		if( undefinedp(valid_types[skill[i]]) ) {
			map_delete(map, skill[i]);
			continue;
		}
		if( !who->query_skill(skill[i]) ) continue;
		if( undefinedp(map[skill[i]]) ) continue;
		modify = who->query_temp("apply/" + skill[i]);
		printf("  %-20s： %-20s  有效等级：%s%4d\n" NOR, 
			valid_types[skill[i]] + " (" + skill[i] + ")",
			undefinedp(map[skill[i]]) ? 
			"无" : to_chinese(map[skill[i]]),
			(modify==0 ? "" : (modify>0 ? HIC : HIR)),
			who->query_skill(skill[i]));
	}
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : enable2 <id>

这个指令让你指定所要用的技能，需指明技能种类和技能名称。如果不加参
数则会显示出技能种类及你目前所使用的技能名称 ，如果加一个 ? 会列出
所有能使用特殊技能的技能种类。
 
HELP
        );
        return 1;
}
