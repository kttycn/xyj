
/* 
   www/cgi-bin/uptime.c  
   By Ammy@YSZZ 
   /2001/04/12/
   is called at board_list.c
*/ 

inherit F_CLEAN_UP;

string report()
{
        int t, d, h, m, s;
        string time;

        t = uptime();
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "�롣\n";
	return time;
}


