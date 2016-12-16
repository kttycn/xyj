// CMDS USR top.c
// Created by kittt@����Ц
// Last modified by kittt@DJX 4/13/2000
// ���ڸ���Ҳ鿴������ҵĸ������С�MUD_NAME�������ͼ�ζԲ���
// ���Լ��ĸ�����������score��Ȼ���԰��Լ����뷨�޸ġ�

#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
	
	object *list,*ob;
	int i;
	string msg;

	ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
	list = sort_array(ob, (: top_list :));
	msg =  "\n              �� "+BCYN HIW+CHINESE_MUD_NAME+"���߸������а�"NOR" ��\n";
	msg += "���������ө����ߩ��������������ө��������ߩ��ө���������\n";
	msg += "�� ���� ��    ��        ��    ��  ��    ��  ���ۺ����۩�\n";
	msg += "�ĩ������ة��������������������ة������������ة���������\n";
	for (i = 0 ;i < 10 ; i++) {
		if( i >= sizeof(list)) msg += "����ʱ��ȱ������    ������������������������������������\n";
		else {
			if( !list[i] ) continue;
			if( !list[i]->query("id") ) continue;
			if(list[i] == me) msg += BBLU HIY;
			msg += sprintf("��  %-5s %-22s%-14s %5d  ��\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
			list[i]->query("id")+")",
			list[i]->query("family")?list[i]->query("family/family_name"):"��ͨ����",
			get_score(list[i]));
		}
	}
	msg += "��������������������������������������������������������\n";
	msg += "  " + NATURE_D->game_time() + "�ǡ�\n";
	write(msg);
	return 1;

}
int top_list(object ob1, object ob2)
{
	int score1,score2;

	score1 = get_score(ob1);
	score2 = get_score(ob2);

	return score2 - score1;
}

int get_score(object ob)
{
	int tlvl,i,score;
	string *ski;
	mapping skills;

    reset_eval_cost();
	skills = ob->query_skills();
	if (!sizeof(skills)) return 1; 
	ski  = keys(skills);
	for(i = 0; i<sizeof(ski); i++) {
		tlvl += skills[ski[i]];
	}  // count total skill levels
 	score = tlvl/10;
	score += ob->query("max_force")/10;
	score += ob->query_str() + ob->query_int() + ob->query_spi() + ob->query_con();
	score += (int)ob->query("combat_exp")/2500;
	score += (int)ob->query("daoxing")/2500;

	return score;
}

int help(object me)
{
write(@HELP
ָ���ʽ : top 
 
���ָ���������֪������ʮ���������Щ����ȥ�����ǡ� 
 
HELP
    );
    return 1;
}
 
