/*
	www/cgi-bin/inc_header.c
	Created by Ammy@YSZZ
	2001/04/13
	��ÿ��ҳ��Ķ�������
*/
	
#include <mudlib.h>

inherit F_REMOVEANSI;

string gateway()
{
        string ret;
        
        ret="<head><title>"+MUD_NAME+"���߲�ѯ</title>\n";
        ret+="<link rel='stylesheet' href='../style.css'>\n";
        ret+="</HEAD>\n";
        
        ret+="\n";
        ret+="<table align='center' border='0' cellPadding='0' cellSpacing='0'
width='100%'>\n";
        ret+="<tr>\n";
        ret+="<td valign='top' width='50%'><a href='http://www.yszz.net'><img
alt='����֮����ҳ' border='0'
src='http://202.119.144.5/~mudadm/mudweb/FLOG_YSZZ.gif'></a></td>\n";
        ret+="<td align='center' valign='top' width='50%'>\n";
        ret+="    <table border='0' cellPadding='2' cellSpacing='0'>\n";
        ret+="          <tr>
                        <td align='center'><font face='����'
style='font-size:9pt'><b><a href='/index.html'>����֮�����߲�ѯϵͳ</a></b></font></td>
                        </tr>\n";
        ret+="<tr>
          <td align='center'><a href='board_list.c'>���԰�</a>
            | <a href='wizlist.c'>��ʦ�б�</a> | <a href='who.c'>�����û�</a>
            | <a href='top.c'>���߸���</a> | <a href='topten.c'>TOPTEN</a>
            | <a href='mudlist.c'>�������</a></td>
          </tr>\n";
        ret+="<form action='login.c' method='post' id=login name=login>\n";
        ret+="<tr><td align='center'><table><tr>\n";
        ret+="<td><b>�û�:</b><br><INPUT type='text' name='name' size='10' value='' 
class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>\n";
        ret+="<td><b>����:</b><br><INPUT type='password' name='pass' size='10' value=''
class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>\n";
        ret+="<td valign='bottom'><INPUT
src='http://202.119.144.5/~mudadm/mudweb/button_login.gif' type='image'
value='Login' name='submit' type='submit' border=0 hspace=4></td>\n";
        ret+="</tr>\n";
        ret+="<tr><td colspan='3' align='center'><font face='����'
style='font-size:9pt'><a href=passwd.c>����������룿</a></font></td></tr>\n";
        ret+="</table></td></tr></form></table></td></tr></table>\n";
        return ret;                             
}
                        
                                
