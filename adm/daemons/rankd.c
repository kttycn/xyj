// rankd.c

#include <ansi.h>

//descriptions...

//note, be careful with the size of this list, dx increases as n^3. 
string *dx_level_desc = ({
	BLU "新入道途" NOR, //in unit of year 
	BLU "闻道则喜" NOR, //1x2=2
	BLU "初领妙道" NOR, //8x2=16
	BLU "略通道行" NOR, //27x2=56
	HIB "渐入佳境" NOR, //64x2=128
	HIB "元神初具" NOR, //125x2=250
	HIB "道心稳固" NOR, //216x2=432
	HIB "一日千里" NOR, //343x2=686
	CYN "道高德隆" NOR, //512x2=1024
	CYN "脱胎换骨" NOR, //729x2=1458
	CYN "霞举飞升" NOR, //1000x2=2000
	CYN "道满根归" NOR, //1331x2=2662
	HIC "不堕轮回" NOR, //1728x2=3456
	HIC "已证大道" NOR, //2197x2=4394
	HIC "反璞归真" NOR, //2744x2=5688
	HIW "天人合一" NOR  //3375x2=6750
});

string *fali_level_desc = ({
	BLU "初具法力" NOR, //    
	BLU "略晓变化" NOR, //1x40=40
	BLU "降龙伏虎" NOR, //4x40=160
	HIB "腾云驾雾" NOR, //9x40=360   
	HIB "神出鬼没" NOR, //16x40=640
	HIB "预知祸福" NOR, //25x40=1000
	HIB "妙领天机" NOR, //36x40=1440    
	CYN "呼风唤雨" NOR, //49x40=1960
	CYN "负海担山" NOR, //64x40=2560    
	CYN "移星换斗" NOR, //81x40=3240
	CYN "包罗万象" NOR, //100x40=4000
	HIC "随心所欲" NOR, //121x40=4840    
	HIC "变换莫测" NOR, //144x40=5760
	HIW "法力无边" NOR  //169x40=6760
});

string *exp_level_desc = ({
/*	BLU "初学乍练" NOR,
	BLU "初窥门径" NOR,
	HIB "粗通皮毛" NOR,
	HIB "略知一二" NOR,
	YEL "半生不熟" NOR,
	YEL "马马虎虎" NOR,
	HIY "已有小成" NOR,
	HIY "渐入佳境" NOR,
	HIM "驾轻就熟" NOR,
	HIM "了然于胸" NOR,
	HIR "出类拔萃" NOR,
	HIR "心领神会" NOR,
	MAG "神乎其技" NOR,
	MAG "出神入化" NOR,
	CYN "豁然贯通" NOR,
	CYN "登峰造极" NOR,
	HIC "举世无双" NOR,
	HIC "一代宗师" NOR,
	HIC "震古铄今" NOR,
	HIW "深不可测" NOR
*/
	BLU "不堪一击" NOR,
	BLU "毫不足虑" NOR,
	HIB "不足挂齿" NOR,
	HIB "初学乍练" NOR,
	HIB "勉勉强强" NOR,
	YEL "初窥门径" NOR,
	YEL "初出茅庐" NOR,
	YEL "略知一二" NOR,
	HBYEL "普普通通" NOR,
	HBYEL "平平淡淡" NOR,
	HBYEL "平淡无奇" NOR,
	HBBLU "粗通皮毛" NOR,
	HBBLU "半生不熟" NOR,
	HBBLU "马马虎虎" NOR,
	BBLU "略有小成" NOR,
	BBLU "已有小成" NOR,
	BBLU "鹤立鸡群" NOR,
	BMAG "驾轻就熟" NOR,
	BMAG "青出于蓝" NOR,
	BMAG "融会贯通" NOR,
	HIY "心领神会" NOR,
	HIY "炉火纯青" NOR,
	HIY "了然于胸" NOR,
	HIM "略有大成" NOR,
	HIM "已有大成" NOR,
	HIM "豁然贯通" NOR,
	HIR "出类拔萃" NOR,
	HIR "无可匹敌" NOR,
	HIR "技冠群雄" NOR,
	BRED "神乎其技" NOR,
	BRED "出神入化" NOR,
	BRED "非同凡响" NOR,
	HBRED "傲视群雄" NOR,
	HBRED "登峰造极" NOR,
	HBRED "无与伦比" NOR,
	MAG "所向披靡" NOR,
	MAG "一代宗师" NOR,
	MAG "精深奥妙" NOR,
	CYN "神功盖世" NOR,
	CYN "举世无双" NOR,
	CYN "惊世骇俗" NOR,
	HIC "撼天动地" NOR,
	HIC "震古铄今" NOR,
	HIC "超凡入圣" NOR,
	WHT "威镇寰宇" NOR,
	WHT "空前绝后" NOR,
	WHT "天人合一" NOR,
	HIW "深藏不露" NOR,
	HIW "深不可测" NOR,
	HIW "返璞归真" NOR

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
	//note, this is to make 深不可测 requires 2700k combat_exp,
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
		line = HIB "不到一年" NOR;
		return line;
	}
	
	if(sixty > 0 )
	{
		if ( left != 0 )
		{ 
			line = HIW + chinese_number(sixty) + "甲子" + NOR + "又" +  HIR + chinese_number(left) + "年" + NOR;
		}
		else 
		{
			line = HIW + chinese_number(sixty) + "甲子"  + NOR;	
		}		
	}
	else 
		line = HIR + chinese_number(year)+"年" + NOR;

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
    
    if(sscanf(rank,"%s【%s】%s",s1,s2,s3)!=3) return rank;
    len=14-sizeof(s2);
    if(len<1) return rank;

    len1=len/2;
    len2=len-len1;
    if(len1) s2=repeat_string(" ",len1)+s2;
    if(len2) s2+=repeat_string(" ",len2);
    
    return s1+"【"+s2+"】"+s3;
}

string _query_rank(object ob)
{
	string at;
	int dx, exp, avg, age;

	if(strlen(ob->query("added_title"))<1) ob->set("added_title", "无名");
	//need this default, otherwise looks too ugly sometimes.

	at = ob->query("added_title");
	dx = (int)ob->query("daoxing");
	exp = (int)ob->query("combat_exp");
	avg = (dx + exp)/2;
	age = ob->query("age");

	if( ob->is_ghost() ) return HIB "【 黑暗幽灵 】" NOR;
	switch(ob->query("gender")) 
	{
		case "女性":
		case "雌性":
			switch(wizhood(ob)) {
				case "(admin)":	    return HIW "【 女  神 】" NOR;
				case "(arch)":		return HIR "【 仙  子 】" NOR;
				case "(wizard)":	return HIY "【 天  女 】" NOR;
				case "(apprentice)":	return HIG "【 大魔女 】" NOR;
				case "(immortal)":      return HIM "【 魔  女 】" NOR;
				case "(elder)":      	return HIB "【 小精灵 】" NOR;
				default:
					switch(ob->query("class")) 
					{
//------------------rank for girls--------------------
/*凤凰星(phoenix) - HIR  火云洞(yaomo) - RED  将军府(fighter) - HIR  盱眙山(xian) - GRN
蜀山剑派(swordsman) - HIG  五庄观(xian) - YEL  南海普陀山(bonze) - HIY  陷空山无底洞(yaomo) - BLU
阎罗地府(youling) - HIB  盘丝洞(xian) - MAG  月宫(moon) - HIM  方寸山三星洞(taoism) - CYN
东海龙宫(dragon) - HIC  武圣门(wusheng) - WHT  大雪山(yaomo) - HIW 
轩辕古墓(huli) - HIW
*/
case "xian":
	if ( ob->query("family/family_name") == "五庄观" )
		if(dx<1000) 
			return YEL "【 玉  女 】" NOR;
		else if(dx<10000) 
			return YEL "【 神  女 】" NOR;	
		else if(dx<100000) 
			return YEL "【 仙  子 】" NOR;
		else if(dx<500000) 
			return YEL "【 圣  女 】" NOR;
		else if(dx<1000000) 
			return YEL "【"+at+"神妃】" NOR;	
		else if(dx<5000000) 
			return YEL "【"+at+"圣母】" NOR;	
		else 
			return YEL "【"+at+"天后】" NOR;
	if ( ob->query("family/family_name") == "盘丝洞" )
		if(avg<1000) 
			return MAG "【 小仙女 】" NOR;
		else if(avg<10000) 
			return MAG "【 仙  女 】" NOR;	
		else if(avg<100000) 
			return MAG "【 仙  子 】" NOR;
		else if(avg<500000) 
			return MAG "【 圣  女 】" NOR;
		else if(avg<1000000) 
			return MAG "【"+at+"神女】" NOR;	
		else if(avg<5000000) 
			return MAG "【"+at+"大仙】" NOR;	
		else 
			return MAG "【"+at+"仙后】" NOR;
	if ( ob->query("family/family_name") == "月宫" )
		if(dx<1000) 
			return HIM "【 玉  女 】" NOR;
		else if(dx<10000) 
			return HIM "【 神  女 】" NOR;	
		else if(dx<100000) 
			return HIM "【 仙  子 】" NOR;
		else if(dx<500000) 
			return HIM "【 圣  女 】" NOR;
		else if(dx<1000000) 
			return HIM "【"+at+"神妃】" NOR;	
		else if(dx<5000000) 
			return HIM "【"+at+"圣母】" NOR;	
		else 
			return HIM "【"+at+"仙后】" NOR;
	break;
case "wusheng":		           
	if(dx<1000) 
		return WHT "【 女武士 】" NOR;
	else if(dx<10000) 
		return WHT "【 玉罗刹 】" NOR;	
	else if(dx<100000) 
		return WHT "【 女罗汉 】" NOR;	
	else if(dx<500000) 
		return WHT "【护法尊者】" NOR;
	else if(dx<1000000) 
		return WHT "【"+at+"女尊者】" NOR;	
	else if(dx<5000000) 
		return WHT "【"+at+"圣君】" NOR;	
	else 
		return WHT "【"+at+"大帝】" NOR;
	break;
case "swordsman":
	if(exp<1000) 
		return HIG "【 女剑童 】" NOR;
	else if(exp<10000) 
		return HIG "【 女剑士 】" NOR;	
	else if(exp<100000) 
		return HIG "【 女剑客 】" NOR;
	else if(exp<500000) 
		return HIG "【 女剑侠 】" NOR;
	else if(exp<1000000) 
		return HIG "【"+at+"女剑王】" NOR;	
	else if(exp<5000000) 
		return HIG "【"+at+"女剑仙】" NOR;	
	else
		return HIG "【"+at+"女剑圣】" NOR;
	break;
case "hero":
	if(exp<1000) 
		return GRN "【 女少侠 】" NOR;
	else if(exp<10000) 
		return GRN "【 女游侠 】" NOR;	
	else if(exp<100000) 
		return GRN "【 女侠士 】" NOR;
	else if(exp<500000) 
		return GRN "【 女侠客 】" NOR;
	else if(exp<1000000) 
		return GRN "【"+at+"女侠】" NOR;	
	else if(exp<5000000) 
		return GRN "【"+at+"大侠】" NOR;	
	else
		return GRN "【"+at+"女圣】" NOR;
	break;
case "yaomo":
	if ( ob->query("family/family_name") == "盘丝洞" )
		if(avg<1000) 
			return MAG "【 小妖女 】" NOR;
		else if(avg<10000) 
			return MAG "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return MAG "【 女  妖 】" NOR;
		else if(avg<500000) 
			return MAG "【 女  魔 】" NOR;
		else if(avg<1000000) 
			return MAG "【"+at+"魔女】" NOR;	
		else if(avg<5000000) 
			return MAG "【"+at+"公主】" NOR;	
		else 
			return MAG "【"+at+"女王】" NOR;
	if ( ob->query("family/family_name") == "火云洞" )
		if(avg<1000) 
			return RED "【 小妖女 】" NOR;
		else if(avg<10000) 
			return RED "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return RED "【 女  妖 】" NOR;
		else if(avg<500000) 
			return RED "【 女  魔 】" NOR;
		else if(avg<1000000) 
			return RED "【"+at+"魔女】" NOR;	
		else if(avg<5000000) 
			return RED "【"+at+"公主】" NOR;	
		else 
			return RED "【"+at+"女魔王】" NOR;
	if ( ob->query("family/family_name") == "大雪山" )
		if(avg<1000) 
			return HIW "【 小妖女 】" NOR;
		else if(avg<10000) 
			return HIW "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return HIW "【 女  妖 】" NOR;
		else if(avg<500000) 
			return HIW "【 女  魔 】" NOR;
		else if(avg<1000000) 
			return HIW "【"+at+"魔女】" NOR;	
		else if(avg<5000000) 
			return HIW "【"+at+"公主】" NOR;	
		else 
			return HIW "【"+at+"女魔王】" NOR;
	if ( ob->query("family/family_name") == "轩辕古墓" )
		if(avg<1000)
			return WHT "【 小狐狸 】" NOR;
		else if(avg<10000)
			return WHT "【 狐狸精 】" NOR;
		else if(avg<100000)
			return WHT "【 妖  狐 】" NOR;
		else if(avg<500000) 
			return WHT "【 魔  狐 】" NOR;
		else if(avg<1000000) 
			return WHT "【"+at+"狐仙】" NOR;	
		else if(avg<5000000) 
			return WHT "【"+at+"公主】" NOR;	
		else 
			return WHT "【"+at+"狐王】" NOR;
	if ( ob->query("family/family_name") == "陷空山无底洞" )
		if(avg<1000) 
			return BLU "【 小妖女 】" NOR;
		else if(avg<10000) 
			return BLU "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return BLU "【 女  妖 】" NOR;
		else if(avg<500000) 
			return BLU "【 女  魔 】" NOR;
		else if(avg<1000000) 
			return BLU "【"+at+"魔女】" NOR;	
		else if(avg<5000000) 
			return BLU "【"+at+"公主】" NOR;	
		else 
			return BLU "【"+at+"女魔王】" NOR;
	break;
case "bonze":
	if(dx<1000)
		return HIY "【 小尼姑 】" NOR;
	else if(dx<10000) 
		return HIY "【 尼  姑 】" NOR;	
	else if(dx<100000) 
		return HIY "【 师  太 】" NOR;	
	else if(dx<500000) 
		return HIY "【 圣  尼 】" NOR;
	else if(dx<1000000) 
		return HIY "【"+at+"神尼】" NOR;	
	else if(dx<5000000) 
		return HIY "【"+at+"菩萨】" NOR;	
	else 
		return HIY "【"+at+"佛】" NOR;
	break;
case "taoist":		           
	if(dx<1000) 
		return CYN "【 女道童 】" NOR;
	else if(dx<10000) 
		return CYN "【 小道姑 】" NOR;	
	else if(dx<100000) 
		return CYN "【 飞  天 】" NOR;
	else if(dx<500000) 
		return CYN "【 玄  女 】" NOR;
	else if(dx<1000000) 
		return CYN "【"+at+"玄女】" NOR;	
	else if(dx<5000000)
		return CYN "【"+at+"圣母】" NOR;
	else 
		return CYN "【"+at+"娘娘】" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "【 小宫娥 】" NOR;
	else if(avg<10000) 
		return HIC "【 宫  女 】" NOR;	
	else if(avg<100000) 
		return HIC "【 母夜叉 】" NOR;	
	else if(avg<500000) 
		return HIC "【 小龙女 】" NOR;
	else if(avg<1000000) 
		return HIC "【"+at+"龙女】" NOR;	
	else if(avg<5000000) 
		return HIC "【"+at+"公主】" NOR;	
	else 
		return HIC "【"+at+"圣主】" NOR;
	break;
case "scholar":
	if( (string)at=="未设" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIG "【 女学童 】" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIG "【 才  女 】" NOR;
		else 
			return HIG "【 女学士 】" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIG "【 女学童 】" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIG "【"+at+"秀才】" NOR;
		else 
			return HIG "【"+at+"学士】" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "【 女  兵 】" NOR;
	else if(exp<10000) 
		return HIR "【 女校尉 】" NOR;	
	else if(exp<100000) 
		return HIR "【 女参将 】" NOR;	
	else if(exp<500000) 
		return HIR "【巾帼英雄】" NOR;
	else if(exp<1000000) 
		return HIR "【"+at+"女提督】" NOR;	
	else if(exp<5000000) 
		return HIR "【"+at+"大元帅】" NOR;	
	else 
		return HIR "【"+at+"将军王】" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "【阴曹小鬼】" NOR;
	else if(avg<10000) 
		return HIB "【迷魂女鬼】" NOR;	
	else if(avg<100000) 
		return HIB "【幽冥女使】" NOR;
	else if(avg<500000) 
		return HIB "【 罗刹女 】" NOR;
	else if(avg<1000000)
		return HIB "【"+at+"修罗】" NOR;	
	else if(avg<5000000)
		return HIB "【"+at+"女王】" NOR;	
	else 
		return HIB "【"+at+"菩萨】" NOR;
	break;	
case "phoenix":	//凤凰星
	if(exp<1000) 
		return HIR "【 女战士 】" NOR;
	else if(exp<10000) 
		return HIR "【 凤战士 】" NOR;	
	else if(exp<100000) 
		return HIR "【 女骑士 】" NOR;
	else if(exp<500000) 
		return HIR "【 凤骑士 】" NOR;
	else if(exp<1000000) 
		return HIR "【"+at+"凤将】" NOR;	
	else if(exp<5000000) 
		return HIR "【"+at+"战神】" NOR;
	else 
		return HIR "【"+at+"女神】" NOR;
	break;
case "dancer":
	return MAG "【 舞  妓 】" NOR;	
	break;
default:
	if ( ob->query("family/family_name") == "南海普陀山" )
		if(dx<1000)
			return HIY "【 少  女 】" NOR;
		else if(dx<10000) 
			return HIY "【 女檀越 】" NOR;	
		else if(dx<100000) 
			return HIY "【 护寺人 】" NOR;	
		else if(dx<500000) 
			return HIY "【 佛家护法 】" NOR;
		else if(dx<1000000) 
			return HIY "【"+at+"护法】" NOR;	
		else if(dx<5000000) 
			return HIY "【"+at+"真身】" NOR;	
		else 
			return HIY "【"+at+"王】" NOR;
	if ( ob->query("xmark/学员") )
		if(exp<1000)
			return HIR "【 女进修 】" NOR;
		else if(exp<10000) 
			return HIR "【 女待招 】" NOR;	
		else
			return HIR "【 江湖废人 】" NOR;
	if( ob->query("guild/master") )
		if( ob->query("added_title")!="无名" )
			return REDMAG"【 "+ob->query("added_title")+" 】"NOR;
		else
			return REDMAG"【 女英雄 】"NOR;
	if( ob->query("guild/child") )
	{
		if(avg<1000)
			return REDMAG "【 女闲人 】" NOR;
		else if(avg<10000) 
			return REDMAG "【 侍  女 】" NOR;	
		else if(avg<100000) 
			return REDMAG "【 侍  姬 】" NOR;
		else if(avg<500000) 
			return REDMAG "【 女斗士 】" NOR;
		else if(avg<1000000) 
			return REDMAG "【"+at+"家将】" NOR;	
		else if(avg<5000000) 
			return REDMAG "【"+at+"骑士】" NOR;
		else 
			return REDMAG "【"+at+"领主】" NOR;
	}		
	if (age <= 16)
		return MAG"【 少  女 】"NOR;
	else if (age<=30)
		return MAG"【 少  妇 】"NOR;
	else if (age<=60)
		return MAG"【中年妇人】"NOR;
	else return MAG"【 婆  婆 】"NOR; 

//------------------end rank for girls--------------------
				}
			}
//begin 男性：
		case "男性":
		case "雄性":
			switch(wizhood(ob)) 
			{
				case "(admin)":      return HIW "【 天  神 】" NOR;
				case "(arch)":       return HIR "【 龙  神 】" NOR;
				case "(wizard)":     return HIY "【 仙  人 】" NOR;
				case "(apprentice)": return HIG "【 散  仙 】" NOR;
				case "(immortal)":   return HIM "【 魔法师 】" NOR;
				case "(elder)":      return HIB "【 小精灵 】" NOR;
				default:
					switch(ob->query("class")) 
					{
//------------------rank for men--------------------
case "xian":	            	
	if(dx<1000)
		return YEL "【 仙  童 】" NOR;
	else if(dx<10000) 
		return YEL "【 散  仙 】" NOR;
	else if(dx<100000) 
		return YEL "【 地  仙 】" NOR;
	else if(dx<500000) 
		return YEL "【 大  仙 】" NOR;
	else if(dx<1000000) 
		return YEL "【"+at+"大仙】" NOR;	
	else if(dx<5000000) 
		return YEL "【"+at+"真君】" NOR;
	else 
		return YEL "【"+at+"天尊】" NOR;
	break;
case "wusheng":		           
	if(dx<1000) 
		return WHT "【 武  士 】" NOR;
	if(dx<10000) 
		return WHT "【 大罗刹 】" NOR;
	else if(dx<100000) 
		return WHT "【 大罗汉 】" NOR;	
	else if(dx<500000) 
		return WHT "【护法尊者】" NOR;
	else if(dx<1000000) 
		return WHT "【"+at+"尊者】" NOR;	
	else if(dx<5000000) 
		return WHT "【"+at+"武帝】" NOR;	
	else 
		return WHT "【"+at+"大帝】" NOR;
	break;
case "swordsman":
	if(avg<1000) 
		return HIG "【 剑  童 】" NOR;
	else if(avg<10000) 
		return HIG "【 剑  士 】" NOR;
	else if(avg<100000) 
		return HIG "【 剑  客 】" NOR;
	else if(avg<500000) 
		return HIG "【 剑  侠 】" NOR;
	else if(avg<1000000)
		return HIG "【"+at+"剑王】" NOR;
	else if(avg<5000000)
		return HIG "【"+at+"剑仙】" NOR;
	else 
		return HIG "【"+at+"剑圣】" NOR;
	break;
case "hero":
	if(avg<1000) 
		return GRN "【 少  侠 】" NOR;
	else if(avg<10000) 
		return GRN "【 游  侠 】" NOR;	
	else if(avg<100000) 
		return GRN "【 侠  士 】" NOR;
	else if(avg<500000) 
		return GRN "【 侠  客 】" NOR;
	else if(avg<1000000) 
		return GRN "【"+at+"侠客】" NOR;	
	else if(avg<5000000) 
		return GRN "【"+at+"大侠】" NOR;	
	else
		return GRN "【"+at+"侠圣】" NOR;
	break;
case "yaomo":
	if ( ob->query("family/family_name") == "火云洞" )
		if(avg<1000) 
			return RED "【 小  妖 】" NOR;
		else if(avg<10000) 
			return RED "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return RED "【 妖  怪 】" NOR;
		else if(avg<500000) 
			return RED "【 妖  仙 】" NOR;
		else if(avg<1000000) 
			return RED "【 "+at+"怪 】" NOR;	
		else if(avg<5000000) 
			return RED "【"+at+"老魔】" NOR;
		else 
			return RED "【"+at+"魔王】" NOR;
	if ( ob->query("family/family_name") == "大雪山" )
		if(avg<1000) 
			return HIW "【 小  妖 】" NOR;
		else if(avg<10000) 
			return HIW "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return HIW "【 妖  怪 】" NOR;
		else if(avg<500000) 
			return HIW "【 妖  仙 】" NOR;
		else if(avg<1000000) 
			return HIW "【 "+at+"怪 】" NOR;	
		else if(avg<5000000) 
			return HIW "【"+at+"老魔】" NOR;
		else 
			return HIW "【"+at+"魔王】" NOR;
	if ( ob->query("family/family_name") == "陷空山无底洞" )
		if(avg<1000) 
			return BLU "【 小  妖 】" NOR;
		else if(avg<10000) 
			return BLU "【 妖  精 】" NOR;	
		else if(avg<100000) 
			return BLU "【 妖  怪 】" NOR;
		else if(avg<500000) 
			return BLU "【 妖  仙 】" NOR;
		else if(avg<1000000) 
			return BLU "【 "+at+"怪 】" NOR;	
		else if(avg<5000000) 
			return BLU "【"+at+"老魔】" NOR;
		else 
			return BLU "【"+at+"魔王】" NOR;
	break;
case "bonze":		
	if(dx<1000) 
		return HIY "【 小和尚 】" NOR;
	else if(dx<10000) 
		return HIY "【 比丘僧 】" NOR;	
	else if(dx<100000) 
		return HIY "【 圣  僧 】" NOR;
	else if(dx<500000) 
		return HIY "【金身罗汉】" NOR;
	else if(dx<1000000) 
		return HIY "【"+at+"尊者】" NOR;	
	else if(dx<5000000) 
		return HIY "【"+at+"菩萨】" NOR;
	else 
		return HIY "【"+at+"佛】" NOR;
	break;
case "taoist":		            
	if(dx<1000) 
		return CYN "【 小道士 】" NOR;
	else if(dx<10000) 
		return CYN "【 道  士 】" NOR;	
	else if(dx<100000) 
		return CYN "【 道  长 】" NOR;
	else if(dx<500000) 
		return CYN "【 天  师 】" NOR;
	else if(dx<1000000)
		return CYN "【"+at+"真人】" NOR;	
	else if(dx<5000000) 
		return CYN "【"+at+"道君】" NOR;
	else 
		return CYN "【"+at+"天尊】" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "【 虾  兵 】" NOR;
	else if(avg<10000) 
		return HIC "【 蟹  将 】" NOR;	
	else if(avg<100000) 
		return HIC "【巡海夜叉】" NOR;
	else if(avg<500000) 
		return HIC "【 龟丞相 】" NOR;
	else if(avg<1000000)
		return HIC "【"+at+"天龙】" NOR;	
	else if(avg<5000000)
		return HIC "【"+at+"龙王】" NOR;
	else 
		return HIC "【"+at+"神主】" NOR;
	break;
case "scholar":
	if( (string)at=="无名" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIR "【 童  生 】" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIR "【 秀  才 】" NOR;
		else 
			return HIR "【 大学士 】" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return HIR "【 童  生 】" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return HIR "【"+at+"秀才】" NOR;
		else 
			return HIR "【"+at+"学士】" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "【 小  兵 】" NOR;
	else if(exp<10000) 
		return HIR "【 小  校 】" NOR;	
	else if(exp<100000) 
		return HIR "【 参  将 】" NOR;
	else if(exp<500000) 
		return HIR "【 将  军 】" NOR;
	else if(exp<1000000) 
		return HIR "【"+at+"提督】" NOR;	
	else if(exp<5000000) 
		return HIR "【"+at+"大元帅】" NOR;
	else 
		return HIR "【"+at+"将军王】" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "【阴曹小鬼】" NOR;
	else if(avg<10000) 
		return HIB "【勾魂使者】" NOR;	
	else if(avg<100000) 
		return HIB "【 无  常 】" NOR;
	else if(avg<500000) 
		return HIB "【地府判官】" NOR;
	else if(avg<1000000) 
		return HIB "【"+at+"鬼王】" NOR;	
	else if(avg<5000000) 
		return HIB "【"+at+"冥王】" NOR;
	else 
		return HIB "【"+at+"菩萨】" NOR;
	break;
case "phoenix":	//凤凰星
	if(exp<1000)
		return HIR "【 战  士 】" NOR;
	else if(exp<10000) 
		return HIR "【 龙战士 】" NOR;	
	else if(exp<100000) 
		return HIR "【 骑  士 】" NOR;
	else if(exp<500000) 
		return HIR "【 龙骑士 】" NOR;
	else if(exp<1000000) 
		return HIR "【"+at+"龙将】" NOR;	
	else if(exp<5000000) 
		return HIR "【"+at+"战神】" NOR;
	else 
		return HIR "【"+at+"神】" NOR;
	break;
default:
	if ( ob->query("family/family_name") == "南海普陀山" )
		if(dx<1000)
			return HIY "【 少  年 】" NOR;
		else if(dx<10000) 
			return HIY "【 檀  越 】" NOR;	
		else if(dx<100000) 
			return HIY "【 护寺人 】" NOR;	
		else if(dx<500000) 
			return HIY "【 佛家护法 】" NOR;
		else if(dx<1000000) 
			return HIY "【"+at+"护法】" NOR;	
		else if(dx<5000000) 
			return HIY "【"+at+"真身】" NOR;	
		else 
			return HIY "【"+at+"王】" NOR;
	if ( ob->query("xmark/学员") )
		if(exp<1000)
			return HIR "【 进  修 】" NOR;
		else if(exp<10000) 
			return HIR "【 待  招 】" NOR;	
		else
			return HIR "【 江湖废人 】" NOR;
	if (ob->query("guild/master"))
		if( ob->query("added_title")!="无名" )
			return REDMAG"【 "+ob->query("added_title")+" 】"NOR;
		else
			return REDMAG"【 英  雄 】"NOR;
	if( ob->query("guild/child") )
	{
		if(avg<1000)
			return REDMAG "【 闲  客 】" NOR;
		else if(avg<10000) 
			return REDMAG "【 伴  读 】" NOR;	
		else if(avg<100000) 
			return REDMAG "【 侍  卫 】" NOR;
		else if(avg<500000) 
			return REDMAG "【 斗  士 】" NOR;
		else if(avg<1000000) 
			return REDMAG "【"+at+"家将】" NOR;	
		else if(avg<5000000) 
			return REDMAG "【"+at+"骑士】" NOR;
		else 
			return REDMAG "【"+at+"领主】" NOR;
	}		
	if (age <= 16)
		return HIC"【 少  年 】"NOR;
	else if (age<=30)
		return HIC"【 青  年 】"NOR;
	else if (age<=60)
		return HIC"【 壮  汉 】"NOR;
	else return HIC"【 老公公 】"NOR; 

//------------------end rank for men--------------------
				}
			}
		default:
			if (age <= 16)
				return HIC"【 小太监 】"NOR;
			else if (age<=30)
				return HIC"【 太  监 】"NOR;
			else if (age<=60)
				return HIC"【 公  公 】"NOR;
			else return HIC"【"+at+"公公】"NOR; 

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
		case "女性":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 18 ) return "小师太";
	else return "师太";
	break;
case "taoist":
	if( age < 18 ) return "小仙姑";
	else return "仙姑";
	break;
case "xian":
	if( age < 18 ) return "小仙姑";
	else return "仙姑";
	break;
case "swordsman":
	if( age < 18 ) return "女少侠";
	else return "女侠";
	break;
case "huli":
	if( age < 18 ) return "小可爱";
	else return "狐仙";
	break;
default:
	if( age < 18 ) return "小姑娘";
	else if( age < 30 ) return "姑娘";
	else if( age < 40 ) return "大婶";
	else return "婆婆";
	break;
			}
		case "男性":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 18 ) return "小神仙";
	else if( age < 50 ) return "仙兄";
	else return "老神仙";
	break;
case "swordsman":
	if( age < 18 ) return "少侠";
	else if( age < 50 ) return "大侠";
	else return "老侠客";
	break;
case "bonze":
	if( age < 18 ) return "小师父";
	else if( age < 50 ) return "大师";
	else return "长老";
	break;
case "taoist":
	if( age < 18 ) return "小道爷";
	else if( age < 50 ) return "道兄";
	else return "道长";
	break;
case "fighter":
	if( age < 18 ) return "小将军";
	else if( age < 50 ) return "大将军";
	else return "老将军";
	break;
case "scholar":
	if( age < 18 ) return "小相公";
	else if( age < 50 ) return "相公";
	else return "老先生";
	break;
case "swordsman":
	if( age < 18 ) return "小老弟";
	else if( age < 50 ) return "壮士";
	else return "老前辈";
	break;
default:
	if( age < 18 ) return "小兄弟";
	else if( age < 50 ) return "壮士";
	else return "老爷子";
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
		case "女性":
			switch(ob->query("class")) 
			{
case "xian":
	if(age < 30) return "小妖精";
	else if(age < 50) return "妖女";
	else return "老妖婆";
	break;
case "swordsman":
	if(age < 30) return "小贱人";
	else if(age < 50) return "贱人";
	else return "死老太婆";
	break;
case "huli":
	if(age < 30) return "小妖精";
	else if(age < 50) return "骚狐狸";
	else return "老狐子";
	break;
case "yaomo":
	if(age < 30) return "小妖女";
	else if(age < 50) return "妖女";
	else return "老妖婆";
	break;
case "bonze":
	if(age < 30) return "小贼尼";
	else if(age < 50) return "贼尼";
	else return "老贼尼";
	break;
case "taoist":
	if(age < 30) return "小妖女";
	else if(age < 50) return "妖女";
	else return "老妖婆";
	break;
default:
	if( age < 18 ) return "小娘皮";
	if( age < 25 ) return "小贱人";
	if( age < 40 ) return "贼婆娘";
	else return "死老太婆";
	break;
			}
		case "男性":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 50 ) return "死妖怪";
	else return "老妖怪";
	break;
case "swordsman":
	if( age < 18 ) return "小王八蛋";
	else if( age < 50 ) return "臭贼";
	else return "老匹夫";
	break;
case "yaomo":
	if( age < 50 ) return "死妖怪";
	else return "老妖怪";
	break;
case "bonze":
	if( age < 50 ) return "死秃驴";
	else return "老秃驴";
	break;
case "taoist":
	if( age < 18 ) return "小杂毛";
	if( age < 30 ) return "死牛鼻子";
	else return "老杂毛";
	break;
	break;
case "scholar":
	if( age < 18 ) return "小书呆子";
	else if( age < 50 ) return "臭书呆子";
	else return "老童生";
	break;
default:
	if( age < 20 ) return "小王八蛋";
	if( age < 30 ) return "直娘贼";
	if( age < 50 ) return "臭贼";
	if( age < 80 ) return "老匹夫";
	else return "老不死";
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
		case "女性":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "贫尼";
	else return "老尼";
	break;
case "taoist":
	return "贫道";
	break;
case "xian":
	if( age < 20 ) return "小仙姑我";
	if( age > 50 ) return "婆婆";
	else return "仙子我";
	break;
default:
	if( age < 20 ) return "小女子";
	if( age > 50 ) return "老身";
	else return "妾身";
	break;
			}
		case "男性":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 18 ) return "小衲";
	if( age < 40 ) return "贫僧";
	else return "老纳";
	break;
case "taoist":
	if( age < 18 ) return "小道";
	if( age < 50 ) return "贫道";
	else return "老道";
	break;
case "scholar":
	if( age < 30 ) return "晚生";
	else return "不才";
	break;
default:
	if( age < 50 ) return "在下";
	else return "老头子";
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
		case "女性":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "贫尼";
	else return "老尼";
	break;
case "taoist":
	return "本仙姑";
	break;
case "xian":
	return "本仙姑";
	break;
default:
	if( age < 20 ) return "姑娘";
	if( age < 30 ) return "姑奶奶";
	else return "老娘";
	break;
			}
		case "男性":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "大和尚我";
	else return "老和尚我";
	break;
case "taoist":
	return "本山人";
	return "老道我";
	break;
case "scholar":
	if( age < 50 ) return "本相公";
	else return "老夫子我";
	break;
default:
	if( age < 20 ) return "本少爷我";
	if( age < 40 ) return "大爷我";
	else return "你爷爷我";
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
	case "女性" :
		if (a1 > a2)
			return "妹妹";
		else
			return "秭秭";
		break;
	case "男性" :
		if (a1 > a2)
			return "弟弟";
		else
			return "哥哥";
	default:
		return "公公";
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

	case "女性" :
		if (a1 > a2)
			return "秭秭我";
		else
			return "小妹我";
		break;
	case "男性" :
		if (a1 > a2)
			return "愚兄我";
		else
			return "小弟我";
	default:
		return "公公";
		break;
	}
}
