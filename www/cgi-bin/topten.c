/*
   www/cgi-bin/topten.c
   created by ammy@yszz
   2001/04/12
   ʮ��������а�   
*/	

#include <mudlib.h>

inherit F_REMOVEANSI;

private mapping all_types = ([
	"exp" : 	({"����"}),
	"neili" : 	({"����"}),
	"mana" : 	({"����"}),
	"rich" :	({"����"}),
	"pker" :	({"ɱ�˿�"}),
	"per1" :	({"˧��"}),
	"per2" :	({"��Ů"}),
	"age" :		({"�����"}),
]);

string gateway()
{
	string str,str_h,str_f;
	string *list;
	string b_name,f_name,*astr,*bstr,name,id;
	int i,j,k,data;
			
	str_h="/www/cgi-bin/inc_header.c"->gateway();
        str_f="/www/cgi-bin/inc_footer.c"->gateway();
        
        str =str_h;
        
        str +="<div align=center><br>��&nbsp;"+MUD_NAME+"���������а�</div>";
        str += "<table border=0 width='750' cellspacing=0 cellpadding=0 align=center bgcolor='black'>";
        str += "<tr>";
        
        
	list=keys(all_types);
	sort_array(list,1);
        
        for (k=0;k<sizeof(list);k++)
        {
        	f_name="/topten/"+list[k]+".txt";	
		b_name="<div algin=center>ʮ��"
		       +all_types[list[k]][0]
		       +"���а�</div>";
       		       		
       		
       		if(file_size(f_name)==-1){
			str +="<td valign=top><table border=0 width='100%' cellspacing=1 cellpadding=4>"; 
        		str+="<tr bgcolor=whitesmoke>";
        		str+="<td nowrap>"+b_name+"<br></td></tr>";
                	str +="<tr><td bgcolor=whitesmoke align=center><font color=red>WRONG!<br></font>"+b_name+"�����ļ���û�д�����<br><br>"
        		+"</td><tr>";
        		str+="</table></td>";
        		continue;}
        		
        	astr=explode(read_file(f_name),"\n");        	
		str +="<td valign=top><table border=0 width='100%' cellspacing=1 cellpadding=4>"; 
        	str+="<tr bgcolor=whitesmoke>";
        	str+="<td nowrap align=center>"+b_name+"(<font color=orange>topten&nbsp;"+list[k]+"</font>)</td></tr>";
        	for(i=0;i<sizeof(astr);i++)
        	{
                	bstr=explode(remove_ansi(astr[i]),";");            
                	for(j=0;j<sizeof(bstr);j++)
               		{
                        sscanf(bstr[j],"%s(%s)%d",name,id,data);                       
                        str +=sprintf(
                        	"<tr bgcolor=whitesmoke><td align=center>"
                          	"%s<br>"
                          	"[<a href=finger?id=%s>%s</a>]</td></tr>"
                          	,
                          		name,lower_case(id),id
                          );	
                	}
                	
                }
                if (i<10)
                	for (i;i<10;i++)
                	   str +="<tr bgcolor=whitesmoke><td>&nbsp;<br>&nbsp;</td></tr>";
                str+="</table></td>";
        }
        
        str+="</tr></table>";
        
        str+=str_f;
        return str;

}        
