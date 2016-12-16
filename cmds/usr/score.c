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
		if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ×´Ì¬£¿\n");
	} else
		return notify_fail("Ö»ÓĞÎ×Ê¦ÄÜ²ì¿´±ğÈËµÄ×´Ì¬¡£\n");
	my = ob->query_entire_dbase();
	write(NOR YEL"¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô"HIG"¸ö"NOR YEL"¡Ô¡Ô"HIG"ÈË"NOR YEL"¡Ô¡Ô"HIG"µµ"NOR YEL"¡Ô¡Ô"HIG"°¸"NOR YEL"¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n"NOR);
	write("ÄãÏÖÔÚµÄ"HIR"ÏÉÏÎ"NOR" : "+RANK_D->query_rank(ob)+"\n");
	write("ÄãÏÖÔÚµÄ"HIR"Ö°Î»"NOR" : "+ob->short(1)+"\n");
	line = NOR YEL"¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô\n"NOR;
	str = "";
	if( mapp(my["family"]) )
		if( my["family"]["master_name"] ) str ="["+my["family"]["family_name"]+HIC+get_name(my["family"]["master_name"])+NOR+"]";

	line += sprintf( " ÄêÁä£º[%s%6s%s]   ÉúÈÕ£º[%s%-24s%s]\n",
		HIC, chinese_number(ob->query("age")), NOR,
		HIC, CHINESE_D->chinese_date(((int)ob->query("birthday")-900000000)*60), NOR );

	line += sprintf( " ĞÔ±ğ£º[ %s%-4s%s ]   ×î´ó¸ºÖØ£º[%s%-4s¹«½ï%s]   ÃÅÅÉ£º[%s%-6s%s]\n",
		HIC, ob->query("gender"), NOR,
		HIC, chinese_number((int)ob->query_weight()/1000), NOR,
		HIC, ob->query("family/family_name")?ob->query("family/family_name"):"ÆÕÍ¨°ÙĞÕ", NOR );
	if (ob->query("couple/name") != 0) line += sprintf(" »éÒö×´¿ö£º" HIG"°éÂÂ£º%-22s\n\n"NOR,ob->query("couple/name"));
	else line += sprintf(" »éÒö×´¿ö£º" MAG"Î´»é\t\t\t"NOR);
	if( str != "" ) line += sprintf( " Ê¦³Ğ£º%-23s%s\n",str, NOR );
	else line+="["CYN"Äã»¹Î´ÔøÇóÏÉ·ÃµÀ"NOR"]\n";

	masters = "";
	if( mapp(my["master"]) ) {
		marks = keys( my["master"] );
		for( i = 0; i < sizeof(marks); i ++ ) {
			if( masters != "" ) masters += "¡¢";
			masters += (string)ob->query("master/"+marks[i]);
		}
	}
	if (ob->query("master") != 0) line += sprintf(" Èı½ç×ğºÅ£º[%-20s]\n\n"NOR,masters);
	else line += " Èı½ç×ğºÅ£º["CYN"ÄãÏÖÔÚ»¹Î´Ôø³öÈËÍ·µØ"NOR"]\n";

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

	line += sprintf( " Ìå¸ñ£º[%s %4s %s]  ",
		NOR, display_attr(my["str"], ob->query_str()), NOR );
	if( my["eff_gin"] <my["max_gin"] ) str = HIR+"Éú²¡";
	else if( my["gin"]*100 / my["max_gin"]>=70 ) str = HIG + "±¥Âú";
	else if( my["gin"]*100 / my["max_gin"]>=40 ) str = HIR + "Æ£¾ë";
	else str = HIB + "ºÜÀÛ";
	line += "¡¼"HIR"¾«Éñ"NOR"¡½  " + tribar_graph(my["gin"], my["eff_gin"], my["max_gin"], NOR, HIR ,HIW)
		+ sprintf( "  [%4s%s]\n", str,NOR);
	line += sprintf( " ¸ù¹Ç£º[%s %4s %s]  ",
		NOR, display_attr(my["con"], ob->query_con()), NOR );
	if( my["eff_kee"] <my["max_kee"] ) str = HIR+"ÉË²Ğ";
	else if( my["kee"]*100 / my["max_kee"]>=70 ) str = HIG + "³äÅæ";
	else if( my["kee"]*100 / my["max_kee"]>=40 ) str = HIR + "ÊÜÉË";
	else str = HIB + "ÖØÉË";
	line += "¡¼"HIR"ÆøÑª"NOR"¡½  " + tribar_graph(my["kee"], my["eff_kee"], my["max_kee"], NOR, HIR ,HIW)
		+ sprintf( "  [%4s%s]\n",str,NOR);

	if( my["food"] * 100 / ob->max_food_capacity() >= 80 ) str = HIG+"ºÜ±¥";
	else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"Õı³£";
	else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"È±Ê³";
	else str = HIB + "¼¢¶ö";

	if( my["water"] * 100 / ob->max_water_capacity() > 60 ) str = HIG + "Õı³£";
	else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "È±Ë®";
	else str = HIB + "¼¢¿Ê";
	line += sprintf( " ÎòĞÔ£º[%s %4s %s]  ",
		NOR, display_attr(my["int"], ob->query_int()), NOR );
	line += "¡¼"HIC"Ê³Îï"NOR"¡½£º" + tribar_graph(my["food"], ob->max_food_capacity(),
		ob->max_food_capacity(), NOR, HIC ,HIR)
		+ sprintf( "  [%4s%s]\n", str, NOR );
	line += sprintf( " ÁéĞÔ£º[%s %4s %s]  ",
		NOR, display_attr(my["spi"], ob->query_spi()), NOR );
	line += "¡¼"HIC"ÒûË®"NOR"¡½£º" + tribar_graph(my["water"], ob->max_water_capacity(),
		ob->max_water_capacity(), NOR, HIC ,HIR)
		+ sprintf( "  [%4s%s]\n",  str, NOR );

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) ) 
		> RANK_D->grade_dx(CYN "µÀ¸ßµÂÂ¡" NOR) )
	look_sc = 1;

	line += sprintf( " ÈİÃ²£º[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["per"], ob->query_per()):"Òş²Ø", NOR );

	pk_dx=ob->query("kill/pkgain")-ob->query("kill/pklose");
	if (pk_dx>0)
		line += "¡¼"HIR"£Ğ£ËµÀĞĞÔö¼Ó"NOR"¡½£º "+COMBAT_D->chinese_daoxing(pk_dx)+"\n";
	else if (pk_dx<0)
		line += "¡¼"HIR"£Ğ£ËµÀĞĞ¼õÉÙ"NOR"¡½£º "+HIR+COMBAT_D->chinese_daoxing(-pk_dx)+NOR+"\n";
	else if (pk_dx==0)
		line += "¡¼"HIR"£Ğ£ËµÀĞĞÔö¼Ó"NOR"¡½£º "HIM"ÎŞ\n"NOR;

	line += sprintf( " ¸£Ôµ£º[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["kar"], ob->query_kar()):"Òş²Ø", NOR );

	if(ob->query("kill/nkgain") )
		line +="¡¼"HIR"£Î£ËµÀĞĞÔö¼Ó"NOR"¡½£º "+
			COMBAT_D->chinese_daoxing(ob->query("kill/nkgain"))+"\n";
	else if(!ob->query("kill/nkgain"))
		line += "¡¼"HIR"£Î£ËµÀĞĞÔö¼Ó"NOR"¡½£º "HIM"ÎŞ\n"NOR;

	line += sprintf( " µ¨Ê¶£º[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["cor"], ob->query_cor()):"Òş²Ø", NOR);

	line += "¡¼"HIR"ËÀÍö"NOR"¡½£º" 
		+ sprintf( "±»É±£º%s%s%s ´Î\n",  HIR, chinese_number((int) ob->query("death/count") ), NOR);

	line += sprintf( " ¶¨Á¦£º[%s %4s %s]  ",
		NOR, wizardp(me)||look_sc?display_attr(my["cps"], ob->query_cps()):"Òş²Ø", NOR);
    
	line += "¡¼"HIR"ÍÀÉ±"NOR"¡½£º" 
		+ sprintf( "É±º¦Íæ¼Ò£º%s%s%sÎ»£¬É±ËÀµĞÈË£º%s%d%sÃû\n",  HIR, chinese_number(my["PKS"]), NOR,
		HIW, my["MKS"], NOR);

	if((int)ob->query("balance"))
	line+= "¡¼"HIY"´æ¿î"NOR"¡½£º"+"/adm/daemons/moneyd.c"->money_str((int)ob->query("balance"))+"\n\n";
	else line+="¡¼"HIY"´æ¿î"NOR"¡½£º"+HIW"Ã»ÓĞÈÎºÎ´æ¿î"NOR+"\n\n";

      if(wizardp(this_player())) 
	line += sprintf(" Õ½¶·¹¥»÷Á¦ " HIW "%d (+%d)" NOR "\t\tÕ½¶··ÀÓùÁ¦ " HIW "%d (+%d)\n" NOR,
	attack_points/100 + 1, ob->query_temp("apply/damage"),
		(dodge_points + (weapon? parry_points: 
		(parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
	else line+=sprintf(" ±øÆ÷ÉËº¦Á¦£º ["HIR"%d"NOR"]" NOR "\t\t¿ø¼×±£»¤Á¦£º ["HIG"%d"NOR"]\n" NOR,
	ob->query_temp("apply/damage"),
	ob->query_temp("apply/armor"));

	line+= "¡¼"CYN"Èı½çÆÀ¼Û"NOR"¡½£º"+HIR""+(int)ob->query("score")+NOR+"\t\t¡¼"CYN"ÃÅÅÉÖÒ³Ï¶È"NOR"¡½"+HIR""+(int)ob->query("faith")+NOR+"\n\n";

	obstacles = ob->query("obstacle/number");
	if( obstacles==0 ) line += RED" Î÷ÌìÈ¡¾­"NOR"£ºÄã»¹Î´ÔøÌ¤ÉÏÈ¡¾­Ö®Â·\n";
	else if (obstacles == 35) line += RED" Î÷ÌìÈ¡¾­"NOR"£º"HIR"ÄãÎ÷ĞĞÇóÈ¡Õæ¾­ÒÑÀú¾¡ÁËËùÓĞµÄÄÑ¹Ø¡£\n"NOR;
	else line += sprintf(RED" Î÷ÌìÈ¡¾­"NOR"£ºÄãÒÑ¾­ÀúÁË"HIR"%s"NOR"µÀ½ÙÄÑ¡£\n", chinese_number(obstacles));
	dntg = ob->query("dntg/number");
	if (dntg == 0) line += " "RED"´óÄÖÌì¹¬"NOR"£ºÄã»¹Î´Ôø´óÄÖÌì¹¬\n";
	else if (dntg == 10) line += " "RED"´óÄÖÌì¹¬"NOR"£º"HIR"Äã´óÄÖÌì¹¬ÒÑ¾­¹¦µÂÔ²Âú£¡\n"NOR;
	else line+= RED" ´óÄÖÌì¹¬"NOR"£ºÄã´óÄÖÌì¹¬ÒÑ¹ı"HIR+chinese_number(dntg)+NOR"¹Ø¡£\n";

	line += sprintf(" µÀĞĞ¾³½ç£º[%s]       ÎäÑ§¾³½ç£º[%s]\n",
		 RANK_D->describe_dx(ob->query("daoxing")),  RANK_D->describe_exp(ob->query("combat_exp")) );
	line += sprintf(" ·¨Á¦ĞŞÎª£º[%s]       ÄÚÁ¦ĞŞÎª£º[%s]\n",
		 RANK_D->describe_fali(ob->query("max_mana")),  RANK_D->describe_neili(ob->query("max_force")) );
	line += YEL"¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô¡Ô "NOR+MAG+CHINESE_MUD_NAME+HIY"¡¤"NOR CYN+INTERMUD_MUD_NAME+NOR YEL" ¡Ô¡Ô¡Ô¡Ô\n"NOR;
	line += sprintf(CYN+" ÎªÇóÈ¡Õæ¾­%sÒÑÀú¾­ÁË"HIW"%s"NOR+CYN"µÄ¼èĞÁËêÔÂ \n"+NOR,ob==me?"Äã":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age") + (int)ob->query("age_modify")));

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
		if( i < n )  ret += "©¥";
		else ret += HIW"©¥"NOR;
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
Ö¸Áî¸ñÊ½£ºscore
          score <¶ÔÏóÃû³Æ>      £¨Î×Ê¦×¨ÓÃ£©

ÏÔÊ¾×Ô¼º»òÕßÖ¸¶¨¶ÔÏó£¨º¬¹ÖÎï£©µÄ»ù±¾×ÊÁÏ¡£´ËÖ¸Áî¿ÉÒÔ¡°sc¡±´úÌæ¡£

Ïà¹ØÑ¶Ï¢£ºhp
HELP
	);

	return 1;
}
