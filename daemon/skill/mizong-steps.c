// mizong-steps �����ٲ���

/*
���ٲ�
Ʈ���޶�Ϊ��ɫ��˲��֮�������ʧ�����֮�䣬��Ӱ���١�
*/

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n����һ�ݣ�ʹ��"HIR"��Ʈ��������"NOR"���ܿ�����һ�С�\n",
	"$N��һ����$nʹ��"HIC"�����Ƹ�����"NOR"һ�����$Nͷ��Խ����\n",
	"$nһ�����ã�һ��"HIW"��׷�Ǹ��¡�"NOR"�������������Ӱ�Ӷ�û�ˡ�\n",
	"$n����һ�㣬һ��"HIM"��������ء�"NOR"�ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ��"HIY"����Ӱ���١�"NOR"����������Ʈ�˿�ȥ��\n",
	"����$n�ظ�����һ�����ڼ䲻�ݷ�֮��һ��������������ø�"HIB"����ת��ء�"NOR"��\n",
	"ֻ��$nһ����Х������һ�ɼ��磬�������ڷ����\n$N�Ĺ�����ʧ��׼ͷ�����ǡ����ٲ����е�"HIG"����̤���硹"NOR"��\n"
});

int valid_enable(string usage)
{
	return usage=="dodge";
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취�����ٲ���\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("��������������������������ٲ���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60)
		return notify_fail("�����ڽ����鸡������Ϣһ��ɡ�\n");
	if( (int)me->query("sen") < 60)
		return notify_fail("��ľ����޷������ˣ���Ϣһ���ٽ��в���ɡ�\n");
	if((int)me->query("force") < 6 )
		return notify_fail("�������������������Լ���������ȥ�ˡ�\n");
	me->receive_damage("kee", 60);
	me->add("force", -6);
	return 1;
}
