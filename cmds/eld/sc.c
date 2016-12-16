// make by enbsir
// ����Enbsir 2000/8/20

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
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	my = ob->query_entire_dbase();

//	line = sprintf( BOLD "\n%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
	line = sprintf(HIR"\n������"HIY+ CHINESE_MUD_NAME+"��\n");
//	str = "";
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] ) str = my["family"]["master_name"];
	}
	if( mapp(my["marks"]) ) {
		marks = keys( my["marks"] );
		for( i = 0; i < sizeof(marks); i ++ ) {
			if( str != "" ) str += "��";
			str += marks[i];
		}
	}

	line += sprintf( HIY"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�"NOR"\n");
	line += sprintf( BOLD " %s��" NOR, RANK_D->query_rank(ob));
	line += sprintf( " ������[%s% 6s%s]  �Ա�[%s% 6s%s] ���䣺[%s% 6s%s]\n"NOR"",
		HIC, ob->query("name"), NOR,
		HIC, ob->query("gender"), NOR,
		HIG, chinese_number(ob->query("age")), NOR );
	line += sprintf( " ���ࣺ[%s% 6s%s]  ȡ����[%s% 8d%s] ��ϵ��[%s%-25s%s]\n",
		HIC, ob->query("race"), NOR,
		HIC, ob->query("obstacle/number"), NOR,
		HIC, ob->query("title"), NOR );

	if( str != "" ) line += sprintf( " ʦ�У�[%s% 6s%s]  ���գ�[%s%-36s%s] \n",HIC, str, NOR,
		HIC, CHINESE_D->chinese_date(((int)ob->query("birthday") -14*365*24*60) * 60), NOR );

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK)/100;
	parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE)/100;
	dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE)/100;

	line += sprintf( " ���[%s %4d %s]  ",
		HIY, ob->query("str"), NOR );
	line += "����  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["gin"], HIG,
		HIM, my["max_gin"], HIG, HIR, my["max_gin"] - my["eff_gin"], NOR );

	line += sprintf( " ���ǣ�[%s %4d %s]  ",
		HIY, ob->query("con"), NOR );
                                
	line += "��Ѫ  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["kee"], HIG,
		HIM, my["max_kee"], HIG, HIR, my["max_kee"] - my["eff_kee"], NOR );

	line += sprintf( " ���ԣ�[%s %4d %s]  ",
		HIY, ob->query("int"), NOR );
	line += "����  " + tribar_graph(my["sen"], my["eff_sen"], my["max_sen"], BLINK, HIR ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %s%4d%s]\n", HIW, my["sen"], HIG,
		HIM, my["max_sen"], HIG, HIR, my["max_sen"] - my["eff_sen"], NOR );

	if( my["food"] * 100 / ob->max_food_capacity() > 10 ) str = HIC + "����";
	else str = HIR + "ȱʳ";
	line += sprintf( " ���ԣ�[%s %4d %s]  ",
		HIY, ob->query("spi"), NOR );
	line += "ʳ�" + tribar_graph(my["food"], ob->max_food_capacity(),
		ob->max_food_capacity(), MAG, HIC ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", HIC, my["food"], HIG,
		HIC, ob->max_food_capacity(), HIG, str, NOR );

	if( my["water"] * 100 / ob->max_water_capacity() > 10 ) str = HIC + "����";
	else str = HIR + "ȱˮ";
	line += sprintf( " ������[%s %4d %s]  ",
		HIY, ob->query("cps"), NOR );
	line += "��ˮ��" + tribar_graph(my["water"], ob->max_water_capacity(),
		ob->max_water_capacity(), MAG, HIC ,HIR)
		+ sprintf( "  [%s%4d%s / %s%4d%s , %4s%s]\n", HIC, my["water"], HIG,
		HIC, ob->max_water_capacity(), HIG,  str, NOR );

	line += sprintf( " ��ò��[%s %4d %s]  ",
		HIY, ob->query("per"), NOR );
	line += "�޳���" + tribar_graph(my["PKS"], my["MKS"] + my["PKS"],
		my["MKS"] + my["PKS"], MAG, HIR ,HIR)
		+ sprintf( "  [%s%4d%s +%s%5d%s =%s%5d%s]\n", HIR, my["PKS"], HIR,
		HIM, my["MKS"], HIR, RED, my["MKS"] + my["PKS"], NOR );

	line += sprintf( " ��ʶ��[%s %4d %s]  ",
		HIY, ob->query("cor"), NOR );
	line += sprintf("������[%s%12d%s (%s+%4d%s)%s]  ������[%s%12d%s]%s\n" NOR,
		HIC, attack_points + 1, HIG, HIW, ob->query_temp("apply/damage"), HIG, NOR,
		HIC, dodge_points + 1, NOR, NOR);

	line += sprintf( " ��Ե��[%s %4d %s]  ",
		HIY, ob->query("kar"), NOR );
//	line += sprintf( " ɱ����"GRN"["HIW"%6d"NOR""GRN"]"NOR"  ",
//		ob->query("MKS") );
	line += sprintf("������[%s%12d%s (%s+%4d%s)%s]  �мܣ�[%s%12d%s]%s\n"NOR,
		HIC, (dodge_points + (weapon ? parry_points: (parry_points/10))) + 1, HIG,
		HIW, ob->query_temp("apply/armor"), HIG, NOR,
		HIC, parry_points + 1, NOR, NOR);

	line += sprintf( " ɱ�ˣ�"GRN"["HIR"%6d"NOR""GRN"]"NOR"  ",
		ob->query("PKS") );
	line += sprintf("��ѧ��["BLINK"%s%20d%s"NOR"]  �����칬��[%s% 8d%s] \n",
		HIG, ob->query("combat_exp"), NOR,
		HIY, ob->query("dntg/number"), NOR);

	line += sprintf(" ������[%s% 6d%s]  ���У�["BLINK"%s%20d%s"NOR"]  Ǳ��[%s%14d%s] \n",
		HIR, ob->query("dietimes"), NOR,
		HIG, ob->query("daoxing"), NOR,
		HIY, (int)ob->query("potential") - (int)ob->query("learned_points"), NOR );

	line += sprintf( HIY"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�"NOR"\n\n");

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
ָ���ʽ��score
          score <��������>      ����ʦר�ã�

��ʾ�Լ�����ָ�����󣨺�����Ļ������ϡ���ָ����ԡ�sc�����档

���ѶϢ��hp
HELP
        );

        return 1;
}
