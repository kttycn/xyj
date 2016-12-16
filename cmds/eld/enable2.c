// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping valid_types = ([
	"unarmed":	"ȭ��",
	"sword":	"����",
	"blade":	"����",
	"stick":	"����",
	"staff":	"�ȷ�",
	"throwing":	"����",
	"force":	"�ڹ�",
	"parry":	"�м�",
	"dodge":	"�Ṧ",
	"spells":	"����",
	"whip" :	"�޷�",
	"spear":	"ǹ��",
	"axe":      "����",
	"mace":     "ﵷ�",
	"fork":		"�淨",
	"rake":		"�ٷ�",
	"archery":	"����",
	"hammer":	"����",
	"halberd":  "ꪷ�",
	"literate": "����ʶ��",
	"needle":   "�뷨",
]);

int main(object me, string arg)
{
	mapping map;
	string *types, *skill, ski, map_to;
	int i, modify;
	string check;
	object who;

	seteuid(getuid());
	if (!arg)
		return notify_fail("����ȷʹ�����enable2 <id>\n");
	
	who = present( arg, environment(me) );

	if (!who) me = LOGIN_D->find_body(arg);
	if (!who) return notify_fail("û������ˡ�\n");

	map = who->query_skill_map();
	if( !mapp(map) || sizeof(map)==0 )
		return notify_fail(who->query("name")+"����û��ʹ���κ����⼼�ܡ�\n");

	skill = keys(valid_types);
	write("������"+who->query("name")+"Ŀǰʹ���е����⼼�ܡ�\n");
	for (i=0; i<sizeof(skill); i++) {
		if( undefinedp(valid_types[skill[i]]) ) {
			map_delete(map, skill[i]);
			continue;
		}
		if( !who->query_skill(skill[i]) ) continue;
		if( undefinedp(map[skill[i]]) ) continue;
		modify = who->query_temp("apply/" + skill[i]);
		printf("  %-20s�� %-20s  ��Ч�ȼ���%s%4d\n" NOR, 
			valid_types[skill[i]] + " (" + skill[i] + ")",
			undefinedp(map[skill[i]]) ? 
			"��" : to_chinese(map[skill[i]]),
			(modify==0 ? "" : (modify>0 ? HIC : HIR)),
			who->query_skill(skill[i]));
	}
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : enable2 <id>

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�� ? ���г�
������ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}
