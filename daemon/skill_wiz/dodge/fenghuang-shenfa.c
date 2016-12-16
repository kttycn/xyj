#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$nһʽ���ɻ�չ�᡹��ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
	"$nһʽ�������Ӳ�����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
	"$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
	"$nһʽ����۵糸����˫�ŵ�أ�ȫ��һ�����磬��������$N�ɱ���\n",
	"$nһʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
	"$nһʽ������˫�ɡ��������������������ݷ����У���$Nͷ����Ծ������\n",
	"$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
	"$nһʽ���ɷ�鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
	"$n��Ȼʹ�����������֮����������Ӱ�����������������ʧ����Ӱ����!\n",
});

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 40 )
		return notify_fail("�������̫���ˣ������������\n");
	me->receive_damage("kee", 30);
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
