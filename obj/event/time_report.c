//By waiwai@mszj 2000/11/12

#include <ansi.h>
#include <localtime.h>
#include <command.h>
inherit F_CLEAN_UP;

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";
        c_week = " ����"+c_week;

        c_time = chinese_number(day) + "��";
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        c_time += chinese_number(second) + "��";

        if (type) {
                switch( type ) {
                        case 5: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 1: return year+"��"+(member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��"+second+"��";
                        case 6: return (member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

void time_report() {
	seteuid( getuid() );
	users()->receive_message("event", HBMAG BLINK HIG"\n ���㱨ʱ " NOR HIR" �������й�����ʱ��:  " HIY+ chinese_time(5,(string)localtime(time())) + " \n\n" + NOR );

}
