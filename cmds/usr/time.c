// time.c
#include <mudlib.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("������"HIM " ��"+ CHINESE_MUD_NAME+"��"HIY"��"NOR CYN+
	INTERMUD_MUD_NAME + NOR + " " + NATURE_D->game_time() + "��\n");
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ������֪�����ڵ�ʱ����

HELP
    );
    return 1;
}
