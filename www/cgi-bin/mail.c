/*
  www/cgi-bin/mail.c
  Created by Ammy@YSZZ
  2001/04/13
 */ 
 
inherit F_REMOVEANSI;

string gateway()
{
	string str,str_h,str_f;
	str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        
        str =str_h;
        str+="<p align=center><br><br>";
        str+="<font color=#FF0000>Sorry�����������У��ݲ�����!</font><br><br><br><br></p>";
        str+=str_f;
        return str;
}
