// more.c
// 支持通配符的more.c
// by bikini@BITMUD on 02/14/2001

inherit F_CLEAN_UP;

#include <ansi.h>

int help(object me);

int main(object me, string arg)
{
	string file, dir, result;
	object ob;
    mixed *files;
    int i;
    
	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	dir = resolve_path(me->query("cwd"), arg);

    if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
    files = get_dir(dir, -1);

    dir = dir[0..strsrch(dir,"/",-1)];

    if( !sizeof(files) ){
        if (file_size(dir) == -2) return notify_fail("目录是空的。\n");
        else
            return notify_fail("没有这个目录或者文件。\n");
    }

    result = "";
    
    for(i=0; i<sizeof(files); i++){
        files[i][0] = resolve_path(dir,files[i][0]);
        if(!(int)SECURITY_D->valid_read(files[i][0], me)) continue;
        if(files[i][1] != -2) {
            result += sprintf(HIY"\n%s\n\n"NOR, files[i][0]);
            if(!(int)SECURITY_D->valid_read(files[i][0], me)) // added by bikini 没有权限休想看文件
                result += HIR"\n你没有权限读取该文件\n\n"NOR;
            else
                result += read_file(files[i][0]);
        }
    }

    me->start_more( result );
        
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
 
分页显示档案内容，支持通配符，如：more /cmds/imm/m* 或者 more /cmds/imm/*。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

HELP
    );
    return 1;
}
