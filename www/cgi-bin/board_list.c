/*
  www/cgi-bin/board_list.c
  By Ammy@YSZZ
  2001/04/13
  ʹ��ʱ��ȷ���������԰������ļ�������
 */ 

#include <mudlib.h>

inherit F_CLEAN_UP;
inherit F_REMOVEANSI;

private mapping vaild_boards = ([
        "ann_b" :       ({"��ʦ������",0}),
        "city_b" :      ({"�ϳǿ�ջ���԰�",1}),
        "dragon_b" :    ({"�����ĺ����԰�",1}),
        "honglou_b" :   ({"��¥��ʯ",1}),
        "jiangjing_b" : ({"��ׯ�۽�����",1}),
        "kaifeng_b" :   ({"�����������Ա�",1}),
        "moon_b" :      ({"�¹����԰�",1}),
        "query_b" :     ({"�����������԰�",1}),   
        "shengsi_b" :   ({"�ظ�������",1}),
        "shibei_b" :    ({"��̨ɽʯ��",1}),
        "system_b" :    ({"ϵͳ�����",0}),
        "wall_b" :      ({"�������Ա�",1}),
        "wudidong_b" :  ({"�޵׶��ʱ�",1}),        
        "xlwang_b" :    ({"�ϳǿ�ջ�����",1}), 
        "xueshan_b" :   ({"ѩɽ���԰�",1}),      
        "xy_b" :        ({"��Ĺ��ԯ��",1}),      

]);


string gateway() {
        int i,j=0;
        string str,str_h,str_f,*list;
        string number,master,time;
        mapping notes;
        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();

        list = keys(vaild_boards);
        sort_array(list,1);
        
        str =str_h;
        str+="<table width=100% border=0>";
        str+="<tr><td><span style='font-size:9pt'>";
        str+="&nbsp;&nbsp;"+MUD_NAME+"�Ѿ�������"+"/www/cgi-bin/uptime.c"->report();   
        str+="</span></td>";   
        str+="<td align=right><span style='font-size:9pt'>";
        str+=read_file("/log/counter_for_web");
        str+="&nbsp;&nbsp;</span></td></tr></table>";    

        str += "<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 width='100%' cellspacing=1 cellpadding=4>";

        str +=sprintf("
        <tr>
          <td align=center bgcolor='#fafafa' nowrap><b>&nbsp;</b></td>
          <td align=center bgcolor='#fafafa' nowrap><font 
          color='#339900'> ��� </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ���� 
            </font> </td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ��ʽ 
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'> ���¼��� 
            </font></td>
          <td align=center bgcolor='#fafafa' nowrap> <font color='#339900'>�Ұ�����</font></td>
        </tr>"
        );

        str += sprintf(
        "<tr> 
          <td bgcolor='#ccff99' colspan='6'><b><span style='font-size:11pt'><font color='#339900'>�� %s�﹫����</font></span></b></td>
         </tr>",
         MUD_NAME
         );
        for (i=0;i<2;i++) 
        {
        
                if(i==0) list[i]="ann_b";
                if(i==1) list[i]="system_b";    
                str +="<tr> <td bgcolor='whitesmoke' align=center valign=top><img src='http://202.119.144.5/~mudadm/mudweb/icon_folder_new.gif' height=15 width=15 border=0 hspace=0 alt='New Posts'></td>";
                number="/www/cgi-bin/board_h.c"->gateway(list[i],"num");
                master="/www/cgi-bin/board_h.c"->gateway(list[i],"master");
                time="/www/cgi-bin/board_h.c"->gateway(list[i],"time");
                str +=  sprintf(
                "<td bgcolor='whitesmoke' align=left>%d.<a href=board_read?%s&0&9999>%s</a></td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "<td bgcolor='whitesmoke' align=center>%s</td>"
                "</tr>",
                                j,
                                list[i],
                                vaild_boards[list[i]][0],
                                number,
                                vaild_boards[list[i]][1]==1?"��д":"ֻ��",
                                time,
                                master
                                );
        }
                
        str += sprintf(
        "<tr> 
          <td bgcolor='#ccff99' colspan='6'><b><span style='font-size:11pt'><font color='#339900'>�� %s������������</font></span></b></td>
         </tr>",
         MUD_NAME
         );
        
        for( i=0;i<sizeof(list);i++) 
        {
        
        if (list[i]=="ann_b" || list[i]=="system_b") continue;
        
        ++j;    
        str +="<tr> <td bgcolor='whitesmoke' align=center valign=top><img src='http://202.119.144.5/~mudadm/mudweb/icon_folder_new.gif' height=15 width=15 border=0 hspace=0 alt='New Posts'></td>";

/*
  the first: board's name ,decribtion,url,order number 
  the second: the number of all posts in this board
  the third:  the limiting of this board
  the 4th:  time of the last post         
  the 5th:  the  master's id of this board
*/

        number="/www/cgi-bin/board_h.c"->gateway(list[i],"num");
        master="/www/cgi-bin/board_h.c"->gateway(list[i],"master");
        time="/www/cgi-bin/board_h.c"->gateway(list[i],"time");
        str +=  sprintf(
        "<td bgcolor='whitesmoke' align=left>%d.<a href=board_read?%s&0&9999>%s</a></td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "<td bgcolor='whitesmoke' align=center>%s</td>"
        "</tr>",
                                j,
                                list[i],
                                vaild_boards[list[i]][0],
                                number,
                                vaild_boards[list[i]][1]==1?"��д":"ֻ��",
                                time,
                                master
                                );

        }

        str += "</table></table></center>";
        str +=str_f;
        return str;
}

mapping query_boards() {
        return vaild_boards;
}
