// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;
int check_valid_create(string arg);

int main(object me, string arg)
{
	int skill, amount, qskill, qlearned, upper;

	seteuid(getuid());

//	if( !environment(me)->query("canwu") )
//		return notify_fail("���ﲻ�ǲ���ĵط���\n");

	if( !arg )
		return notify_fail("��Ҫ����ʲô��(apperception <��������>)\n");

	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	skill = me->query_skill(arg, 1);

	if(!check_valid_create(arg) && !me->query("guild") )
	{
		return notify_fail("�ⲻ���㴴���Ĺ���ѽ��\n");
	}
	if( me->is_busy() )
		return notify_fail("�����ں�æ��������ϰ��\n");

	if( !arg ) return (__DIR__"skills")->main(me, arg);

	if( skill < 1 )
		return notify_fail("Ϲ����ʲôѽ������ⷽ��ļ��ܻ���һ�ϲ�ͨ�أ�\n");

	if(skill<250)
		return notify_fail(CYN"��ԡ�"+to_chinese(arg)+"������⻹������������򵽸����εĶ�����\n"NOR);

	if( (string)SKILL_D(arg)->type()=="martial" && 
	skill*skill*skill/10 > (int)me->query("combat_exp") )
		return notify_fail("�����ѧ��Ϊ��û��������磬������ٶ�Ҳû�á�\n");
	else if( (string)SKILL_D(arg)->type()=="magic" && 
	skill*skill*skill/10 > (int)me->query("daoxing") )
		return notify_fail("��ĵ�����Ϊ��û��������磬������ٶ�Ҳû�á�\n");

	upper= (int)me->query("potential")-(int)me->query("learned_points");
	if(upper<10)
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ټ������в�����ѧ�ˡ�\n");

	if(MISC_D->random_capture(me,20000,0)) return 1;

	if(!skill) {
		qskill=1; qlearned=0; amount=0;
	} else {
		qskill=me->query_skills()[skill]+1;
		qskill*=qskill;
		qlearned=me->query_learned()[skill];
		amount = qlearned;
	}
	amount += random(me->query_int())+1;
	amount -= qlearned;

	notify_fail("�����Ų���" + to_chinese(arg) + "�����ǲ�û���κν�����\n");

        //added by mon. 7/24/97
	if( SKILL_D(arg)->apperception_skill(me) ) {
		me->improve_skill(arg, amount,(qlearned<2*qskill) ?0:1);
		me->add("learned_points", 10);
		write( HIY "���" + to_chinese(arg) + "�����ˣ�\n" NOR);
		me->start_busy(1);
		return 1;
	}
	else return 0;
}

int check_valid_create(string arg)
{
	string file,*list,playername;
	object me;

	me=this_player();
	file=read_file(SKILL_D(arg+".c"));
	if(!file) 
		return 0;
	list = explode(file, "\n");
	playername=geteuid(me);

	if(list[0]=="// ��������Դ��书���� ԭ��maxim@nju_fengxue��д������swallow@xjqy�޸�")
	{
		if(list[1]=="// "+playername) return 1;
		else return 0;
	}
	return 1;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��apperception|canwu <��������>

���ָ���������ĳ������ļ��ܣ�������ܵĵȼ�������250�����ϡ�����
���Ѿ��������ɳ�Ϊһ��������

��������ļ����㹻�ߣ����Ծ��ɲ�����ֱ��������ÿ����һ�β������10
��Ǳ�ܡ���������������ֻ�����ʵ�������л���㹻�ľ����йء�
TEXT
	);
	return 1;
}
