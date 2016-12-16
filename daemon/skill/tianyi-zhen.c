// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */


inherit SKILL;

#include <ansi.h>;

string* skill_head =({
        "[31m$N�������е�$w��һ��[m",
        "[32m$N���е�$wһ����һʽ[m",
        "[33m$Nһ�����е�$w��ʹ��[m",
        "[34m$N���е�$w�������֣�ʹ��һʽ[m",
        "[35m$N����$w��ɣ�ʹ��һ��[m",
        "[36m$N����$wһ����һʽ[m",
     });

string* skill_tail =({
        "[31m������$n��$l��[m",
        "[32m����$n��$l���̹�ȥ��[m",
        "[33m����Ȼ�ճ���һ��Բ������$n��ȫ��[m",
        "[34m������$n��Ҫ����λ��[m",
        "[35m������Ĵ̽���$n��$l[m",
        "[36m��$w��$n���ٷ�ȥ��[m",
});

mapping *action = ({
([      "action" : "$N�������е�$w��һ�С����������������$n��$l��",
        //"force" : 120,
        "dodge" : -10,
        "parry" : 5,
        "damage" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N���е�$wһ����$w����һ����Ŀ�Ĺ�â������$n��Ҫ����",
        //"force" : 130,
        "dodge" : -10,
        "parry" : 10,
        "damage" : 50,
        "damage_type" : "����"
]),
([      "action" : "$N����һ������$w���ͼ�$w��$n���̹�ȥ��",
        //"force" : 140,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 55,
        "damage_type" : "����"
]),
([      "action" : "$N���е�$w�������֣�ͻȻ�ͼ�$w��$n��Ҫ����ȥ��",
        //"force" : 160,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 60,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����$w�ƺ���ǧ���أ�ֱ��$nѹ�¡�",
        //"force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��СС��$w��Ȼ�ճ���һ��Բ������$n��ȫ��",
        //"force" : 210,
        "dodge" : -15,
        "parry" : 15,
        "damage" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N����$wһ����$n��ʱ�����Ի󲻽⣬ͬʱ�ͼ�$w�Ѿ�������$n��$l��",
        //"force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 70,
        "damage_type" : "����"
]),
([      "action" : "$N���һ����$w��ɣ�ֻ��$n��$l��Ҫ��$w�̵���",
        //"force" : 280,
        "dodge" : -20,
        "parry" : 10,
        "damage" : 60,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "needle") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("xuanhu-xinfa", 1) < 20)
                return notify_fail("��������ķ����̫ǳ��\n");
        if ((int)me->query_skill("fox-hand", 1) < 20)
                return notify_fail("��ĺ��ֻ��̫ǳ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_tianyi-zhen");
     if(me->query("skill_tianyi-zhen")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];

}

int practice_skill(object me)
{
	object ob;

	if(!objectp(ob=me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "needle")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("��������������������롣\n");
	me->receive_damage("kee", 30);
	return 1;
}
string perform_action_file(string action)
{
	return CLASS_D("xuanyuan")+"/tianyi-zhen/"+action;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����������롣\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����������롣\n");
	return 1;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("tianyi-zhen",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��������������������ˣ�����������������һ���µľ��磡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����������������һ���µ��÷���\n"NOR);
      tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_tianyi-zhen");
   if(!pointerp(m_actions))m_actions=({});
   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="�����������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+arg+"��"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_tianyi-zhen",m_actions);
}
