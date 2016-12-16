// zhuanhuan.c

#include <skill.h>
#include <combat.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int amount, daoxing;

	seteuid(getuid());

	if( me->is_fighting() )
		return notify_fail("ս���в�����ת��Ǳ�ܣ����߻���ħ��\n");

	if( !arg || !sscanf(arg, "%d", amount) )
		amount=50;

	if( amount < 1 ) return notify_fail("������Ҫת�� 1 ��Ǳ�ܡ�\n");

	if( (int)(me->query("potential")-me->query("learned_points")) < amount )
		return notify_fail("��û����ô���Ǳ����ת�ơ�\n");

	if( (int)me->query("kee") < amount)
		return notify_fail("�����ھ���̫���ˣ��޷�����רһ����ת��ɣ�\n");

	me->receive_damage("kee", amount);
        daoxing = (amount*3)/2;
	me->add("potential",-amount);
	me->add("daoxing", daoxing );

	write("�ϣˣ����" + amount + "��Ǳ��ת��Ϊ" + COMBAT_D->chinese_daoxing(daoxing) + "���У�\n");
	log_file("cmds/zhuanhuan", sprintf("%s(%s) �� %s Ǳ��ת���� %s ���� ʱ�� %s\n",
		me->query("name"),me->query("id"),chinese_number(amount),chinese_number(daoxing),ctime(time())));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : zhuanhuan [<�ķѡ�Ǳ�ܡ�������Ԥ��ֵ 30>]

���������԰����Ǳ�ܻ�Ϊ���С�
HELP
	);
	return 1;
}
 
