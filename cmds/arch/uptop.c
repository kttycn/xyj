//Cracked by Roath

inherit F_CLEAN_UP;

int main(object me)
{
    object *user = users();
    for (int i=0;i<sizeof(user);i++)
    {
    	TOPTEN_D->topten_checkplayer(user[i]);
    	reset_eval_cost();
    }
    write("排行版更新完毕!\n");
    return 1;
 }
 
int help (object me)
{
        write(@HELP
指令格式: uptop
 
在线更新topten。
 
HELP
);
        return 1;
}
 
