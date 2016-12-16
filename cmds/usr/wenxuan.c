// wenxuan.c 
// by snowman@SJ 23/04/1999
// Last modified by jjgod@FYTX. 01/03/07.

#include <ansi.h>
#include <localtime.h>

inherit F_CLEAN_UP;
int help(object me);
int list(object me, int y)
{
	string *note;
	string str;
	int i, j;

	tell_object(me, y+" ��"); 
	note = get_dir("/data/wenxuan/"+y+"/");
	i = sizeof(note);
	if (!i){
		write("��û���κ���ѡ��\n");
		return 0;
		}

	write("����"+chinese_number(i)+"����ѡ��\n");
	str = "������������������������������������������������������������������������������\n";
	for(j=0;j<i;j++)
		str += " ["HIW+(j+1)+NOR"] "+read_file("/data/wenxuan/"+y+"/"+(j+1)+".w", 1, 1);
		me->start_more(str+"������������������������������������������������������������������������������\n");
	return 1;           
}

int read_note(object me, int number,int y)
{
	string *note;
	int i;
    
	tell_object(me, y+" ��"); 
	note = get_dir("/data/wenxuan/"+y+"/");
	i = sizeof(note);
	if (!i)
	{
		write("��û���κ���ѡ��\n");
		return 0;
	}
	if( number < 1 || number > i )
	{
		write("Ŀǰ��û������Ҫ������ƪ��ѡ��\n");
		return 0;
	}

	write("�ĵ�"+chinese_number(number)+"����ѡ��\n\n");
	me->start_more( "["HIW+number+NOR"] "+read_file("/data/wenxuan/"+y+"/"+number+".w"));
	return 1;
        
}

int main(object me, string arg)
{
	string *file, str;
	int i, j, number,y;

	tell_object(me,"��"HIW+MUD_NAME+NOR"��ѡ��ȫ����");
        
	file = get_dir("/data/wenxuan/");
	i = sizeof(file);
	if (!i) return notify_fail("������ʱ��û����ѡ��\n");

	y = localtime(time())[LT_YEAR];
        
	if (!arg) list(me, y);
                
	else if(sscanf(arg, "%d %d", number,j)==2){
		if(j < 1970 || j > y ) 
			return notify_fail("��û�� ["+j+"] �������ѡ�ء�\n");
		if(number == 0)
			list(me, j);
		else read_note(me, number, j);
	}
	else if(sscanf(arg, "%d %d", number, y)==2){
		if(number == 0)
			list(me, y);
		else read_note(me, number, y);
	}
	else if(arg == "all"){
		str = "Ŀǰ�� ";
		while(i--) str += "["+file[i]+"��] ";
		tell_object(me, str+"����ѡ��\n");
	}
	else if(sscanf(arg, "%d", number)==1)
	read_note(me, number, y);
        
	else help(me);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��

wenxuan all                  : �г�����ѡ����ݡ�
wenxuan                      : �г�������ѡ��
wenxuan <���>               : �Ķ�����˱�ŵ����¡�
wenxuan 0 <���>             : �г�������ѡ��
wenxuan <���> <���>        : �Ķ�����ݴ˱�ŵ����¡�

HELP
    );
    return 1;
}
