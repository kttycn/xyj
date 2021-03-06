// make by enbsir
// 烟仔Enbsir 2000/8/20

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, *marks;
	object weapon;
	int i, attack_points, dodge_points, parry_points;

	seteuid(getuid(me));
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();

//	line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
	line = sprintf(HIR"\n　■　"HIY+ CHINESE_MUD_NAME+"　\n");
//	str = "";
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] ) str = my["family"]["master_name"];
	}
	if( mapp(my["marks"]) ) {
		marks = keys( my["marks"] );
		for( i = 0; i < sizeof(marks); i ++ ) {
			if( str != "" ) str += "、";
			str += marks[i];
		}
	}

	line += sprintf( HIY"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡"NOR"\n");
	line += sprintf( BOLD " %s　" NOR, RANK_D->query_rank(ob));
	line += sprintf( " 姓名：[%s% 6s%s]  性别：[%s% 6s%s] 年龄：[%s% 6s%s]\n"NOR"",
		HIC, ob->query("name"), NOR,
		HIC, ob->query("gender"), NOR,
		HIG, chinese_number(ob->query("age")), NOR );
	line += sprintf( " 种类：[%s% 6s%s]  取经：[%s% 8d%s] 派系：[%s%-25s%s]\n",
		HIC, ob->query("race"), NOR,
		HIC, ob->query("obstacle/number"), NOR,
		HIC, ob->query("title"), NOR );

	if( str != "" ) line += sprintf( " 师承：[%s% 6s%s]  生日：[%s%-36s%s] \n",HIC, str, NOR,
		HIC, CHINESE_D->chinese_date(((int)ob->query("birthday") -14*365*24*60) * 60), NOR );

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK)/100;
	parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE)/100;
	dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE)/100;

	line += sprintf( " 体格：[%s %4d %s]  ",
		HIY, ob->query("str"), NOR );
	line += "魂魄  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["gin"], HIG,
		HIM, my["max_gin"], HIG, HIR, my["max_gin"] - my["eff_gin"], NOR );

	line += sprintf( " 根骨：[%s %4d %s]  ",
		HIY, ob->query("con"), NOR );
                                
	line += "气血  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["kee"], HIG,
		HIM, my["max_kee"], HIG, HIR, my["max_kee"] - my["eff_kee"], NOR );

	line += sprintf( " 悟性：[%s %4d %s]  ",
		HIY, ob->query("int"), NOR );
	line += "精神  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["sen"], HIG,
		HIM, my["max_sen"], HIG, HIR, my["max_sen"] - my["eff_sen"], NOR );

	if( my["food"] * 100 / ob->max_food_capacity() > 10 ) str = HIC + "正常";
	else str = HIR + "缺食";
	line += sprintf( " 灵性：[%s %4d %s]  ",
		HIY, ob->query("spi"), NOR );
	line += "食物：" + tribar_graph(my["food"], ob->max_food_capacity(),
		ob->max_food_capacity(), MAG, HIC ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", HIC, my["food"], HIG,
		HIC, ob->max_food_capacity(), HIG, str, NOR );

	if( my["water"] * 100 / ob->max_water_capacity() > 10 ) str = HIC + "正常";
	else str = HIR + "缺水";
	line += sprintf( " 定力：[%s %4d %s]  ",
		HIY, ob->query("cps"), NOR );
	line += "饮水：" + tribar_graph(my["water"], ob->max_water_capacity(),
		ob->max_water_capacity(), MAG, HIC ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", HIC, my["water"], HIG,
		HIC, ob->max_water_capacity(), HIG,  str, NOR );

	line += sprintf( " 容貌：[%s %4d %s]  ",
		HIY, ob->query("per"), NOR );
	line += "无常：" + tribar_graph(my["PKS"], my["MKS"] + my["PKS"],
		my["MKS"] + my["PKS"], MAG, HIR ,HIR)
		+ sprintf( "  [%s%4d%s +%s%5d%s =%s%5d%s]\n", HIR, my["PKS"], HIR,
		HIM, my["MKS"], HIR, RED, my["MKS"] + my["PKS"], NOR );

	line += sprintf( " 胆识：[%s %4d %s]  ",
		HIY, ob->query("cor"), NOR );
	line += sprintf("攻击：[%s%12d%s (%s+%4d%s)%s]  躲闪：[%s%12d%s]%s\n" NOR,
		HIC, attack_points + 1, HIG, HIW, ob->query_temp("apply/damage"), HIG, NOR,
		HIC, dodge_points + 1, NOR, NOR);

	line += sprintf( " 福缘：[%s %4d %s]  ",
		HIY, ob->query("kar"), NOR );
//	line += sprintf( " 杀生："GRN"["HIW"%6d"NOR""GRN"]"NOR"  ",
//		ob->query("MKS") );
	line += sprintf("防御：[%s%12d%s (%s+%4d%s)%s]  招架：[%s%12d%s]%s\n"NOR,
		HIC, (dodge_points + (weapon ? parry_points: (parry_points/10))) + 1, HIG,
		HIW, ob->query_temp("apply/armor"), HIG, NOR,
		HIC, parry_points + 1, NOR, NOR);

	line += sprintf( " 杀人："GRN"["HIR"%6d"NOR""GRN"]"NOR"  ",
		ob->query("PKS") );
	line += sprintf("武学：["BLINK"%s%20d%s"NOR"]  大闹天宫：[%s% 8d%s] \n",
		HIG, ob->query("combat_exp"), NOR,
		HIY, ob->query("dntg/number"), NOR);

	line += sprintf(" 死亡：[%s% 6d%s]  道行：["BLINK"%s%20d%s"NOR"]  潜能[%s%14d%s] \n",
		HIR, ob->query("dietimes"), NOR,
		HIG, ob->query("daoxing"), NOR,
		HIY, (int)ob->query("potential") - (int)ob->query("learned_points"), NOR );

	line += sprintf( HIY"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡"NOR"\n\n");

	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%4d", value );
        else if( value < gift ) return sprintf( HIC "%4d", value );
        else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
        int percent;

        if( max ) percent = current * 100 / max;
        else percent = 100;

        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 20;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 5;
        eff_n = eff * 100 / max / 5;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = NOR "[" + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "O";
                else ret += "-";
        }
        ret += fcolor + NOR "]";
        return ret;
}
int help(object me)
{
        write(@HELP
指令格式：score
          score <对象名称>      （巫师专用）

显示自己或者指定对象（含怪物）的基本资料。此指令可以“sc”代替。

相关讯息：hp
HELP
        );

        return 1;
}
