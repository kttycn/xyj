// more.c
// ֧��ͨ�����more.c
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
	if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
	dir = resolve_path(me->query("cwd"), arg);

    if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
    files = get_dir(dir, -1);

    dir = dir[0..strsrch(dir,"/",-1)];

    if( !sizeof(files) ){
        if (file_size(dir) == -2) return notify_fail("Ŀ¼�ǿյġ�\n");
        else
            return notify_fail("û�����Ŀ¼�����ļ���\n");
    }

    result = "";
    
    for(i=0; i<sizeof(files); i++){
        files[i][0] = resolve_path(dir,files[i][0]);
        if(!(int)SECURITY_D->valid_read(files[i][0], me)) continue;
        if(files[i][1] != -2) {
            result += sprintf(HIY"\n%s\n\n"NOR, files[i][0]);
            if(!(int)SECURITY_D->valid_read(files[i][0], me)) // added by bikini û��Ȩ�����뿴�ļ�
                result += HIR"\n��û��Ȩ�޶�ȡ���ļ�\n\n"NOR;
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
ָ���ʽ : more <����>|<�����>
 
��ҳ��ʾ�������ݣ�֧��ͨ������磺more /cmds/imm/m* ���� more /cmds/imm/*��
 
more ģʽ�µ�ָ��:
q      : �뿪 more.
b      : ��ʾǰһҳ������.
[ENTER]: ��ʾ��һҳ������.

HELP
    );
    return 1;
}
