// jueqing-bian.c
// �����鳤����
// Juney: 07/04/97: Genesis.
/*�����鳤��Ϊ�׾�������������������˿�����������ֱ������������
*/
//��Ͷ���չ���� ͻ����������� ����ĺĺƵ˼�� ǧ��濾�ֻ�ǿ�
//������������� ȴ���칫������ �����޶���˼�� �˺������޾���
//��Ȼ���������� Ը�˳��ÿ��ź� ����δ���ɰ�ͷ ����������ǰԵ
//���鲻�Ƽ��Ƹ� �����칫������ �ճ��˻�����ʱ ��������鳤�� 

inherit SKILL;
#include <ansi.h>
mapping *action =
({
	([
		"skill_name" : "��Ͷ���չ����",
		"action":     "$Nʹһʽ"HIC"����Ͷ���չ���ա�"NOR"����¶΢Ц������$wһ��������
����������$n��$l",
		"dodge":   10,
		"parry" : 0,
		"force": 30,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "ͻ�����������",
		"action":     "$Nʹһʽ"HIC"��ͻ�������������"NOR"���������������ж��䣬����$w
��һ�����벻���ķ�λбб����$n��$l",
		"dodge":   15,
        "parry" : 10,
        "force": 40,
		"damage_type":  "����"
	]),
   ([
		"skill_name" : "����ĺĺƵ˼��",
		"action": "$Nʹһʽ"HIC"������ĺĺƵ˼�䡻"NOR"���������ߣ����׸���Ƭ�̣���
������$w��Ȼ���ϣ�����$n��$l",
		"dodge":   -10,
		"parry" : 10,
        "force": 50,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "ǧ��濾�ֻ�ǿ�",
		"action": "$Nʹһʽ"HIC"��ǧ��濾�ֻ�ǿա�"NOR"������һ�Σ����Ӷ��ϣ�����$w
����һ������׼$n��$l��������",
		"dodge":   10,
		"parry" : -10,
		"force": 35,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "�������������",
		"action": "$Nʹһʽ"HIC"��������������须"NOR"��һ����������$n����Ӱ���棬
����$w���Ȼ��������$n��$l��ȥ",
		"dodge":   20,
        "parry" : -15,
        "force": 70,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "ȴ���칫������",
		"action": "$Nʹһʽ"+HIC"��ȴ���칫��������"NOR+"��һ����������$w����б����
��ֱָ$n��$l",
		"dodge":   0,
        "parry" : 10,
        "force": 55,
		"damage_type":  "����"
	]),
	(["skill_name" : "�����޶���˼��",
	"action": "$Nʹһʽ"+HIC"�������޶���˼�ࡻ"NOR+"��΢΢һ��ת������$wȴ����
���´���������$n��$l",
		"dodge":  -10,
        "parry" : 10,
        "force": 30,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "�˺������޾���",
		"action": "$Nʹһʽ"+HIC"���˺������޾��ڡ�"NOR+"����ɫ΢�䣬���ж�Ȼ���������
�ȣ�����$w��ƥ��������$n��$l",
		"dodge":  10,
        "parry" : 10,
        "force": 60,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "Ը�˳��ÿ��ź�",
		"action": "$Nʹһʽ"+HIC"��Ը�˳��ÿ��źޡ�"NOR+"�������Ծ������$w�ڰ�������£�
����һ����ɫ��������$n��$l",
		"dodge":   30,
        "parry" : 10,
        "force": 50,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "����δ���ɰ�ͷ",
		"action": "$Nʹһʽ"+HIC"������δ���ɰ�ͷ��"NOR+"������ಽ������$w���ּ���������
��ৡ���һ����$n��$l��ȥ",
		"dodge":   65,
        "parry" : 10,
        "force": 60,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "����������ǰԵ",
		"action": "$Nʹһʽ"+HIC"������������ǰԵ��"NOR+"����ؼ���һ�����ֳ�ǰ����������
$w��Ϊ�⻡��$n��$l��ȥ",
		"dodge":   40,
        "parry" : 10,
        "force": 40,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "���鲻�Ƽ��Ƹ�",
		"action": "$Nʹһʽ"+HIC"�����鲻�Ƽ��Ƹ֡�"NOR+"������Ծ�𣬲�����Ӱ������ȴ�ִ�
����д��£�˫������$w�����Ʊ��˵ش���$n��$l",
		"dodge":   60,
        "parry" : 10,
        "force": 90,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "�����칫������",
		"action":     "$Nʹһʽ"+HIC"�������칫�����ۡ�"NOR+"������$w���͡���һ��б������գ�
�漴���¡��ৡ����£�����һ�����֣���$n��$l��ȥ",
		"dodge":   45,
        "parry" : 10,
        "force": 40,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "�ճ��˻�����ʱ",
		"action": "$Nʹһʽ"+HIC"���ճ��˻�����ʱ��"NOR+"������΢̧������$w���·�����
����һ�ɾ��練��$n��$l",
		"dodge":   50,
        "parry" : 10,
        "force": 40,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "��������鳤��",
		"action": "$N�㾡ȫ�����"+HIC"����������鳤����"NOR+"����ɫʮ�ּ�������������
����������$w���費ͣ��ȫ�������������˵Ľ����У�$n���ɺ�Ȼ��ֻ��$N
����΢�䣬�����������ѱ���$n��$l",
		"dodge":   70,
        "parry" : 10,
        "force": 50,
		"damage_type":  "����"
	]),
	([
		"skill_name" : "��Ȼ����������",
		"action": "$Nʹһʽ"+HIC"����Ȼ���������桻"NOR+"���������ף�����̾�˿���������
Ө����������������$w�й�ֱ����Ѹ���ޱȵ���$n��$l��ȥ",
		"dodge":  20,
        "parry" : 10,
        "force": 120,
		"damage_type":  "����"
	])
});

int valid_enable(string usage) {
    return usage == "sword" || usage == "parry";
}

int valid_learn(object me)
{
	object ob;

	if (me->query("gender") != "Ů��")
		return notify_fail("ֻ��Ů�Բ������򵽳����鳤���������裡\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("���������Ϊ������޷�ѧϰ�����鳤������\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ����������ϰ�����鳤������\n");
	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
		return notify_fail("��ľ����ķ�Ϊ��ǳ��û��ѧ�����鳤����\n");
	if ((int)me->query_skill("yueying-wubu", 1) < 20)
		return notify_fail("�����Ӱ�貽��Ϊ��ǳ��û��ѧ�����鳤����\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query_temp("CXJ_perform");
	if( !me->query_temp("CXJ_perform")) {
		return action[random(sizeof(action)-1)];
	}else {
		return action[i];
	}
}

int practice_skill(object me)
{
    object weapon;
    if (me->query("gender") != "Ů��")
		return notify_fail("ֻ��Ů�Բ���ѧ������鳤����\n");
    if (!objectp(weapon = me->query_temp("weapon")) ||
	(string)(weapon->query("skill_type")) != "sword")
	return notify_fail("�������������û������ô�������鳤������ :)\n");
	if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("�����鳤�������������˿���ľ����ķ���������\n");
    if ((int)(me->query("kee")) < 50)
	return notify_fail("���Ѿ���ƣ���ߣ�û��������ȥ����\n");
	if ((int)me->query("force") < 15)
		return notify_fail("���������㣬ǿ�������鳤�������߻���ħ��Σ�ա�\n");
    me->receive_damage("kee", 30);
	me->add("force", -15);
	message_vision(HIM"���ճ��˻�����ʱ,��������鳤����"NOR"$N��������һ������鳤����\n", me);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������鳤����\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������鳤����\n");
	return 1;
}

void skill_improved(object me)
{
	if( (int)me->query_skill("chixin-jian", 1)  % 10 == 0 )
	{
		tell_object(me,RED "\n��ͻȻ������ͷһ�󷳶�ֻ������ɱ��....\n\n" NOR);
		me->add("bellicosity", 50);
	}
}

string perform_action_file(string action)
{
        return CLASS_D("pansi") + "/chixin-jian/" + action;
}
