//Cracked by Roath

//Ansi 99.8
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ( me->query_skill("moonforce",1)     
		|| me->query_skill("ningxue-force",1)
		|| me->query_skill("lengquan-force",1)
		|| me->query_skill("zhenyuan-force",1)
		|| me->query_skill("huntian-qigong",1)
		|| me->query_skill("tonsillit",1)
		|| me->query_skill("dragonforce",1)
		|| me->query_skill("huomoforce",1)
		|| me->query_skill("wuxiangforce",1)
		|| me->query_skill("lotusforce",1)
		|| me->query_skill("zixia-shengong",1))
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����ľ�����\n");
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����ľ���\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�����ľ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("pansi") + "/jiuyin-xinjing/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������ľ���\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������ľ���\n");
	return 1;
}
