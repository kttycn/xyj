/*
        www/cgi-bin/wizlist.c
        Created by Ammy@YSZZ
        2001/04/13
        ��ʦ�б�������ʾ��������Լ���ע�ȣ��������䣩
*/      

#include <mudlib.h>

inherit F_REMOVEANSI;
inherit F_CLEAN_UP;

mapping levels=([
        "(admin)"       :       "��    ��",
        "(arch)"        :       "�� �� ʦ",
        "(wizard)"      :       "��    ʦ",
        "(apprentice)"  :       "������ʦ",
        "(immortal)"    :       "С �� ʦ",
        "(elder)"       :       "�����ܹ�",
]);
 
int level(mixed, mixed);    
string query_time(int time);

void create() { seteuid( getuid() ); }

string gateway(object me, string arg)
{
        string *list;
        int i, j,inv=0;
        string str, time_str,str_h,str_f;
        object ob, body;
        string *task=explode(read_file("/adm/etc/wizjob"),"\n");        

        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        str =str_h;

        str+="<br><div align=center>��&nbsp;"+MUD_NAME+"�� ��ʦ�б�<br>";
        str += "<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";

        str +=sprintf("
        <tr>
          <td align=center bgcolor='#fafafa' nowrap><b>������</b></td>
          <td align=center bgcolor='#fafafa' nowrap><font 
          color='#339900'>Ӣ����</font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> �ȼ�
            </font> </td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ״̬
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ����ʱ�� 
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ��ע </font></td>
        </tr>"
        );        

        list = sort_array(SECURITY_D->query_wizlist(),(: level :));

        for(i=0;i<sizeof(list);i++){
          if(list[i]=="ammy") continue;
          inv=0;
          ob=new(LOGIN_OB);
          ob->set("id", list[i]);
          ob->restore();

          if(objectp(body=find_player(list[i])) && !body->query("env/invisibility"))
          {
           time_str=sprintf(
           "<td width=40 align=center><font color=orange>����</font></td><td width=180>%s</td>"
           , query_time(body->query_temp("temp_time")));
           inv=1;
          } 
          else 
          time_str=sprintf(
          "<td width=40 align=center><font color=black>����</font></td><td width=180>%s</td>"
          , query_time(ob->query("last_on")));
          
          str+=sprintf(
          "<tr bgcolor='whitesmoke'>"
          "<td>%s</td>"
          "<td align=center><a href=finger?id=%s>%s</a></td>"
          "<td align=center>%s</td>"
          "%s"
          "<td  align='center'>%s</td></tr>",
                         ob->query("name"), 
                         list[i],
                         list[i],
                         levels[SECURITY_D->get_status(list[i])], 
                         time_str,
                         task[i]+"<br>"); 
          destruct(ob);
        }
        str+=sprintf("</table></td></tr></table><div align=right>%s���ڹ���%s����ʦ&nbsp;&nbsp;&nbsp;&nbsp;</div>", MUD_NAME, chinese_number(sizeof(list)-1));
        str+=str_f;
        return remove_ansi(str);
}

string query_time(int time)
{
        string str;
        int day, hour, min;
        
        time=time()-time;
        
        str="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                str+=sprintf("%s��", chinese_number(day));
        if(day<10 && hour)
                str+=sprintf("%sСʱ", chinese_number(hour));
        if(!day && hour<20 && min)
                str+=sprintf("%s����", chinese_number(min));
        return str;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob2) - wiz_level(ob1);
        return ob1 > ob2?-1:1;
}
