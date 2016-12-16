/*
   autdor: ken@XAJH2
   modified by Ammy@YSZZ 
   2001/04/13
   ��Ҫ��Ӧ�޸�DNS_MASTER �е������趨����
 */ 
 
#include <net/daemons.h>
#include <net/macros.h>
 
inherit F_CLEAN_UP;
inherit F_REMOVEANSI;

private string get_mudlib(string s);
private string get_driver(string s);
private string mail_link(string s);
private string web_link(string s); 

string gateway(string pattern) 
{
        mapping mudlist = DNS_MASTER->query_muds();
        int    i=0,nummuds = sizeof(mudlist),loop,size;
        string  *muds = keys( mudlist );
        string  *matches;
	string str,str_h,str_f;
	str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        
        str =str_h;
        str +="<br><div align=center><br>��&nbsp;"+MUD_NAME+"����������б�</div>";
        str += "<table border=0 widtd='700' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str +="<table border=0 widtd='100%' cellspacing=1 cellpadding=4>";       

        muds = sort_array(muds, 1);

        if ( !pattern )
                matches = muds;
        else
        {
                if( !mapp(mudlist[pattern]) )
                        return str_h+"<font color=red>"
                        "<br><br><br><div align=center>"+upper_case(pattern)
                        +"û���ҵ�</div><br><br><br></font>"
                        +str_f;

                matches = mudlist[pattern];
                str += sprintf(
                "<tr bgcolor=whitesmoke align=center><td colspan=2><a href="
                "telnet://%s:%s>%s</a></td></tr>"
                "<tr bgcolor=whitesmoke><td>Current Mudlib</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Base Mudlib</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Mud driver</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>TCP service</td><td>%s</td></tr>"                
                "<tr bgcolor=whitesmoke><td>Language</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Admin Email</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Mudlib web</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Host name</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Host address</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>User port</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>UDP port</td><td>%s</td></tr>"                                                                  
                "<tr bgcolor=whitesmoke><td>Online user</td><td>%s</td></tr>"
                "<tr bgcolor=whitesmoke><td>Local Time</td><td>%s</td></tr>"
                "</table>",
                	mudlist[pattern]["HOSTADDRESS"],
                	mudlist[pattern]["PORT"],
                	undefinedp( mudlist[pattern]["MUDNAME"] ) ?
                	 pattern : mudlist[pattern]["MUDNAME"],
                	undefinedp( mudlist[pattern]["VERSION"] ) ?
                	 "����" : mudlist[pattern]["VERSION"],
                	get_mudlib( mudlist[pattern]["MUDLIB"] ),
                	get_driver( mudlist[pattern]["DRIVER"] ),
                	undefinedp( mudlist[pattern]["TCP"] ) ?
                	 "����" : mudlist[pattern]["TCP"],
                	undefinedp(mudlist[pattern]["ENCODING"])? 
                	"����": (mudlist[pattern]["ENCODING"]=="GB"?"���庺��":"���庺��"),
                	mail_link( mudlist[pattern]["ADM_EMAIL"] ),
                	web_link( mudlist[pattern]["MUD_WEB"] ),
                	undefinedp( mudlist[pattern]["TIME"] ) ?
                	 "����" : mudlist[pattern]["HOST"],
                	undefinedp( mudlist[pattern]["HOSTADDRESS"]) ?
                	 "����" : mudlist[pattern]["HOSTADDRESS"],
                	undefinedp( mudlist[pattern]["PORT"]) ?
                	 "����" : mudlist[pattern]["PORT"],
                	undefinedp( mudlist[pattern]["PORTUDP"]) ?
                	 "����" : mudlist[pattern]["PORTUDP"],
                	undefinedp( mudlist[pattern]["USERS"] ) ? 
                	 "����" : mudlist[pattern]["USERS"],
                	undefinedp( mudlist[pattern]["TIME"] ) ? 
                	 "����" : mudlist[pattern]["TIME"],
                );

			str+="</td></tr></table>";
			str=remove_ansi(str);
			str+=str_f;
                        return str;
        }
  

        matches = filter_array(matches, (: $(mudlist)[$1]["_dns_no_contact"] == 0 :));

	str +="<tr bgcolor=#fafafa align=center>";
	str +="<td width=50>MUD</td><td width=300>��������</td>
	      <td width=200>������·��ַ</td><td width=50>����</td><td width=100>����</td>";
       	str +="</tr>";
        for(loop = 0, size = sizeof(matches); loop<size; loop++) 
        {      

                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        str += "<tr align=center bgcolor=#ccff99>";
                else
                        str += "<tr align=center bgcolor=whitesmoke>";

                if( undefinedp(mudlist[matches[loop]]["MUDNAME"]) ) {
                        str +=  sprintf(
                        "<td align=left colspan=2>%-43s</td>"
                        "<td>%-15s</td>"
                        "<td>%4s</td>", 
                                upper_case(matches[loop]),
                                mudlist[matches[loop]]["HOSTADDRESS"],
                                mudlist[matches[loop]]["PORT"]);
                }
                else {
                        str +=  sprintf(
                        "<td align=left>%-20s</td>"
                        "<td><a href='mudlist.c?%s'>%-23s</a></td>"
                        "<td><a href='telnet://%s:%s'>%-15s</a></td>"
                        "<td>%4s</td>", 
                                upper_case(matches[loop]),
                                lower_case(matches[loop]),
                                undefinedp(mudlist[matches[loop]]["MUDNAME"])?
                                "":mudlist[matches[loop]]["MUDNAME"],
                                mudlist[matches[loop]]["HOSTADDRESS"],
                                mudlist[matches[loop]]["PORT"],
                                mudlist[matches[loop]]["HOSTADDRESS"],
                                mudlist[matches[loop]]["PORT"]);
                }
                if(!undefinedp(mudlist[matches[loop]]["USERS"]))
                                str+=sprintf("<td>%-4s</td>", mudlist[matches[loop]]["USERS"] );
                else
                                str+=sprintf("<td>----</td>", mudlist[matches[loop]]["USERS"] );

                str +="</tr>";
               
        }

        str += "</table></td></tr></table>";

        str += sprintf("<div align=right>����<font color=red>"+
                        sizeof(mudlist)+ " </font>�� Mud ������ InterMud������ <font color=red>"+
                        sizeof(matches)+" </font>�� Mud �� "
                        "%s</font> ����&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>",
                        CHINESE_MUD_NAME
                        );

	str =remove_ansi(str);
	str+=str_f;
        return str;
}


private string get_mudlib(string s)
{
        switch (s[0..3])
        {
       	case "YSZZ":
                return sprintf("<a href=http://www.yszz.net/>%s</a>", s);
       	case "ES":
                return sprintf("<a href=http://192.168.0.1/>%s</a>", s);                           
        default:
                return "����";
        }
}

private string get_driver(string s)
{
        if( sizeof(s) < 4 )             
        	s="unknow";
        switch (s[0..4])
        {
                case "MudOS":
                        return "<a href=http://www.mudos.org>" + s + "</a>";
                default:
                        return "����";
        }
}

private string mail_link(string s)
{
        if( sizeof(s) < 3 )     return "����";
        return sprintf("<a href=mailto:%s>%s</a>", s, s);
}

private string web_link(string s)
{
        if( sizeof(s) < 4 )     return "����";
        return sprintf("<a href=%s>%s</a>", s, s);
}
