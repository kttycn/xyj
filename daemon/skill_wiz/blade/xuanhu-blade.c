//�������޵�
// dodge -10   parry -5   damage 25
inherit SKILL;
#include <ansi.h>;

mapping *action = ({
	([      "name":     "���������������У��������տ�������",
     "action":   "$Nһʽ"+HIR"���������������У��������տ�������"NOR+"����̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���
�Ե�����������$w������Ϣ�ش���$n��$l",
     "dodge":   -10,
     "parry":   -10,
     "damage":   120,
     "damage_tupe":   "����",
     "parry_msg":   "$Nһʽ���������������У��������տ�����������̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���",
     "parry_power":   10,
   ]),
   ([   "name":     "���ٳ��ӹĳ���ҹ�������Ǻ������졹",
     "action":   "$Nһʽ"+HIB"���ٳ��ӹĳ���ҹ�������Ǻ������졹"NOR+"����ռ������λ��
����$w����һ������, �����ӵ�к�����$n$l",
     "dodge":   -5,
     "parry":   -5,
     "damage":   45,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ���ٳ��ӹĳ���ҹ�������Ǻ������졹����ռ������λ��
����$w����һ������, �Ŀ�$n�Ĺ���",
     "parry_power":   20,
   ]),
   ([   "name":     "����������»�Ȫ������ãã�Բ�����",
     "action":       "$Nһʽ"+HIY"����������»�Ȫ������ãã�Բ�����"NOR+"��������λ��
����$w��Ϊ���쵶Ӱ��������������������$nȫ�����",
     "dodge":    0,
     "parry":   -10,
     "damage":   55,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ����������»�Ȫ������ãã�Բ�������������λ��
����$w��Ϊ���쵶Ӱ������������������ס$Nȫ�����",
     "parry_power":20,
   ]),
   ([   "name":     "��¥���������������д�Լ�����ӡ�",
     "action":   "$Nһʽ"+HIC"��¥���������������д�Լ�����ӡ�"NOR+"����$n������ת��
��ΪһȦ��Ӱ���ڡ��ޡ�λͻ��һ������̩ɽѹ��֮ʽ����$n$l",
     "dodge":   -15,
     "parry":   -10,
     "damage":   40,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ��¥���������������д�Լ�����ӡ�����$n������ת��
��ΪһȦ��Ӱ���㿪$n�Ĺ���",
     "parry_power":   10,
   ]),
   ([   "name":     "���紵����ƮƮ�٣��������������衹",
     "action":   "$Nһʽ"+HIW"���紵����ƮƮ�٣��������������衹"NOR+"�����弱����ת��
�ڡ��롹λ��һ�����磬����$w৵ؿ���$n��$l",
     "dodge":    5,
     "parry":   -10,
     "damage":   45,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ���紵����ƮƮ�٣��������������衹�����弱����ת��
�ڡ��롹λ��һ�����磬��ȥ$n�Ĺ���",
     "parry_power":   20,
   ]),
   ([   "name":     "�����ݼ�į�����ɣ��滨һ֦�����꡹",
     "action":   "$Nһʽ"+HIM"�����ݼ�į�����ɣ��滨һ֦�����꡹"NOR+"��ռס���ҡ�λ��
������$w��������ǹ⣬����$nȫ��",
     "dodge":   -20,
     "parry":   -10,
     "damage":   60,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ�����ݼ�į�����ɣ��滨һ֦�����꡹��ռס���ҡ�λ��
������$w��������ǹ⣬����$n��$l����ȥ$n�Ĺ���",
     "power_power":  20,
   ]),
   ([   "name":     "������Ը���������ڵ�ԸΪ����֦��",
     "action":   "$Nһʽ"+HIG"������Ը���������ڵ�ԸΪ����֦��"NOR+"����̤��Ǭ����������λ��
����$w������������$n��$l��ȥ",
     "dodge":    0,
     "parry":   -10,
     "damage":   50,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ������Ը���������ڵ�ԸΪ����֦������̤��Ǭ����������λ��
��$n�Ĺ��������˳�ȥ",
     "parry_power":  20,
   ]),
   ([   "name":     "���쳤�ؾ���ʱ�����˺������޾��ڡ�",
     "action":   "$Nһʽ"+HIW"���쳤�ؾ���ʱ�����˺������޾��ڡ�"NOR+"���ɡ�������Ǭ�����ˣ�
����$w����һ��������$n$l��ȥ",
     "dodge":   -25,
     "parry":   -10,
     "damage":   60,
     "damage_type":   "����",
     "parry_msg":   "$Nһʽ���쳤�ؾ���ʱ�����˺������޾��ڡ����ɡ�������Ǭ�����ˣ�
����$w����һ�����絴����$n�ķ�â",
     "parry_power":   20,
   ]),
});
int valid_learn(object me)
{
	object ob;

	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�������޵�ֻ��Ů�Բ���ѧϰ��\n");

	if( (int)me->query("max_force") < 200 )
		return notify_fail("�������������û�а취ѧ�������޵�����\n");

	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ�����ѧ�������޵�����\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�������޵�ֻ��Ů�Բ�������\n");

	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("kee") < 10 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 10);
	me->add("force", -5);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����������޵���\n");
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("�������޵�ֻ�ʺ�Ů��������\n");

	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����������޵���\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("xuanyuan") + "/xuanhu-blade/"+action;
}
