// toptenadd.c
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str,*astr, msg;
	int i;
	seteuid(geteuid(me));
	if (!arg||arg=="")
	{
		msg = HIY+"�� "+CHINESE_MUD_NAME+" ��"HIC"��Ŀǰ���������а�\n"NOR+
			HIM"����������������������������������������������������������������"NOR+
			HIR"\n������ "+HIC+RICH_B+"������rich"+
			HIR"\n������ "+HIC+PKER_B+"������pker"+
			HIR"\n������ "+HIC+MASTER_B+"������master"+
			HIR"\n������ "+HIC+EXP_B+"������exp"+
			HIR"\n������ "+HIC+DX_B+"������dx"+
			HIR"\n������ "+HIC+KILL_B+"������killer"+
			HIR"\n������ "+HIC+SPELLS_B+"������spells"+
			HIR"\n������ "+HIC+FORCE_B+"������force"+
			HIR"\n������ "+HIC+PER1_B+"������per1"+
			HIR"\n������ "+HIC+PER2_B+"������per2"+
			HIR"\n������ "+HIC+AGE_B+"������age"+
			HIR"\n������ "+HIC+QUESTS_B+"������quests"+
			HIR"\n������ "+HIC+TASK_B+"������task"+
			HIM"\n����������������������������������������������������������������"NOR;
		write ( msg+"\n");
		return 1;
	}
	str=TOPTEN_D->topten_query(arg);
	write(str+"\n");
	return 1;
}
/*
int help(object me)
{
write(@HELP
ָ���ʽ : topten <����> <���ID>
	���ͣ�rich(ʮ����)|per1(ʮ���������)|per2(ʮ����������)|spells(ʮ��ħ������)|  pker(ʮ��ɱ�˿�)|age(ʮ���ϲ���)|exp(ʮ�����)|force(ʮ����������)|kill(ʮ��ħͷ)
HELP
    );
    return 1;
}
*/
