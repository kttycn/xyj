#include <ansi.h>
#define SCORE_COST 50000
#define GOLD_COST 20
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title;	
	string *dir;
	int i;
	seteuid(getuid());
	if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
		return notify_fail("ָ���ʽ����bang xuelianjiao ѩ���� ����\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("��Ľ�����������"+chinese_number(SCORE_COST)+"�㡣\n");
	if((int)me->query("combat_exp") < 5000000)
		return notify_fail("��ľ��鲻��"+chinese_number(5000000)+"�㡣\n");
	if((int)me->query("daoxing") < 5000000)
		return notify_fail("��ĵ��л�������ǧ�ꡣ\n");
	gold = present("gold-coin_money",me);
	if(!gold) return notify_fail("������û����Ӱ��ҡ�\n");
	if((int) gold->query_amount() < GOLD_COST)
		return notify_fail("������û��"+chinese_number(GOLD_COST)+"ö��Ӱ��ҡ�\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
		return 1;
	c_name += " ";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
		return notify_fail("���봴���İ������Ļ�Ӣ�������Ѿ�������ռ���ˣ�\n");	
	if(!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
		return notify_fail("��Ϸϵͳ�������⣡��֪ͨ������Ա��\n");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
	me->set("title",HIR+c_name+title+NOR);
	message("channel:es",
	HIM"\n\n�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n\n"HIC
		"\t\t    �� "+c_name+"��"+"�ڽ����г����ˣ�\n"HIM
	    "\n�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n"NOR,
	users() );
	return 1;
}
/*
string replace(string arg)
{
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$BLINK$", BLINK);

	newarg=arg;


	while(sscanf(newarg,"%s%*sm%s",str1,str2)==3)
		newarg=str1+str2;
	arg = arg + NOR;
	return arg;
}
*/
int help(object me)
{
    write(@HELP
�����ں����г����Լ��İ��ɣ�

ָ���ʽ: 
bang xuelianjiao ѩ���� ����

��ָ�����㴴��һ���µİ�ɣ���̡� 
������Ϊѩ���̽�����

������

bang bluedress ����¥ �ܹ�
��������¥������Ϊ����¥�ܹܡ�
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
		write("�Բ����������ֱ���������ʮ��������֡�\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("�Բ����������ֲ����ÿ�����Ԫ��\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ������ֱ��������ġ�\n");
			return 0;
		}
	}
	return 1;
}

