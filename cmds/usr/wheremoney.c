// wheremoney.c

#include <ansi.h> 

inherit F_CLEAN_UP;


int main(object me, string arg)
{
	string msg;

	seteuid(getuid());
	
	if( !(msg="/adm/daemons/moneyd"->show_msg()) ){
		write("����û�з����κ�Ǯ�ơ�\n");
		return 1;
	}
	write("�ƺ�����������ط������ڵ�Ǯ�ƣ�\n"+msg+"\n");
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: wheremoney

���ָ�����Ѱ��Ǯ���൱���á�
HELP
   );
   return 1;
}
