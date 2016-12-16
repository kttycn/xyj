// wlist.c

#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
mapping levels=([
		"(admin)"       :  HIW "ϵͳ����" NOR,
		"(arch)"        :  HIR "���򿪷�" NOR,
		"(wizard)"      :  HIY "��������" NOR,
		"(apprentice)"  :  HIG "���¹���" NOR,
		"(immortal)"    :  HIM "ʵϰ����" NOR,
		"(elder)"       :  HIB "�������" NOR,
]);

string query_time(int time);

void create() { seteuid( getuid() ); }

int main(object me, string arg)
{
	string *list;
	int i, inv=0;
	string msg, time_msg,name;
	object ob, body;

	msg = HIR"\n ��"HIM " ��"+ CHINESE_MUD_NAME+"��"HIY"��"NOR CYN+INTERMUD_MUD_NAME+HIW"����ʦ��Ա"+HIB"
��������������������������������������������������������������������������\n"NOR;

	msg+="\n ������   Ӣ����     �ȼ�     ״̬   ��ʱ�䡡             ��ע\n\n";
//	msg+="==========================================================================\n";
//������������������������������������������������������������������������\n";
	list = sort_array(SECURITY_D->query_wizlist(), 1);

	for(i=0;i<sizeof(list);i++)
	{
		inv=0;
		ob=new(LOGIN_OB);
		ob->set("id", list[i]);
		ob->restore();
		if(objectp(body = find_player(list[i])) && !body->query("env/invisibility"))
		{
			time_msg=sprintf(" ���ߣ�%s", query_time(time()-body->query_temp("temp/login_time")));
			name = body->query("name");
			inv=1;
		}
		else
			time_msg=sprintf(" ���ߣ�%s", query_time(time()-ob->query("last_on")));

		msg+=sprintf(" %-10s%-8s%s  %s%-26s%s%s\n", inv?name:ob->query("name"), capitalize(list[i]),
			levels[SECURITY_D->get_status(list[i])],
			inv?HIY:NOR, time_msg, NOR,
			ob->query("duty")?ob->query("duty"):"��������������"); 
		destruct(ob);
	}
	msg+=HIB"\n��������������������������������������������������������������������������\n"NOR;
	msg+=sprintf(HIC" %sĿǰ���ڹ���"+HIR"%s"+HIC"λ�����ߡ�\n"NOR, MUD_NAME, chinese_number(sizeof(list)));
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
		msg+=sprintf("%s��", chinese_number(day));
	if(day<10 && hour)
		msg+=sprintf("%sСʱ", chinese_number(hour));
	if(!day && hour<20 && min)
		msg+=sprintf("%s����", chinese_number(min));
	return msg;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wlist

��; : �г�Ŀǰ���е���ʦ����(��������ʦ)��
HELP
     );
     return 1;
}

