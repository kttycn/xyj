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
    write("���а�������!\n");
    return 1;
 }
 
int help (object me)
{
        write(@HELP
ָ���ʽ: uptop
 
���߸���topten��
 
HELP
);
        return 1;
}
 
