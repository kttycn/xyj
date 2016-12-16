// rankd.c

#include <ansi.h>

//descriptions...

//note, be careful with the size of this list, dx increases as n^3. 
string *dx_level_desc = ({
	BLU "�����;" NOR, //in unit of year 
	BLU "�ŵ���ϲ" NOR, //1x2=2
	BLU "�������" NOR, //8x2=16
	BLU "��ͨ����" NOR, //27x2=56
	HIB "����Ѿ�" NOR, //64x2=128
	HIB "Ԫ�����" NOR, //125x2=250
	HIB "�����ȹ�" NOR, //216x2=432
	HIB "һ��ǧ��" NOR, //343x2=686
	CYN "���ߵ�¡" NOR, //512x2=1024
	CYN "��̥����" NOR, //729x2=1458
	CYN "ϼ�ٷ���" NOR, //1000x2=2000
	CYN "��������" NOR, //1331x2=2662
	HIC "�����ֻ�" NOR, //1728x2=3456
	HIC "��֤���" NOR, //2197x2=4394
	HIC "��豹���" NOR, //2744x2=5688
	HIW "���˺�һ" NOR  //3375x2=6750
});

string *fali_level_desc = ({
	BLU "���߷���" NOR, //    
	BLU "�����仯" NOR, //1x40=40
	BLU "��������" NOR, //4x40=160
	HIB "���Ƽ���" NOR, //9x40=360   
	HIB "�����û" NOR, //16x40=640
	HIB "Ԥ֪����" NOR, //25x40=1000
	HIB "�������" NOR, //36x40=1440    
	CYN "���绽��" NOR, //49x40=1960
	CYN "������ɽ" NOR, //64x40=2560    
	CYN "���ǻ���" NOR, //81x40=3240
	CYN "��������" NOR, //100x40=4000
	HIC "��������" NOR, //121x40=4840    
	HIC "�任Ī��" NOR, //144x40=5760
	HIW "�����ޱ�" NOR  //169x40=6760
});

string *exp_level_desc = ({
/*	BLU "��ѧէ��" NOR,
	BLU "�����ž�" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��֪һ��" NOR,
	YEL "��������" NOR,
	YEL "������" NOR,
	HIY "����С��" NOR,
	HIY "����Ѿ�" NOR,
	HIM "�������" NOR,
	HIM "��Ȼ����" NOR,
	HIR "�������" NOR,
	HIR "�������" NOR,
	MAG "����似" NOR,
	MAG "�����뻯" NOR,
	CYN "��Ȼ��ͨ" NOR,
	CYN "�Ƿ��켫" NOR,
	HIC "������˫" NOR,
	HIC "һ����ʦ" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
*/
	BLU "����һ��" NOR,
	BLU "��������" NOR,
	HIB "����ҳ�" NOR,
	HIB "��ѧէ��" NOR,
	HIB "����ǿǿ" NOR,
	YEL "�����ž�" NOR,
	YEL "����é®" NOR,
	YEL "��֪һ��" NOR,
	HBYEL "����ͨͨ" NOR,
	HBYEL "ƽƽ����" NOR,
	HBYEL "ƽ������" NOR,
	HBBLU "��ͨƤë" NOR,
	HBBLU "��������" NOR,
	HBBLU "������" NOR,
	BBLU "����С��" NOR,
	BBLU "����С��" NOR,
	BBLU "������Ⱥ" NOR,
	BMAG "�������" NOR,
	BMAG "�������" NOR,
	BMAG "�ڻ��ͨ" NOR,
	HIY "�������" NOR,
	HIY "¯����" NOR,
	HIY "��Ȼ����" NOR,
	HIM "���д��" NOR,
	HIM "���д��" NOR,
	HIM "��Ȼ��ͨ" NOR,
	HIR "�������" NOR,
	HIR "�޿�ƥ��" NOR,
	HIR "����Ⱥ��" NOR,
	BRED "����似" NOR,
	BRED "�����뻯" NOR,
	BRED "��ͬ����" NOR,
	HBRED "����Ⱥ��" NOR,
	HBRED "�Ƿ��켫" NOR,
	HBRED "�����ױ�" NOR,
	MAG "��������" NOR,
	MAG "һ����ʦ" NOR,
	MAG "�������" NOR,
	CYN "�񹦸���" NOR,
	CYN "������˫" NOR,
	CYN "��������" NOR,
	HIC "���춯��" NOR,
	HIC "������" NOR,
	HIC "������ʥ" NOR,
	WHT "�������" NOR,
	WHT "��ǰ����" NOR,
	WHT "���˺�һ" NOR,
	HIW "��ز�¶" NOR,
	HIW "��ɲ�" NOR,
	HIW "��豹���" NOR

});

string describe_dx(int value)
{
	int grade, two_year, n;
	
	two_year = value/2000;
	for(grade=0; grade<sizeof(dx_level_desc); grade++) 
	{
		n = (grade+1)*(grade+1)*(grade+1);
		if( two_year<n ) break;
	}
	if( grade>=sizeof(dx_level_desc) ) grade=sizeof(dx_level_desc)-1;
	return dx_level_desc[grade];
}

int grade_dx(string desc)
{
	int grade, n;

	for(grade=0; grade<sizeof(dx_level_desc); grade++) 
	{
		n = grade;
		if ( dx_level_desc[grade] == desc )
			return n;
	}
	return 0;
}

string describe_exp(int value)
{
	int grade, lvl , n;
	
	lvl = (value)/45;
	//note, this is to make ��ɲ� requires 2700k combat_exp,
	//which also means player can learn skill level to 300.

	for(grade=0; grade<sizeof(exp_level_desc); grade++) 
	{
		n = (grade+1)*(grade+1)*(grade+1);
		if( lvl<n ) break;
	}
	if( grade>=sizeof(exp_level_desc) ) grade=sizeof(exp_level_desc)-1;
	return exp_level_desc[grade];
}

int grade_exp(string desc)
{
	int grade, n;

	for(grade=0; grade<sizeof(exp_level_desc); grade++) 
	{
		n = grade;
		if ( exp_level_desc[grade] == desc )
			return n;
	}
	return 0;
}

string describe_neili(int value)
{
	int year, sixty, left;
	string line;
	
	year = value/100;
	sixty = year/60;
	left = year - sixty*60;

	if( year <= 0 )
	{
		line = HIB "����һ��" NOR;
		return line;
	}
	
	if(sixty > 0 )
	{
		if ( left != 0 )
		{ 
			line = HIW + chinese_number(sixty) + "����" + NOR + "��" +  HIR + chinese_number(left) + "��" + NOR;
		}
		else 
		{
			line = HIW + chinese_number(sixty) + "����"  + NOR;	
		}		
	}
	else 
		line = HIR + chinese_number(year)+"��" + NOR;

	return line;
}

string describe_fali(int value)
{
	int grade, lvl, n;

	//in unit of 40, increase by n^2.
	lvl=value/40;
	for(grade=0; grade<sizeof(fali_level_desc); grade++) 
	{
		n=(grade+1)*(grade+1);
		if( lvl<n ) break;
	}
	if( grade>=sizeof(fali_level_desc) ) grade=sizeof(fali_level_desc)-1;
	return fali_level_desc[grade];
}
 
int grade_fali(string desc)
{
	int grade;

	for(grade=0; grade<sizeof(fali_level_desc); grade++) 
	{
		if ( (string)fali_level_desc[grade] == desc )
			return grade;
	}
	return 0;
}

string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    
    if(type==0) level_desc = dx_level_desc;
    else if(type==1) level_desc = exp_level_desc;
    else level_desc = fali_level_desc;
    
    for(i=0; i<sizeof(level_desc); i++)
    {
	line += level_desc[i] + "    ";
	if( (i%4)==3 ) line += "\n";
    }
    
    return line;
}

string _query_rank(object ob);

string query_rank(object ob)
{
    string rank=_query_rank(ob);
    string s1,s2,s3;
    int len, len1, len2;
    
    if(sscanf(rank,"%s��%s��%s",s1,s2,s3)!=3) return rank;
    len=14-sizeof(s2);
    if(len<1) return rank;

    len1=len/2;
    len2=len-len1;
    if(len1) s2=repeat_string(" ",len1)+s2;
    if(len2) s2+=repeat_string(" ",len2);
    
    return s1+"��"+s2+"��"+s3;
}

string _query_rank(object ob)
{
	string at;
	int dx, exp, avg, age;

	if(strlen(ob->query("added_title"))<1) ob->set("added_title", "����");
	//need this default, otherwise looks too ugly sometimes.

	at = ob->query("added_title");
	dx = (int)ob->query("daoxing");
	exp = (int)ob->query("combat_exp");
	avg = (dx + exp)/2;
	age = ob->query("age");

	if( ob->is_ghost() ) return HIB "�� �ڰ����� ��" NOR;
	switch(ob->query("gender")) 
	{
		case "Ů��":
		case "����":
			switch(wizhood(ob)) {
				case "(admin)":	    return HIW "�� Ů  �� ��" NOR;
				case "(arch)":		return HIR "�� ��  �� ��" NOR;
				case "(wizard)":	return HIY "�� ��  Ů ��" NOR;
				case "(apprentice)":	return HIG "�� ��ħŮ ��" NOR;
				case "(immortal)":      return HIM "�� ħ  Ů ��" NOR;
				case "(elder)":      	return HIB "�� С���� ��" NOR;
				default:
					switch(ob->query("class")) 
					{
//------------------rank for girls--------------------
/*�����(phoenix) - HIR  ���ƶ�(yaomo) - RED  ������(fighter) - HIR  ����ɽ(xian) - GRN
��ɽ����(swordsman) - HIG  ��ׯ��(xian) - YEL  �Ϻ�����ɽ(bonze) - HIY  �ݿ�ɽ�޵׶�(yaomo) - BLU
���޵ظ�(youling) - HIB  ��˿��(xian) - MAG  �¹�(moon) - HIM  ����ɽ���Ƕ�(taoism) - CYN
��������(dragon) - HIC  ��ʥ��(wusheng) - WHT  ��ѩɽ(yaomo) - HIW 
��ԯ��Ĺ(huli) - HIW
*/
case "xian":
	if ( ob->query("family/family_name") == "��ׯ��" )
		if(dx<1000) 
			return YEL "�� ��  Ů ��" NOR;
		else if(dx<10000) 
			return YEL "�� ��  Ů ��" NOR;	
		else if(dx<100000) 
			return YEL "�� ��  �� ��" NOR;
		else if(dx<500000) 
			return YEL "�� ʥ  Ů ��" NOR;
		else if(dx<1000000) 
			return YEL "��"+at+"������" NOR;	
		else if(dx<5000000) 
			return YEL "��"+at+"ʥĸ��" NOR;	
		else 
			return YEL "��"+at+"���" NOR;
	if ( ob->query("family/family_name") == "��˿��" )
		if(avg<1000) 
			return MAG "�� С��Ů ��" NOR;
		else if(avg<10000) 
			return MAG "�� ��  Ů ��" NOR;	
		else if(avg<100000) 
			return MAG "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return MAG "�� ʥ  Ů ��" NOR;
		else if(avg<1000000) 
			return MAG "��"+at+"��Ů��" NOR;	
		else if(avg<5000000) 
			return MAG "��"+at+"���ɡ�" NOR;	
		else 
			return MAG "��"+at+"�ɺ�" NOR;
	if ( ob->query("family/family_name") == "�¹�" )
		if(dx<1000) 
			return HIM "�� ��  Ů ��" NOR;
		else if(dx<10000) 
			return HIM "�� ��  Ů ��" NOR;	
		else if(dx<100000) 
			return HIM "�� ��  �� ��" NOR;
		else if(dx<500000) 
			return HIM "�� ʥ  Ů ��" NOR;
		else if(dx<1000000) 
			return HIM "��"+at+"������" NOR;	
		else if(dx<5000000) 
			return HIM "��"+at+"ʥĸ��" NOR;	
		else 
			return HIM "��"+at+"�ɺ�" NOR;
	break;
case "wusheng":		           
	if(dx<1000) 
		return WHT "�� Ů��ʿ ��" NOR;
	else if(dx<10000) 
		return WHT "�� ����ɲ ��" NOR;	
	else if(dx<100000) 
		return WHT "�� Ů�޺� ��" NOR;	
	else if(dx<500000) 
		return WHT "���������ߡ�" NOR;
	else if(dx<1000000) 
		return WHT "��"+at+"Ů���ߡ�" NOR;	
	else if(dx<5000000) 
		return WHT "��"+at+"ʥ����" NOR;	
	else 
		return WHT "��"+at+"��ۡ�" NOR;
	break;
case "swordsman":
	if(exp<1000) 
		return HIG "�� Ů��ͯ ��" NOR;
	else if(exp<10000) 
		return HIG "�� Ů��ʿ ��" NOR;	
	else if(exp<100000) 
		return HIG "�� Ů���� ��" NOR;
	else if(exp<500000) 
		return HIG "�� Ů���� ��" NOR;
	else if(exp<1000000) 
		return HIG "��"+at+"Ů������" NOR;	
	else if(exp<5000000) 
		return HIG "��"+at+"Ů���ɡ�" NOR;	
	else
		return HIG "��"+at+"Ů��ʥ��" NOR;
	break;
case "hero":
	if(exp<1000) 
		return GRN "�� Ů���� ��" NOR;
	else if(exp<10000) 
		return GRN "�� Ů���� ��" NOR;	
	else if(exp<100000) 
		return GRN "�� Ů��ʿ ��" NOR;
	else if(exp<500000) 
		return GRN "�� Ů���� ��" NOR;
	else if(exp<1000000) 
		return GRN "��"+at+"Ů����" NOR;	
	else if(exp<5000000) 
		return GRN "��"+at+"������" NOR;	
	else
		return GRN "��"+at+"Ůʥ��" NOR;
	break;
case "yaomo":
	if ( ob->query("family/family_name") == "��˿��" )
		if(avg<1000) 
			return MAG "�� С��Ů ��" NOR;
		else if(avg<10000) 
			return MAG "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return MAG "�� Ů  �� ��" NOR;
		else if(avg<500000) 
			return MAG "�� Ů  ħ ��" NOR;
		else if(avg<1000000) 
			return MAG "��"+at+"ħŮ��" NOR;	
		else if(avg<5000000) 
			return MAG "��"+at+"������" NOR;	
		else 
			return MAG "��"+at+"Ů����" NOR;
	if ( ob->query("family/family_name") == "���ƶ�" )
		if(avg<1000) 
			return RED "�� С��Ů ��" NOR;
		else if(avg<10000) 
			return RED "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return RED "�� Ů  �� ��" NOR;
		else if(avg<500000) 
			return RED "�� Ů  ħ ��" NOR;
		else if(avg<1000000) 
			return RED "��"+at+"ħŮ��" NOR;	
		else if(avg<5000000) 
			return RED "��"+at+"������" NOR;	
		else 
			return RED "��"+at+"Ůħ����" NOR;
	if ( ob->query("family/family_name") == "��ѩɽ" )
		if(avg<1000) 
			return HIW "�� С��Ů ��" NOR;
		else if(avg<10000) 
			return HIW "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return HIW "�� Ů  �� ��" NOR;
		else if(avg<500000) 
			return HIW "�� Ů  ħ ��" NOR;
		else if(avg<1000000) 
			return HIW "��"+at+"ħŮ��" NOR;	
		else if(avg<5000000) 
			return HIW "��"+at+"������" NOR;	
		else 
			return HIW "��"+at+"Ůħ����" NOR;
	if ( ob->query("family/family_name") == "��ԯ��Ĺ" )
		if(avg<1000)
			return WHT "�� С���� ��" NOR;
		else if(avg<10000)
			return WHT "�� ���꾫 ��" NOR;
		else if(avg<100000)
			return WHT "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return WHT "�� ħ  �� ��" NOR;
		else if(avg<1000000) 
			return WHT "��"+at+"���ɡ�" NOR;	
		else if(avg<5000000) 
			return WHT "��"+at+"������" NOR;	
		else 
			return WHT "��"+at+"������" NOR;
	if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )
		if(avg<1000) 
			return BLU "�� С��Ů ��" NOR;
		else if(avg<10000) 
			return BLU "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return BLU "�� Ů  �� ��" NOR;
		else if(avg<500000) 
			return BLU "�� Ů  ħ ��" NOR;
		else if(avg<1000000) 
			return BLU "��"+at+"ħŮ��" NOR;	
		else if(avg<5000000) 
			return BLU "��"+at+"������" NOR;	
		else 
			return BLU "��"+at+"Ůħ����" NOR;
	break;
case "bonze":
	if(dx<1000)
		return HIY "�� С��� ��" NOR;
	else if(dx<10000) 
		return HIY "�� ��  �� ��" NOR;	
	else if(dx<100000) 
		return HIY "�� ʦ  ̫ ��" NOR;	
	else if(dx<500000) 
		return HIY "�� ʥ  �� ��" NOR;
	else if(dx<1000000) 
		return HIY "��"+at+"���᡿" NOR;	
	else if(dx<5000000) 
		return HIY "��"+at+"������" NOR;	
	else 
		return HIY "��"+at+"��" NOR;
	break;
case "taoist":		           
	if(dx<1000) 
		return CYN "�� Ů��ͯ ��" NOR;
	else if(dx<10000) 
		return CYN "�� С���� ��" NOR;	
	else if(dx<100000) 
		return CYN "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return CYN "�� ��  Ů ��" NOR;
	else if(dx<1000000) 
		return CYN "��"+at+"��Ů��" NOR;	
	else if(dx<5000000)
		return CYN "��"+at+"ʥĸ��" NOR;
	else 
		return CYN "��"+at+"���" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "�� С���� ��" NOR;
	else if(avg<10000) 
		return HIC "�� ��  Ů ��" NOR;	
	else if(avg<100000) 
		return HIC "�� ĸҹ�� ��" NOR;	
	else if(avg<500000) 
		return HIC "�� С��Ů ��" NOR;
	else if(avg<1000000) 
		return HIC "��"+at+"��Ů��" NOR;	
	else if(avg<5000000) 
		return HIC "��"+at+"������" NOR;	
	else 
		return HIC "��"+at+"ʥ����" NOR;
	break;
case "scholar":
	if( (string)at=="δ��" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIG "�� Ůѧͯ ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIG "�� ��  Ů ��" NOR;
		else 
			return HIG "�� Ůѧʿ ��" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIG "�� Ůѧͯ ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIG "��"+at+"��š�" NOR;
		else 
			return HIG "��"+at+"ѧʿ��" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "�� Ů  �� ��" NOR;
	else if(exp<10000) 
		return HIR "�� ŮУξ ��" NOR;	
	else if(exp<100000) 
		return HIR "�� Ů�ν� ��" NOR;	
	else if(exp<500000) 
		return HIR "������Ӣ�ۡ�" NOR;
	else if(exp<1000000) 
		return HIR "��"+at+"Ů�ᶽ��" NOR;	
	else if(exp<5000000) 
		return HIR "��"+at+"��Ԫ˧��" NOR;	
	else 
		return HIR "��"+at+"��������" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "������С��" NOR;
	else if(avg<10000) 
		return HIB "���Ի�Ů��" NOR;	
	else if(avg<100000) 
		return HIB "����ڤŮʹ��" NOR;
	else if(avg<500000) 
		return HIB "�� ��ɲŮ ��" NOR;
	else if(avg<1000000)
		return HIB "��"+at+"���ޡ�" NOR;	
	else if(avg<5000000)
		return HIB "��"+at+"Ů����" NOR;	
	else 
		return HIB "��"+at+"������" NOR;
	break;	
case "phoenix":	//�����
	if(exp<1000) 
		return HIR "�� Ůսʿ ��" NOR;
	else if(exp<10000) 
		return HIR "�� ��սʿ ��" NOR;	
	else if(exp<100000) 
		return HIR "�� Ů��ʿ ��" NOR;
	else if(exp<500000) 
		return HIR "�� ����ʿ ��" NOR;
	else if(exp<1000000) 
		return HIR "��"+at+"�ｫ��" NOR;	
	else if(exp<5000000) 
		return HIR "��"+at+"ս��" NOR;
	else 
		return HIR "��"+at+"Ů��" NOR;
	break;
case "dancer":
	return MAG "�� ��  �� ��" NOR;	
	break;
default:
	if ( ob->query("family/family_name") == "�Ϻ�����ɽ" )
		if(dx<1000)
			return HIY "�� ��  Ů ��" NOR;
		else if(dx<10000) 
			return HIY "�� Ů̴Խ ��" NOR;	
		else if(dx<100000) 
			return HIY "�� ������ ��" NOR;	
		else if(dx<500000) 
			return HIY "�� ��һ��� ��" NOR;
		else if(dx<1000000) 
			return HIY "��"+at+"������" NOR;	
		else if(dx<5000000) 
			return HIY "��"+at+"����" NOR;	
		else 
			return HIY "��"+at+"����" NOR;
	if ( ob->query("xmark/ѧԱ") )
		if(exp<1000)
			return HIR "�� Ů���� ��" NOR;
		else if(exp<10000) 
			return HIR "�� Ů���� ��" NOR;	
		else
			return HIR "�� �������� ��" NOR;
	if( ob->query("guild/master") )
		if( ob->query("added_title")!="����" )
			return REDMAG"�� "+ob->query("added_title")+" ��"NOR;
		else
			return REDMAG"�� ŮӢ�� ��"NOR;
	if( ob->query("guild/child") )
	{
		if(avg<1000)
			return REDMAG "�� Ů���� ��" NOR;
		else if(avg<10000) 
			return REDMAG "�� ��  Ů ��" NOR;	
		else if(avg<100000) 
			return REDMAG "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return REDMAG "�� Ů��ʿ ��" NOR;
		else if(avg<1000000) 
			return REDMAG "��"+at+"�ҽ���" NOR;	
		else if(avg<5000000) 
			return REDMAG "��"+at+"��ʿ��" NOR;
		else 
			return REDMAG "��"+at+"������" NOR;
	}		
	if (age <= 16)
		return MAG"�� ��  Ů ��"NOR;
	else if (age<=30)
		return MAG"�� ��  �� ��"NOR;
	else if (age<=60)
		return MAG"�����긾�ˡ�"NOR;
	else return MAG"�� ��  �� ��"NOR; 

//------------------end rank for girls--------------------
				}
			}
//begin ���ԣ�
		case "����":
		case "����":
			switch(wizhood(ob)) 
			{
				case "(admin)":      return HIW "�� ��  �� ��" NOR;
				case "(arch)":       return HIR "�� ��  �� ��" NOR;
				case "(wizard)":     return HIY "�� ��  �� ��" NOR;
				case "(apprentice)": return HIG "�� ɢ  �� ��" NOR;
				case "(immortal)":   return HIM "�� ħ��ʦ ��" NOR;
				case "(elder)":      return HIB "�� С���� ��" NOR;
				default:
					switch(ob->query("class")) 
					{
//------------------rank for men--------------------
case "xian":	            	
	if(dx<1000)
		return YEL "�� ��  ͯ ��" NOR;
	else if(dx<10000) 
		return YEL "�� ɢ  �� ��" NOR;
	else if(dx<100000) 
		return YEL "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return YEL "�� ��  �� ��" NOR;
	else if(dx<1000000) 
		return YEL "��"+at+"���ɡ�" NOR;	
	else if(dx<5000000) 
		return YEL "��"+at+"�����" NOR;
	else 
		return YEL "��"+at+"����" NOR;
	break;
case "wusheng":		           
	if(dx<1000) 
		return WHT "�� ��  ʿ ��" NOR;
	if(dx<10000) 
		return WHT "�� ����ɲ ��" NOR;
	else if(dx<100000) 
		return WHT "�� ���޺� ��" NOR;	
	else if(dx<500000) 
		return WHT "���������ߡ�" NOR;
	else if(dx<1000000) 
		return WHT "��"+at+"���ߡ�" NOR;	
	else if(dx<5000000) 
		return WHT "��"+at+"��ۡ�" NOR;	
	else 
		return WHT "��"+at+"��ۡ�" NOR;
	break;
case "swordsman":
	if(avg<1000) 
		return HIG "�� ��  ͯ ��" NOR;
	else if(avg<10000) 
		return HIG "�� ��  ʿ ��" NOR;
	else if(avg<100000) 
		return HIG "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return HIG "�� ��  �� ��" NOR;
	else if(avg<1000000)
		return HIG "��"+at+"������" NOR;
	else if(avg<5000000)
		return HIG "��"+at+"���ɡ�" NOR;
	else 
		return HIG "��"+at+"��ʥ��" NOR;
	break;
case "hero":
	if(avg<1000) 
		return GRN "�� ��  �� ��" NOR;
	else if(avg<10000) 
		return GRN "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return GRN "�� ��  ʿ ��" NOR;
	else if(avg<500000) 
		return GRN "�� ��  �� ��" NOR;
	else if(avg<1000000) 
		return GRN "��"+at+"���͡�" NOR;	
	else if(avg<5000000) 
		return GRN "��"+at+"������" NOR;	
	else
		return GRN "��"+at+"��ʥ��" NOR;
	break;
case "yaomo":
	if ( ob->query("family/family_name") == "���ƶ�" )
		if(avg<1000) 
			return RED "�� С  �� ��" NOR;
		else if(avg<10000) 
			return RED "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return RED "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return RED "�� ��  �� ��" NOR;
		else if(avg<1000000) 
			return RED "�� "+at+"�� ��" NOR;	
		else if(avg<5000000) 
			return RED "��"+at+"��ħ��" NOR;
		else 
			return RED "��"+at+"ħ����" NOR;
	if ( ob->query("family/family_name") == "��ѩɽ" )
		if(avg<1000) 
			return HIW "�� С  �� ��" NOR;
		else if(avg<10000) 
			return HIW "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return HIW "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return HIW "�� ��  �� ��" NOR;
		else if(avg<1000000) 
			return HIW "�� "+at+"�� ��" NOR;	
		else if(avg<5000000) 
			return HIW "��"+at+"��ħ��" NOR;
		else 
			return HIW "��"+at+"ħ����" NOR;
	if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )
		if(avg<1000) 
			return BLU "�� С  �� ��" NOR;
		else if(avg<10000) 
			return BLU "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return BLU "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return BLU "�� ��  �� ��" NOR;
		else if(avg<1000000) 
			return BLU "�� "+at+"�� ��" NOR;	
		else if(avg<5000000) 
			return BLU "��"+at+"��ħ��" NOR;
		else 
			return BLU "��"+at+"ħ����" NOR;
	break;
case "bonze":		
	if(dx<1000) 
		return HIY "�� С���� ��" NOR;
	else if(dx<10000) 
		return HIY "�� ����ɮ ��" NOR;	
	else if(dx<100000) 
		return HIY "�� ʥ  ɮ ��" NOR;
	else if(dx<500000) 
		return HIY "�������޺���" NOR;
	else if(dx<1000000) 
		return HIY "��"+at+"���ߡ�" NOR;	
	else if(dx<5000000) 
		return HIY "��"+at+"������" NOR;
	else 
		return HIY "��"+at+"��" NOR;
	break;
case "taoist":		            
	if(dx<1000) 
		return CYN "�� С��ʿ ��" NOR;
	else if(dx<10000) 
		return CYN "�� ��  ʿ ��" NOR;	
	else if(dx<100000) 
		return CYN "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return CYN "�� ��  ʦ ��" NOR;
	else if(dx<1000000)
		return CYN "��"+at+"���ˡ�" NOR;	
	else if(dx<5000000) 
		return CYN "��"+at+"������" NOR;
	else 
		return CYN "��"+at+"����" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "�� Ϻ  �� ��" NOR;
	else if(avg<10000) 
		return HIC "�� з  �� ��" NOR;	
	else if(avg<100000) 
		return HIC "��Ѳ��ҹ�桿" NOR;
	else if(avg<500000) 
		return HIC "�� ��ة�� ��" NOR;
	else if(avg<1000000)
		return HIC "��"+at+"������" NOR;	
	else if(avg<5000000)
		return HIC "��"+at+"������" NOR;
	else 
		return HIC "��"+at+"������" NOR;
	break;
case "scholar":
	if( (string)at=="����" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIR "�� ͯ  �� ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIR "�� ��  �� ��" NOR;
		else 
			return HIR "�� ��ѧʿ ��" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIR "�� ͯ  �� ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIR "��"+at+"��š�" NOR;
		else 
			return HIR "��"+at+"ѧʿ��" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "�� С  �� ��" NOR;
	else if(exp<10000) 
		return HIR "�� С  У ��" NOR;	
	else if(exp<100000) 
		return HIR "�� ��  �� ��" NOR;
	else if(exp<500000) 
		return HIR "�� ��  �� ��" NOR;
	else if(exp<1000000) 
		return HIR "��"+at+"�ᶽ��" NOR;	
	else if(exp<5000000) 
		return HIR "��"+at+"��Ԫ˧��" NOR;
	else 
		return HIR "��"+at+"��������" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "������С��" NOR;
	else if(avg<10000) 
		return HIB "������ʹ�ߡ�" NOR;	
	else if(avg<100000) 
		return HIB "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return HIB "���ظ��й١�" NOR;
	else if(avg<1000000) 
		return HIB "��"+at+"������" NOR;	
	else if(avg<5000000) 
		return HIB "��"+at+"ڤ����" NOR;
	else 
		return HIB "��"+at+"������" NOR;
	break;
case "phoenix":	//�����
	if(exp<1000)
		return HIR "�� ս  ʿ ��" NOR;
	else if(exp<10000) 
		return HIR "�� ��սʿ ��" NOR;	
	else if(exp<100000) 
		return HIR "�� ��  ʿ ��" NOR;
	else if(exp<500000) 
		return HIR "�� ����ʿ ��" NOR;
	else if(exp<1000000) 
		return HIR "��"+at+"������" NOR;	
	else if(exp<5000000) 
		return HIR "��"+at+"ս��" NOR;
	else 
		return HIR "��"+at+"��" NOR;
	break;
default:
	if ( ob->query("family/family_name") == "�Ϻ�����ɽ" )
		if(dx<1000)
			return HIY "�� ��  �� ��" NOR;
		else if(dx<10000) 
			return HIY "�� ̴  Խ ��" NOR;	
		else if(dx<100000) 
			return HIY "�� ������ ��" NOR;	
		else if(dx<500000) 
			return HIY "�� ��һ��� ��" NOR;
		else if(dx<1000000) 
			return HIY "��"+at+"������" NOR;	
		else if(dx<5000000) 
			return HIY "��"+at+"����" NOR;	
		else 
			return HIY "��"+at+"����" NOR;
	if ( ob->query("xmark/ѧԱ") )
		if(exp<1000)
			return HIR "�� ��  �� ��" NOR;
		else if(exp<10000) 
			return HIR "�� ��  �� ��" NOR;	
		else
			return HIR "�� �������� ��" NOR;
	if (ob->query("guild/master"))
		if( ob->query("added_title")!="����" )
			return REDMAG"�� "+ob->query("added_title")+" ��"NOR;
		else
			return REDMAG"�� Ӣ  �� ��"NOR;
	if( ob->query("guild/child") )
	{
		if(avg<1000)
			return REDMAG "�� ��  �� ��" NOR;
		else if(avg<10000) 
			return REDMAG "�� ��  �� ��" NOR;	
		else if(avg<100000) 
			return REDMAG "�� ��  �� ��" NOR;
		else if(avg<500000) 
			return REDMAG "�� ��  ʿ ��" NOR;
		else if(avg<1000000) 
			return REDMAG "��"+at+"�ҽ���" NOR;	
		else if(avg<5000000) 
			return REDMAG "��"+at+"��ʿ��" NOR;
		else 
			return REDMAG "��"+at+"������" NOR;
	}		
	if (age <= 16)
		return HIC"�� ��  �� ��"NOR;
	else if (age<=30)
		return HIC"�� ��  �� ��"NOR;
	else if (age<=60)
		return HIC"�� ׳  �� ��"NOR;
	else return HIC"�� �Ϲ��� ��"NOR; 

//------------------end rank for men--------------------
				}
			}
		default:
			if (age <= 16)
				return HIC"�� С̫�� ��"NOR;
			else if (age<=30)
				return HIC"�� ̫  �� ��"NOR;
			else if (age<=60)
				return HIC"�� ��  �� ��"NOR;
			else return HIC"��"+at+"������"NOR; 

	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 18 ) return "Сʦ̫";
	else return "ʦ̫";
	break;
case "taoist":
	if( age < 18 ) return "С�ɹ�";
	else return "�ɹ�";
	break;
case "xian":
	if( age < 18 ) return "С�ɹ�";
	else return "�ɹ�";
	break;
case "swordsman":
	if( age < 18 ) return "Ů����";
	else return "Ů��";
	break;
case "huli":
	if( age < 18 ) return "С�ɰ�";
	else return "����";
	break;
default:
	if( age < 18 ) return "С����";
	else if( age < 30 ) return "����";
	else if( age < 40 ) return "����";
	else return "����";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 18 ) return "С����";
	else if( age < 50 ) return "����";
	else return "������";
	break;
case "swordsman":
	if( age < 18 ) return "����";
	else if( age < 50 ) return "����";
	else return "������";
	break;
case "bonze":
	if( age < 18 ) return "Сʦ��";
	else if( age < 50 ) return "��ʦ";
	else return "����";
	break;
case "taoist":
	if( age < 18 ) return "С��ү";
	else if( age < 50 ) return "����";
	else return "����";
	break;
case "fighter":
	if( age < 18 ) return "С����";
	else if( age < 50 ) return "�󽫾�";
	else return "�Ͻ���";
	break;
case "scholar":
	if( age < 18 ) return "С�๫";
	else if( age < 50 ) return "�๫";
	else return "������";
	break;
case "swordsman":
	if( age < 18 ) return "С�ϵ�";
	else if( age < 50 ) return "׳ʿ";
	else return "��ǰ��";
	break;
default:
	if( age < 18 ) return "С�ֵ�";
	else if( age < 50 ) return "׳ʿ";
	else return "��ү��";
	break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "xian":
	if(age < 30) return "С����";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
case "swordsman":
	if(age < 30) return "С����";
	else if(age < 50) return "����";
	else return "����̫��";
	break;
case "huli":
	if(age < 30) return "С����";
	else if(age < 50) return "ɧ����";
	else return "�Ϻ���";
	break;
case "yaomo":
	if(age < 30) return "С��Ů";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
case "bonze":
	if(age < 30) return "С����";
	else if(age < 50) return "����";
	else return "������";
	break;
case "taoist":
	if(age < 30) return "С��Ů";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
default:
	if( age < 18 ) return "С��Ƥ";
	if( age < 25 ) return "С����";
	if( age < 40 ) return "������";
	else return "����̫��";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 50 ) return "������";
	else return "������";
	break;
case "swordsman":
	if( age < 18 ) return "С���˵�";
	else if( age < 50 ) return "����";
	else return "��ƥ��";
	break;
case "yaomo":
	if( age < 50 ) return "������";
	else return "������";
	break;
case "bonze":
	if( age < 50 ) return "��ͺ¿";
	else return "��ͺ¿";
	break;
case "taoist":
	if( age < 18 ) return "С��ë";
	if( age < 30 ) return "��ţ����";
	else return "����ë";
	break;
	break;
case "scholar":
	if( age < 18 ) return "С�����";
	else if( age < 50 ) return "�������";
	else return "��ͯ��";
	break;
default:
	if( age < 20 ) return "С���˵�";
	if( age < 30 ) return "ֱ����";
	if( age < 50 ) return "����";
	if( age < 80 ) return "��ƥ��";
	else return "�ϲ���";
	break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "ƶ��";
	else return "����";
	break;
case "taoist":
	return "ƶ��";
	break;
case "xian":
	if( age < 20 ) return "С�ɹ���";
	if( age > 50 ) return "����";
	else return "������";
	break;
default:
	if( age < 20 ) return "СŮ��";
	if( age > 50 ) return "����";
	else return "���";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 18 ) return "С��";
	if( age < 40 ) return "ƶɮ";
	else return "����";
	break;
case "taoist":
	if( age < 18 ) return "С��";
	if( age < 50 ) return "ƶ��";
	else return "�ϵ�";
	break;
case "scholar":
	if( age < 30 ) return "����";
	else return "����";
	break;
default:
	if( age < 50 ) return "����";
	else return "��ͷ��";
	break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "ƶ��";
	else return "����";
	break;
case "taoist":
	return "���ɹ�";
	break;
case "xian":
	return "���ɹ�";
	break;
default:
	if( age < 20 ) return "����";
	if( age < 30 ) return "������";
	else return "����";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "�������";
	else return "�Ϻ�����";
	break;
case "taoist":
	return "��ɽ��";
	return "�ϵ���";
	break;
case "scholar":
	if( age < 50 ) return "���๫";
	else return "�Ϸ�����";
	break;
default:
	if( age < 20 ) return "����ү��";
	if( age < 40 ) return "��ү��";
	else return "��үү��";
	break;
			}
	}
}


string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )       {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	
	if( !rgender )
		gender = ob->query("gender");					   
	else    gender = rgender;

	switch ( gender ) {
	case "Ů��" :
		if (a1 > a2)
			return "����";
		else
			return "����";
		break;
	case "����" :
		if (a1 > a2)
			return "�ܵ�";
		else
			return "���";
	default:
		return "����";
		break;
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	if( objectp(ob) ) {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) {

	case "Ů��" :
		if (a1 > a2)
			return "������";
		else
			return "С����";
		break;
	case "����" :
		if (a1 > a2)
			return "������";
		else
			return "С����";
	default:
		return "����";
		break;
	}
}
