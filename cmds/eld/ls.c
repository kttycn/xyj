//ls.c
//By Bill 2000/5/3
#include <ansi.h>
#include <localtime.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir,dir1,result,cwd = me->query("cwd"), str;
	mixed *files,times;
	mixed *file,*arrge;
	object obj;

	int i,j,e,d,c,w,fc,dc,bytes,*dis;

	seteuid(geteuid(this_player(1))); 
	dir = resolve_path(cwd, arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
	files = get_dir(dir, -1);

	dir = dir[0..strsrch(dir,"/",-1)];
	if( !sizeof(files) ){
		if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
		else return notify_fail("没有这个目录或者文件。\n");
	}
	write("\n"+HIY+"〖"+MUD_NAME+HIY"〗"NOR+"文件目录："  + "\n");
	write(""+HIR+"----------------------------------------------------------------------------"NOR);
	result ="\n"NOR;
	for(i=0;i<sizeof(files);i++){
		files[i][0] = resolve_path(dir,files[i][0]);
		if(!(int)SECURITY_D->valid_read(files[i][0], me)) continue;
		times = localtime(files[i][2]);
		if(files[i][1] == -2) result += sprintf(HIW"<  目录 >"NOR"     %-=40s%4d/%2d/%2d/%2d:%2d\n",
			files[i][0],times[LT_YEAR],times[LT_MON],times[LT_MDAY],times[LT_HOUR],times[LT_MIN]);
		else
		{
			if (find_object(files[i][0])) str = "*";
			else str = " ";
			result += sprintf(HIG"%-9d    "HIY"%s"NOR"%-=40s%4d/%2d/%2d/%2d:%2d\n",
			files[i][1],str,files[i][0],times[LT_YEAR],times[LT_MON],times[LT_MDAY],times[LT_HOUR],times[LT_MIN]);
		}
	}
   
	i = sizeof(files);
	c = 0;
	w = 0;
	dis=allocate(i);
	while(i--) {
		dir1=files[i][0];
//    dir1=(arg[strlen(arg)-1]=='/')?(arg+dir1):(arg+"/"+dir1);
		dir1=(dir1[0]=='/')?dir1:"/"+dir1;
		if(files[i][0]=="."||files[i][0]=="..")
			continue;//直接跳过算了，不然".."总是不能正常显示
		if(file_size(dir1)==-1)
			dis[d++]=i+1;
		if(files[i][1]==-2) {
			files[i][0] =files[i][0]+"/";
			c++;
		}
	}
	fc = sizeof(files) - c;
	dc = c;
	bytes = c+c;
	j = sizeof(files);

	if (sizeof(files)) {
		for(i=0; i<j; i++) {
			bytes += files[i][1];
		}
	}

	printf("\n       "+WHT"%4d"NOR+"个目录       "+WHT"%4d"NOR+"个文件       "+
	WHT"%d"NOR+"字节", dc, fc, bytes);
	write("\n"+HIR+"----------------------------------------------------------------------------"NOR+" "  + "\n");
	write(HIR+"目录及字节             目录及文件名称                     最后修改日期      "NOR+" "  + "\n");

	me->start_more(result);
	write(HIR+"----------------------------------------------------------------------------"NOR+" "  + "\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: ls [<路径名>]
以长格式列出目录下所有的子目录及档案, 如果没有指定目录, 则
列出所在目录的内容，所列出的档案中前面标示 * 号的是已经载入
的物件。黄色目录为无权限读取的目录。

相关命令：lf

HELP
	);
	return 1;
}
