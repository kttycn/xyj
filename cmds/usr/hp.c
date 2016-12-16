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
        if (!ob) return notify_fail("您要察看谁的状态？\n");
        } 
		else return notify_fail("只有巫师才可以察看别人的状态。\n");

        my = ob->query_entire_dbase();

        printf(NOR CYN"┏━━━━━━━━━━━━━"HIY"月"HIR"·"HIY"影"HIR"·"HIY"奇"HIR"·"HIY"缘"NOR CYN"━━━━━━━━━━━━━┓\n"NOR,);
        printf(NOR CYN"┃"NOR HIC" 个人状态"NOR CYN" 姓 名："NOR WHT"%-12s"NOR CYN"性别："NOR WHT"%-6s"NOR CYN"I D："NOR WHT"%-20s"NOR CYN"┃\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR CYN"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n"NOR);
        printf(NOR CYN"┃"NOR WHT"〖 魂魄 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["gin"],my["eff_gin"]),my["gin"],my["eff_gin"],status_color(my["eff_gin"],my["max_gin"]),my["eff_gin"]*100/my["max_gin"]);
        printf(NOR WHT"  〖 内力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"┃"NOR WHT"〖 气血 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR WHT"  〖 法力 〗%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        printf(NOR CYN"┃"NOR WHT"〖 精神 〗%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR WHT"  〖 武学 〗%s%18-d    "NOR CYN"┃\n"HIG,HIY,(int)ob->query("combat_exp"));        
        if((my["food"]*100/ob->max_food_capacity())>100) str=HIC+"很饱";
        else if((my["food"]*100/ob->max_food_capacity())>90) str=HIG+"正常";
        else if((my["food"]*100/ob->max_food_capacity())>60) str=HIY+"缺食";        
		else if((my["food"]*100/ob->max_food_capacity())>30) str=CYN+"缺食";
        else if((my["food"]*100/ob->max_food_capacity())>10) str=HIR+"缺食";
        else str=RED+"饥饿";
        printf(NOR CYN"┃"NOR WHT"〖 食物 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR WHT"  〖 潜能 〗%s%14-d "NOR CYN"       ┃\n"NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"很饱";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"正常";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"缺水";
        else str=RED+"饥渴";
		printf(NOR CYN"┃"NOR WHT"〖 饮水 〗%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        printf(NOR WHT"  〖 杀气 〗%s%20-d "NOR CYN" ┃\n"HIG,HIR,(int)ob->query("bellicosity"));
        if (ob->query("xuewei"))
        	printf(NOR CYN"┃"NOR WHT"〖 学位 〗%s%12-s            "NOR,HIC,get_name(ob->query("xuewei")));
        else
        	printf(NOR CYN"┃"NOR WHT"〖 学位 〗                        "NOR);
		if (ob->query("degree"))
//			printf(NOR WHT"〖 官拜 〗%s%-21s   "NOR+WHT"〖 军队 〗%-8d"NOR CYN"              ┃\n"NOR,HIC,get_name(ob->query("degree")), ob->query("soilder"));
			printf(NOR WHT"〖 官拜 〗%s%-22s"NOR CYN"┃\n"NOR, HIC, get_name(ob->query("degree")));
		else
			printf(NOR WHT"〖 官拜 〗"NOR HIB"未入仕途"NOR CYN"              ┃\n");
		anger=ob->query("anger");
		printf(NOR CYN"┃"NOR WHT"〖 怒气 〗"NOR);
		if( !anger || anger<=0 )
			printf(GRN"□□□□□□□□□□",NOR);
		else {
			if(anger>100) anger = 100;
			for( x=0;x<anger/10;x++)
				printf(HIR+FLA"■"NOR);
			if(anger < 100)
				if( anger%10 == 0)
					for( i=0;i<(100-anger )/10;i++)
						printf(GRN"□"NOR);
				else
					for( i=0;i<(100-anger)/10+1;i++)
						printf(GRN"□"NOR);
		}
		sp_skill=ob->query_skill_mapped("spells");
		if(sp_skill)
			printf(WHT"    〖法术属性〗%s"CYN"                ┃\n"NOR,"/adm/daemons/spelld"->query_shuxing_chinese(
			SKILL_D(sp_skill)->query_shuxing()));
		else printf(WHT"    〖法术属性〗"CYN"你并没有学会任何法术┃\n"NOR);
		dao=(int)ob->query("daoxing");       
        printf(NOR CYN"┃"NOR WHT"〖 道行 〗%s%52-s    "NOR CYN"┃\n"NOR,HIM,COMBAT_D->chinese_daoxing(dao));
        
        printf(NOR CYN"┗━━━━━━━━━━━━━"HIY"月"HIR"·"HIY"影"HIR"·"HIY"奇"HIR"·"HIY"缘"NOR CYN"━━━━━━━━━━━━━┛\n"NOR);

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
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
 
