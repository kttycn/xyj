inherit SKILL;

string *dodge_msg = ({
        "$nһ�С�����˫�ɡ�����Ӱ΢�������˿�ȥ��\n",
	"$n����һ�㣬һ�С�������㡹�ڿն��𣬱��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ����Ĩ��ӡ�����������Ĵ�$Nͷ���ɹ���\n",
	"$n��Ӱ΢�����Ѿ���һ�С�����«�ޡ�����������\n",
"ֻ��$n����һ����һ�С����㰧��������$Nһ��������������Ʈ�˿�ȥ��\n",
	"$nһ�С�ĺ���Ϸɡ�����������ݳ����ߣ����˿�ȥ��\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 20 )
                return
notify_fail("�������������û�а취�����в�����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("��������������������������в�����\n");
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
