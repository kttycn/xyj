// wheremoney.c

#include <ansi.h> 

inherit F_CLEAN_UP;


int main(object me, string arg)
{
	string msg;

	seteuid(getuid());
	
	if( !(msg="/adm/daemons/moneyd"->show_msg()) ){
		write("现在没有发放任何钱财。\n");
		return 1;
	}
	write("似乎在下面这个地方可以挖到钱财：\n"+msg+"\n");
	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: wheremoney

这个指令对于寻找钱财相当有用。
HELP
   );
   return 1;
}
