int valid_learn(object me)
{
//line number must be same!!!
//so it is done
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������̫�����޷���"+SKILL_CH_NAME+"��\n");
	return 1;
}
int valid_enable(string usage) { return usage== SKILL_BASE_NAME || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
} //total 34 lines!
