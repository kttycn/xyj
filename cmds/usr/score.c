//Cracked by Roath

#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);
string get_name(string str);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, masters, skill_type, *marks;
	object weapon;
	int i, attack_points, dodge_points, parry_points,obstacles,dntg, pk_dx, look_sc;

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
	write(NOR YEL"�ԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡ�"HIG"��"NOR YEL"�ԡԡԡԡԡԡԡԡԡ�\n"NOR);
	write("�����ڵ�"HIR"����"NOR" : "+RANK_D->query_rank(ob)+"\n");
	write("�����ڵ�"HIR"ְλ"NOR" : "+ob->short(1)+"\n");
	line = NOR YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR;
	str = "";
	if( mapp(my["family"]) )
		if( my["family"]["master_name"] ) str ="["+my["family"]["family_name"]+HIC+get_name(my["family"]["master_name"])+NOR+"]";

	line += sprintf( " ���䣺[%s%6s%s]   ���գ�[%s%-24s%s]\n",
		HIC, chinese_number(ob->query("age")), NOR,
		HIC, CHINESE_D->chinese_date(((int)ob->query("birthday")-900000000)*60), NOR );

	line += sprintf( " �Ա�[ %s%-4s%s ]   ����أ�[%s%-4s����%s]   ���ɣ�[%s%-6s%s]\n",
		HIC, ob->query("gender"), NOR,
		HIC, chinese_number((int)ob->query_weight()/1000), NOR,
		HIC, ob->query("family/family_name")?ob->query("family/family_name"):"��ͨ����", NOR );
	if (ob->query("couple/name") != 0) line += sprintf(" ����״����" HIG"���£�%-22s\n\n"NOR,ob->query("couple/name"));
	else line += sprintf(" ����״����" MAG"δ��\t\t\t"NOR);
	if( str != "" ) line += sprintf( " ʦ�У�%-23s%s\n",str, NOR );
	else line+="["CYN"�㻹δ�����ɷõ�"NOR"]\n";

	masters = "";
	if( mapp(my["master"]) ) {
		marks = keys( my["master"] );
		for( i = 0; i < sizeof(marks); i ++ ) {
			if( masters != "" ) masters += "��";
			masters += (string)ob->query("master/"+marks[i]);
		}
	}
	if (ob->query("master") != 0) line += sprintf(" ������ţ�[%-20s]\n\n"NOR,masters);
	else line += " ������ţ�["CYN"�����ڻ�δ������ͷ��"NOR"]\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	line += sprintf( " ���[%s %4s %s]  ",
		NOR, display_attr(my["str"], ob->query_str()), NOR );
	if( my["eff_gin"] <my["max_gin"] ) str = HIR+"����";
	else if( my["gin"]*100 / my["max_gin"]>=70 ) str = HIG + "����";
	else if( my["gin"]*100 / my["max_gin"]>=40 ) str = HIR + "ƣ��";
	else str = HIB + "����";
	line += "��"HIR"����"NOR"��  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], NOR, HIR ,HIW)
		+ sprintf( "  [%4s%s]\n", str,NOR);
	line += sprintf( " ���ǣ�[%s %4s %s]  ",
		NOR, display_attr(my["con"], ob->query_con()), NOR );
	if( my["eff_kee"] <my["max_kee"] ) str = HIR+"�˲�";
	else if( my["kee"]*100 / my["max_kee"]>=70 ) str = HIG + "����";
	else if( my["kee"]*100 / my["max_kee"]>=40 ) str = HIR + "����";
	else str = HIB + "����";
	line += "��"HIR"��Ѫ"NOR"��  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], NOR, HIR ,HIW)
		+ sprintf( "  [%4s%s]\n",str,NOR);

	if( my["food"] * 100 / ob->max_food_capacity() >= 80 ) str = HIG+"�ܱ�";
	else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"����";
	else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"ȱʳ";
	else str = HIB + "����";

	if( my["water"] * 100 / ob->max_water_capacity() > 60 ) str = HIG + "����";
	else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "ȱˮ";
	else str = HIB + "����";
	line += sprintf( " ���ԣ�[%s %4s %s]  ",
		NOR, display_attr(my["int"], ob->query_int()), NOR );
	line += "��"HIC"ʳ��"NOR"����" + tribar_graph(my["food"], ob->max_food_capacity(),
		ob->max_food_capacity(), NOR, HIC ,HIR)
		+ sprintf( "  [%4s%s]\n", str, NOR );
	line += sprintf( " ���ԣ�[%s %4s %s]  ",
		NOR, display_attr(my["spi"], ob->query_spi()), NOR );
	line += "��"HIC"��ˮ"NOR"����" + tribar_graph(my["water"], ob->max_water_capacity(),
		ob->max_water_capacity(), NOR, HIC ,HIR)
		+ sprintf( "  [%4s%s]\n",  str, NOR );

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) ) 
		> RANK_D->grade_dx(CYN "���ߵ�¡" NOR) )
	look_sc = 1;

	line += sprintf( " ��ò��[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["per"], ob->query_per()):"����", NOR );

	pk_dx=ob->query("kill/pkgain")-ob->query("kill/pklose");
	if (pk_dx>0)
		line += "��"HIR"�У˵�������"NOR"���� "+COMBAT_D->chinese_daoxing(pk_dx)+"\n";
	else if (pk_dx<0)
		line += "��"HIR"�У˵��м���"NOR"���� "+HIR+COMBAT_D->chinese_daoxing(-pk_dx)+NOR+"\n";
	else if (pk_dx==0)
		line += "��"HIR"�У˵�������"NOR"���� "HIM"��\n"NOR;

	line += sprintf( " ��Ե��[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["kar"], ob->query_kar()):"����", NOR );

	if(ob->query("kill/nkgain") )
		line +="��"HIR"�Σ˵�������"NOR"���� "+
			COMBAT_D->chinese_daoxing(ob->query("kill/nkgain"))+"\n";
	else if(!ob->query("kill/nkgain"))
		line += "��"HIR"�Σ˵�������"NOR"���� "HIM"��\n"NOR;

	line += sprintf( " ��ʶ��[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["cor"], ob->query_cor()):"����", NOR);

	line += "��"HIR"����"NOR"����" 
		+ sprintf( "��ɱ��%s%s%s ��\n",  HIR, chinese_number((int) ob->query("death/count") ), NOR);

	line += sprintf( " ������[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["cps"], ob->query_cps()):"����", NOR);
    
	line += "��"HIR"��ɱ"NOR"����" 
		+ sprintf( "ɱ����ң�%s%s%sλ��ɱ�����ˣ�%s%d%s��\n",  HIR, chinese_number(my["PKS"]), NOR,
		HIW, my["MKS"], NOR);

	if((int)ob->query("balance"))
	line+= "��"HIY"���"NOR"����"+"/adm/daemons/moneyd.c"->money_str((int)ob->query("balance"))+"\n\n";
	else line+="��"HIY"���"NOR"����"+HIW"û���κδ��"NOR+"\n\n";

      if(wizardp(this_player())) 
	line += sprintf(" ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n" NOR,
	attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: 
		(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
	else line+=sprintf(" �����˺����� ["HIR"%d"NOR"]" NOR "\t\t���ױ������� ["HIG"%d"NOR"]\n" NOR,
	ob->query_temp("apply/damage"),
	ob->query_temp("apply/armor"));

	line+= "��"CYN"��������"NOR"����"+HIR""+(int)ob->query("score")+NOR+"\t\t��"CYN"�����ҳ϶�"NOR"��"+HIR""+(int)ob->query("faith")+NOR+"\n\n";

	obstacles = ob->query("obstacle/number");
	if( obstacles==0 ) line += RED" ����ȡ��"NOR"���㻹δ��̤��ȡ��֮·\n";
	else if (obstacles == 35) line += RED" ����ȡ��"NOR"��"HIR"��������ȡ�澭�����������е��ѹء�\n"NOR;
	else line += sprintf(RED" ����ȡ��"NOR"�����Ѿ�����"HIR"%s"NOR"�����ѡ�\n", chinese_number(obstacles));
	dntg = ob->query("dntg/number");
	if (dntg == 0) line += " "RED"�����칬"NOR"���㻹δ�������칬\n";
	else if (dntg == 10) line += " "RED"�����칬"NOR"��"HIR"������칬�Ѿ�����Բ����\n"NOR;
	else line+= RED" �����칬"NOR"��������칬�ѹ�"HIR+chinese_number(dntg)+NOR"�ء�\n";

	line += sprintf(" ���о��磺[%s]       ��ѧ���磺[%s]\n",
		 RANK_D->describe_dx(ob->query("daoxing")),  RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf(" ������Ϊ��[%s]       ������Ϊ��[%s]\n",
		 RANK_D->describe_fali(ob->query("max_mana")),  RANK_D->describe_neili(ob->query("max_force")) );
	line += YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ� "NOR+MAG+CHINESE_MUD_NAME+HIY"��"NOR CYN+INTERMUD_MUD_NAME+NOR YEL" �ԡԡԡ�\n"NOR;
	line += sprintf(CYN+" Ϊ��ȡ�澭%s��������"HIW"%s"NOR+CYN"�ļ������� \n"+NOR,ob==me?"��":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age") + (int)ob->query("age_modify")));

	write(line+BBLK);
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
	int i, n, eff_n, max_n = 12;

	if( max == 0 ) max = 1;
	n = val * 100 / max / 10;
	eff_n = eff * 100 / max / 10;

	if( n < 0 ) n = 0;
	if( eff_n < 0 ) eff_n = 0;
	if( n > max_n ) n = max_n;
	if( eff_n > max_n ) eff_n = max_n;

	ret = NOR  + bcolor + fcolor ;
	for( i = 0 ; i < max_n; i ++ ) {
		if( i > eff_n ) ret += dcolor;
		if( i < n )  ret += "��";
		else ret += HIW"��"NOR;
	}
	ret += fcolor + NOR ;
	return ret;
}

string get_name(string str)
{
	string str1, str2;

	while(sscanf(str,"%s%*sm%s",str1,str2)==3)
		str=str1+str2;
	return str;
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