// wlist.c

#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
mapping levels=([
		"(admin)"       :  HIW "系统管理" NOR,
		"(arch)"        :  HIR "程序开发" NOR,
		"(wizard)"      :  HIY "开发辅助" NOR,
		"(apprentice)"  :  HIG "人事管理" NOR,
		"(immortal)"    :  HIM "实习管理" NOR,
		"(elder)"       :  HIB "管理顾问" NOR,
]);

string query_time(int time);

void create() { seteuid( getuid() ); }

int main(object me, string arg)
{
	string *list;
	int i, inv=0;
	string msg, time_msg,name;
	object ob, body;

	msg = HIR"\n ■"HIM " 〖"+ CHINESE_MUD_NAME+"〗"HIY"·"NOR CYN+INTERMUD_MUD_NAME+HIW"　巫师成员"+HIB"
—————————————————————————————————————\n"NOR;

	msg+="\n 中文名   英文名     等级     状态   　时间　             备注\n\n";
//	msg+="==========================================================================\n";
//————————————————————————————————————\n";
	list = sort_array(SECURITY_D->query_wizlist(), 1);

	for(i=0;i<sizeof(list);i++)
	{
		inv=0;
		ob=new(LOGIN_OB);
		ob->set("id", list[i]);
		ob->restore();
		if(objectp(body = find_player(list[i])) && !body->query("env/invisibility"))
		{
			time_msg=sprintf(" 连线：%s", query_time(time()-body->query_temp("temp/login_time")));
			name = body->query("name");
			inv=1;
		}
		else
			time_msg=sprintf(" 离线：%s", query_time(time()-ob->query("last_on")));

		msg+=sprintf(" %-10s%-8s%s  %s%-26s%s%s\n", inv?name:ob->query("name"), capitalize(list[i]),
			levels[SECURITY_D->get_status(list[i])],
			inv?HIY:NOR, time_msg, NOR,
			ob->query("duty")?ob->query("duty"):"───────"); 
		destruct(ob);
	}
	msg+=HIB"\n—————————————————————————————————————\n"NOR;
	msg+=sprintf(HIC" %s目前现在共有"+HIR"%s"+HIC"位管理者。\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
	write(msg);
	return 1;
}

string query_time(int time)
{
	string msg;
	int day, hour, min;

	msg="";
	day=time/86400;
	hour=time%86400/3600;
	min=time/60%60;
	
	if(min<1)
		min=1;
	if(day)
		msg+=sprintf("%s天", chinese_number(day));
	if(day<10 && hour)
		msg+=sprintf("%s小时", chinese_number(hour));
	if(!day && hour<20 && min)
		msg+=sprintf("%s分钟", chinese_number(min));
	return msg;
}

int help(object me)
{
write(@HELP
指令格式 : wlist

用途 : 列出目前所有的巫师名单(含客座巫师)。
HELP
     );
     return 1;
}

