/*  
   www/cgi-bin/post.c 
   Created by Ammy@YSZZ
   2001/04/12
   ���·���������
 */

inherit F_CLEAN_UP;

string gateway(string arg) {
        string str,str_h,str_f;
        string board_id,board_name,method,r_title;
        
        sscanf(arg,"%s&%s&%s&%s",board_id,board_name,method,r_title); 
        
        if (!r_title) r_title="Subject";
        
        str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();

	str=str_h;
	
	str+="<table border='0' width='95%'><tr>";
	str+="<td width='33%' align='left' nowrap><font face='����' style='font-size:9pt'>";
	str+="<a href='board_list.c'>";
	str+="<img src='http://202.119.144.5/~mudadm/mudweb/icon_folder_open.gif' alt='All Forums' height=15 width=15 border='0'>";
	str+="&nbsp;���԰�����ҳ��</a><br>";
        str+="<img src='http://202.119.144.5/~mudadm/mudweb/icon_bar.gif' height=15 width=15 border='0'>";
        str+="<img src='http://202.119.144.5/~mudadm/mudweb/icon_folder_open_topic.gif' height=15 width=15 border='0'>";
	str+=sprintf(
	"&nbsp;<a href='board_read?%s&0&9999'>%s</a><br>",
		board_id,
		board_name
	 );
	str+="</font></td></tr></table>";
	
	str +="<p align=center><font face='����' style='font-size:9pt'>";
	str +="<b>���棺</b> ��������������֮��ע����ܻظ�/������ӡ� <br>";
	str +="��Ҫע�����<a href='telnet://202.119.144.5:8000'>������</a>��";
	str +="��ӭ�������������磡<br>";
	str +="</font></p>";

	str+= sprintf(
"<form method='POST' action='/cgi-bin/board_post?board=%s&method=%s'>"
"<table border='0' cellspacing='0' cellpadding='0' align=center>"
"  <tr>"
"    <td bgcolor='black'>"
"    <table border='0' cellspacing='1' cellpadding='1'>"
"      <tr>"
"       <td bgColor='#f6f6f6' noWrap align='right'><font face='����' style='font-size:9pt'><b>�û�����</b></font></td>"
"       <td bgColor='#f6f6f6'>"
"<input name='id' maxLength='25' size='25' type='text' value='yourid at mud'"
"class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>"
"      </tr>"
"      <tr>"
"       <td bgColor='#f6f6f6' noWrap align='right'><font face='����' style='font-size:9pt'><b>���룺</b></font></td>"
"       <td bgColor='#f6f6f6' valign='top'>"
"<input name='pass' maxLength='25' size='25' type='password' value='password'"
"class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>"
"     </tr>"
"     <tr>"
"       <td bgColor='#f6f6f6' noWrap align='right'><font face='����' style='font-size:9pt'><b>���⣺</b></font></td>"
"       <td bgColor='#f6f6f6'>"
"<input maxLength='20' name='title' value='%s' size='40'"
"class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'>"
"���ɳ���20���ַ�������Ϊ10����</td>"
"     </tr>"
"     <tr>"
"       <td bgColor='#f6f6f6' noWrap vAlign='top' align='right'><font face='����' style='font-size:9pt'><b>���ݣ�</b><br>"
"       <br>"
"       </font></td>"
"       <td bgColor='#f6f6f6'><textarea cols='72' name='text' rows='15' wrap='VIRTUAL'"
"class=input onFocus=this.select() onMouseOver=this.focus() style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></textarea></td>"
"     </tr>"
"     <tr>"
"        <td bgColor='#f6f6f6'>&nbsp;</td>"
"        <td bgColor='#f6f6f6' align='center'>"
"<input name='submit' type='submit' value='����'"
"class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'>"
"&nbsp;<input name='reset' type='reset' value='��д'"
"class=input onFocus=this.select() onMouseOver=this.focus()  style='BORDER-BOTTOM: 1px solid; BORDER-LEFT: 1px solid; BORDER-RIGHT: 1px solid; BORDER-TOP: 1px solid;font-size:9pt'></td>"
"     </tr>"
"   </table>"
"   </td>"
" </tr>"
"</table>"
"</form>",
board_id,method,r_title
);

        str +=str_f;
        return str;
}
