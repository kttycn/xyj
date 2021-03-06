// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("你要删除那个档案?\n");
	if( rm(resolve_path(me->query("cwd"), file)) ) {
		write("Ok.\n");
		log_file("cmds/rm",
		sprintf("%s(%s) 在 %s 目录下 删除 %s on %s\n",
		me->name(1),   //记录使用命令的人名
		geteuid(me),   //记录使用命令的ID
		me->query("cwd"),//记录文件所在目录
		file,          //记录删除的文件
		ctime(time()) ) ); //记录使用命令的时间
	}
	else
		write("你没有删除这个档案的权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你删除有权修改的档案。
HELP
    );
    return 1;
}
