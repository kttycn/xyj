/*
   www/cgi-bin/ip.c
   By ammy@YSZZ
   2001/04/18
 */
 


string gateway(string arg)
{
	string ip,from;
	string str,str_h,str_f,str_m;
	int ip1,ip2,ip3,ip4;
	
	str_h="/www/cgi-bin/inc_header.c"->gateway();
	str_f="/www/cgi-bin/inc_footer.c"->gateway();
	str_m=
	"<tr bgcolor=fafafa><td><br>
	����׷��IP�б���󲿷�����׷��<font color=red>2001/03/14</font><br><br>
	��ѯ��������ο��������������
	<a href='mailto:ammy%40yszz.net'>Mailto��Ammy</a><br><br>
	����������,<font color=red>2001/04/19</font><br><br>
	</td></tr>";
	
	
	str  = str_h;
	str +="<div align=center><br>��&nbsp;"+MUD_NAME+"������׷��</div>";
        str += "<table border=0 width='400' cellspacing=0 cellpadding=0 align=center>";
        str += "<tr><td bgcolor='black'> ";
        str += "<table border=0 width='100%' cellspacing=1 cellpadding=4>";
  	str += "<form action='ip.c' id=ip name=ip method=post> \n";
  	str += "<tr bgcolor=fafafa><td>
  		��������Ҫ��ѯ��IP��ַ:
  		<input class=input type=text name=ip size=20
  	                onFocus=this.select() onMouseOver=this.focus()
                        value='202.119.144.5' 
                        style='font-size:9pt;
                        BORDER-BOTTOM: 1px solid;
                        border-left: 0px solid; 
                        border-right: 0px solid;
                        border-top: 0px solid;'
                        >";
        str += "&nbsp;
        	<input class=input type=submit name=submit
                        value=submit 
                        style='font-size:8pt;
                        color: #000000; background-color: #fafafa;
                        BORDER-BOTTOM: 1px solid;
                        border-left: 0px solid; 
                        border-right: 0px solid;
                        border-top: 0px solid;'
                        >
        	<input class=input type=reset name=reset
                        value=reset 
                        style='font-size:8pt;
                        color: #000000; background-color: #fafafa;
                        BORDER-BOTTOM: 1px solid;
                        border-left: 0px solid; 
                        border-right: 0px solid;
                        border-top: 0px solid;'
                        >                        
                        </td></tr>";
	str += "</form>";
	
	if ( arg ) sscanf(arg,"ip=%s&submit=submit",ip);
		

	if ( !arg || !ip)
	{
		str += "<tr bgcolor=fafafa><td><font color=green>";
		str += "�밴�����ʽ������Ҫ��ѯ��ip��ַ.";
		str += "</font></td></tr>";
		str += str_m;
		str +="</table></td></tr></table>";
		str += str_f;
		return str;
	}

		
	if (sscanf(ip,"%d.%d.%d.%d",ip1,ip2,ip3,ip4)!=4)
	{
		str +="<tr bgcolor=fafafa><td><font color=red>";
		str +="�Բ������ݸ�ʽ�������������룡";
		str += "</font></td></tr>";
		str += str_m;
		str +="</table></td></tr></table>";
		str += str_f;
		return str;
	} 

	from="/adm/daemons/ipd.c"->seek_ip_address(ip);
	
	str +="<tr bgcolor=fafafa><td>";
	str +="�������IP:<font color=red>"+ip+"</font>";
	str +="����:<font color=green>"+from+"</font>";
	str += "</font></td></tr>";
	str += str_m;
	str +="</table></td></tr></table>";
	str +=str_f;		    
	return str;
}
	
