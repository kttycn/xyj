/*
	www/cgi-bin/inc_footer.c
	Created by Ammy@YSZZ
	2001/04/13
	��ÿ��ҳ��ĵײ�����
*/	

string gateway()
{
	string ret;
	ret="<p></p>";
	ret+="<table border=0 width='95%' cellspacing=0 cellpadding=0 align=center>";
  	ret+="<font face='����'>";
  	ret+="<tr> <td> ";
  	ret+="<table width=100% border=0 bgcolor='whitesmoke'>";
	ret+="<tr bgcolor='whitesmoke'>"; 
	ret+="<td bgcolor='whitesmoke'> ";
        ret+="<table border=0 width='100%'>";
        ret+="<tr> ";
        ret+=" <td bgcolor='whitesmoke' align=left valign=top nowrap><font face='����' style='font-size:9pt'> 
                 <a href=/index.html>����֮�����߲�ѯ</a></font></td>
                <td bgcolor='whitesmoke' align=right valign=top nowrap><font face='����' style='font-size:9pt'> 
                  �������� <a href=finger?id=ammy>Ammy@YSZZ</a> </font></td>
             ";
        ret+="</tr></table><td bgcolor='whitesmoke' width=10 nowrap><a href='#top'><img src='http://202.119.144.5/~mudadm/mudweb/icon_go_up.gif' height=14 width=15 border='0' align='right' alt='��ҳ��'></a></td></tr></table></td></tr></font></table></table>";
	return ret;
}
