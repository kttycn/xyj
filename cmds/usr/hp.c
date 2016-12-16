//Last modify by vikee.
//2000.12.15

#include <ansi.h>
inherit F_CLEAN_UP;

string get_name(string str);
string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        mapping my;
        int anger,dao,x,i;
        string str,sp_skill;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("ÄúÒª²ì¿´Ë­µÄ×´Ì¬£¿\n");
        } 
		else return notify_fail("Ö»ÓĞÎ×Ê¦²Å¿ÉÒÔ²ì¿´±ğÈËµÄ×´Ì¬¡£\n");

        my = ob->query_entire_dbase();

        printf(NOR CYN"©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIY"ÔÂ"HIR"¡¤"HIY"Ó°"HIR"¡¤"HIY"Ææ"HIR"¡¤"HIY"Ôµ"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·\n"NOR,);
        printf(NOR CYN"©§"NOR HIC" ¸öÈË×´Ì¬"NOR CYN" ĞÕ Ãû£º"NOR WHT"%-12s"NOR CYN"ĞÔ±ğ£º"NOR WHT"%-6s"NOR CYN"I D£º"NOR WHT"%-20s"NOR CYN"©§\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR CYN"©Ç©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©Ï\n"NOR);
        printf(NOR CYN"©§"NOR WHT"¡¼ »êÆÇ ¡½%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["gin"],my["eff_gin"]),my["gin"],my["eff_gin"],status_color(my["eff_gin"],my["max_gin"]),my["eff_gin"]*100/my["max_gin"]);
        printf(NOR WHT"  ¡¼ ÄÚÁ¦ ¡½%s%7-d/%7-d(+%4d)"NOR CYN"©§\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"©§"NOR WHT"¡¼ ÆøÑª ¡½%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR WHT"  ¡¼ ·¨Á¦ ¡½%s%7-d/%7-d(+%4d)"NOR CYN"©§\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        printf(NOR CYN"©§"NOR WHT"¡¼ ¾«Éñ ¡½%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR WHT"  ¡¼ ÎäÑ§ ¡½%s%18-d    "NOR CYN"©§\n"HIG,HIY,(int)ob->query("combat_exp"));        
        if((my["food"]*100/ob->max_food_capacity())>100) str=HIC+"ºÜ±¥";
        else if((my["food"]*100/ob->max_food_capacity())>90) str=HIG+"Õı³£";
        else if((my["food"]*100/ob->max_food_capacity())>60) str=HIY+"È±Ê³";        
		else if((my["food"]*100/ob->max_food_capacity())>30) str=CYN+"È±Ê³";
        else if((my["food"]*100/ob->max_food_capacity())>10) str=HIR+"È±Ê³";
        else str=RED+"¼¢¶ö";
        printf(NOR CYN"©§"NOR WHT"¡¼ Ê³Îï ¡½%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR WHT"  ¡¼ Ç±ÄÜ ¡½%s%14-d "NOR CYN"       ©§\n"NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"ºÜ±¥";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"Õı³£";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"È±Ë®";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"È±Ë®";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"È±Ë®";
        else str=RED+"¼¢¿Ê";
		printf(NOR CYN"©§"NOR WHT"¡¼ ÒûË® ¡½%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        printf(NOR WHT"  ¡¼ É±Æø ¡½%s%20-d "NOR CYN" ©§\n"HIG,HIR,(int)ob->query("bellicosity"));
        if (ob->query("xuewei"))
        	printf(NOR CYN"©§"NOR WHT"¡¼ Ñ§Î» ¡½%s%12-s            "NOR,HIC,get_name(ob->query("xuewei")));
        else
        	printf(NOR CYN"©§"NOR WHT"¡¼ Ñ§Î» ¡½                        "NOR);
		if (ob->query("degree"))
//			printf(NOR WHT"¡¼ ¹Ù°İ ¡½%s%-21s   "NOR+WHT"¡¼ ¾ü¶Ó ¡½%-8d"NOR CYN"              ©§\n"NOR,HIC,get_name(ob->query("degree")), ob->query("soilder"));
			printf(NOR WHT"¡¼ ¹Ù°İ ¡½%s%-22s"NOR CYN"©§\n"NOR, HIC, get_name(ob->query("degree")));
		else
			printf(NOR WHT"¡¼ ¹Ù°İ ¡½"NOR HIB"Î´ÈëÊËÍ¾"NOR CYN"              ©§\n");
		anger=ob->query("anger");
		printf(NOR CYN"©§"NOR WHT"¡¼ Å­Æø ¡½"NOR);
		if( !anger || anger<=0 )
			printf(GRN"¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ¡õ",NOR);
		else {
			if(anger>100) anger = 100;
			for( x=0;x<anger/10;x++)
				printf(HIR+FLA"¡ö"NOR);
			if(anger < 100)
				if( anger%10 == 0)
					for( i=0;i<(100-anger )/10;i++)
						printf(GRN"¡õ"NOR);
				else
					for( i=0;i<(100-anger)/10+1;i++)
						printf(GRN"¡õ"NOR);
		}
		sp_skill=ob->query_skill_mapped("spells");
		if(sp_skill)
			printf(WHT"    ¡¼·¨ÊõÊôĞÔ¡½%s"CYN"                ©§\n"NOR,"/adm/daemons/spelld"->query_shuxing_chinese(
			SKILL_D(sp_skill)->query_shuxing()));
		else printf(WHT"    ¡¼·¨ÊõÊôĞÔ¡½"CYN"Äã²¢Ã»ÓĞÑ§»áÈÎºÎ·¨Êõ©§\n"NOR);
		dao=(int)ob->query("daoxing");       
        printf(NOR CYN"©§"NOR WHT"¡¼ µÀĞĞ ¡½%s%52-s    "NOR CYN"©§\n"NOR,HIM,COMBAT_D->chinese_daoxing(dao));
        
        printf(NOR CYN"©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥"HIY"ÔÂ"HIR"¡¤"HIY"Ó°"HIR"¡¤"HIY"Ææ"HIR"¡¤"HIY"Ôµ"NOR CYN"©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿\n"NOR);

        printf("\n");   
        return 1;
}

string status_color(int current, int max)
{
        int percent;
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return CYN;
        if( percent >= 10 ) return HIR;
        return RED;
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
Ö¸Áî¸ñÊ½ : hp
           hp <¶ÔÏóÃû³Æ>                   (Î×Ê¦×¨ÓÃ)
 
Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾Äã(Äã)»òÖ¸¶¨¶ÔÏó(º¬¹ÖÎï)µÄ¾«, Æø, ÉñÊıÖµ¡£
 
see also : score
HELP
    );
    return 1;
}
 
