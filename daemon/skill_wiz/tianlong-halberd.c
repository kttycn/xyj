// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */
 
//������ꪡ�tianlong-halberd.c
inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$Nʹһ��",
        "$Nʹ������ꪷ��е�",
        "ֻ��$N����$wһʽ",
        "$N���һ����һ��",
        "$N��$w��㣬��ؽ�������һ��",
        "$N����$wһ�ݣ��������°���ת��һ��",
        "$N�����е�$w����ܲ�͸�磬һ��",                      
});

string* skill_tail =({
        "������$wһ������������ǹͷ��ֱ��$n��$l",
        "������$w�ζ��������ǹ��ͻȻ��Ӱ��һꪴ���$n��$l",
        "����ǰ�ʹܣ�����$w����һꪣ�ֱ��$n��$l",
        "������$wǹͷ�Ҷ�������ǵ�ɱ�������в���$n��$l",
        "����$n���벻���ĵط�����$n��$l",
        "�����ֶ�׼$n$l��ȥ",
        "���ȵ�$N��������",
});

mapping *action = ({
        ([      "action":               
"$Nʹһ�С���Գ��Ρ�������$wһ������������ǹͷ��ֱ��$n��$l",
                "dodge":                15,
                "parry":                -10,
                "damage" :              15,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ������ꪷ��еġ���������������$w�ζ��������ǹ��ͻȻ��Ӱ��һꪴ���$n��$l",
                "dodge":                10,
                "parry":                0,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������β������ǰ�ʹܣ�����$w����һꪣ�ֱ��$n��$l",
                "dodge":                20,
                "parry":                -5,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһʽ�������пա�������$wǹͷ�Ҷ�������ǵ�ɱ�������в���$n��$l",
                "damage":                15,
                "dodge":                10,
                "parry":                10,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��㣬��ؽ�������һ�С������ۡ�����$n��$l",
                "dodge":                15,
                "parry":                -30,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$wһ�ݣ��������°���ת��һ��"HIG"��һ��ع⡹"NOR"���ֶ�׼$n$l��ȥ",
                "dodge":                0,
                "parry":                -10,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������$wӭ��һ�����ó���ǧ��Ӱ������������$w��׼$n�ʹ��˹�ȥ����һ��Ҫ��
���У����������޽���Ҳ����һ����",
                "dodge":                10,
                "parry":                0,
                "damage":               60,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취������ꪷ���\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "halberd" )
                return notify_fail("���������һ��ꪲ�����ꪷ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="halberd" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	mapping* m_actions;
	i=me->query_temp("TLJ_perform");
	if( !me->query_temp("TLJ_perform")) {
		if(me->query("skill_tianlong")==0) return action[random(sizeof(action))];
		if(random(7)>1) return action[random(sizeof(action))];
		m_actions=me->query("skill_tianlong");
		return m_actions[random(sizeof(m_actions))];
   }else {
		return action[i];
   }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�����������������û�а취��ϰ����ꪷ���\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ������ꪷ���\n");
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������ꪷ���\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������ꪷ���\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("xuyi") + "/tianlong-halberd/" + action;
}
 
int effective_level() { return 10;}

string *parry_msg = ({
        "$nʹ��һ�С��������ơ���������$N��$w��\n",
        "$nʹ�����������衹����$N��$w�������⡣\n",
        "$n���еĻ��һ����һ�С�������;������$N��$w�������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����еĻ������ܲ�͸�磬һ�С���黴��С���ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��Ƹ����ࡹ����������ʧ��һ�Ź�â֮�С�\n",
        "$nʹ��һ�С������С���ֱ��$N��˫�֣��ȵ�$N���С�\n",
        "$n�����еĻ��һ����һ�С����Ŀճۡ����ȵ�$N�������ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("tianlong-halberd",1);

   if(m_skill>200&&m_skill%20==0){
     tell_object(me,HIY"�������ꪷ�����������ˣ��������ꪷ�������һ���µľ��磡\n"NOR);
     if(me->query("tianlong/times")>2){
        tell_object(me,HIW"Ȼ���������ꪷ��Ѿ��������壬�����ٴ��������ˡ�\n"NOR);
        return;
     }

     if(random(me->query_kar())<17){
        tell_object(me,HIW"Ȼ���������ȴ���𵭵���ʧ�䡣\n"NOR);
        return;
     }
     if((random(me->query("int")/2)+(int)me->query_skill("literate")/50)<10){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����������ꪷ��µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   string *banned_name = ({
                "��", "��", "��", "��", "��", "��", "��", "��",
                "ү", "��", "��ʦ", "����", "С��", "��Ӱ", "ҹ��", "����",
        });

   mapping* m_actions;
   mapping m_act=([]);
   int content, i=strlen(arg);
   string msg;

   m_actions=me->query("skill_tianlong");
   if(!pointerp(m_actions)) m_actions=({});

     if (!arg || arg=="") 
     {
          tell_object(me,"��Ϊ�������ʽȡһ�����֣�");
          input_to( (: call_other, __FILE__, "name_skill", me:));
          return;
     }
     else while(i--) 
     {
                if( arg[i]<=' ' ) 
                {
                        tell_object(me,"��ʽ���ֲ���ʹ�ÿ�����Ԫ���������趨һ�����֣�");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if(strsrch(arg, "��") >= 0) 
                {
                        tell_object(me,"��ʽ���ֲ����пո��������趨һ�����֣�");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) 
                {
                        tell_object(me,"�����á����ġ�Ϊ�������ʽȡ���֣�");
                        input_to( (: call_other, __FILE__, "name_skill", me:));
                        return;
                }
     }
     if( member_array(arg, banned_name)!=-1 ) 
     {
     tell_object(me,"�Բ����������ֻ���������˵����š��������趨һ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
     if( (strlen(arg) < 8) || (strlen(arg) > 16 ) ) 
     {
     tell_object(me,"�Բ�����ʽ���ֱ����� �� �� �� �������֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
     return;
     }
            
   content=(me->query("str")+me->query_skill("unarmed",1)/10)*2;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=(me->query("con")+me->query_skill("force",1)/10)*2;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   m_act+=(["name": arg ]);
   msg= skill_head[random(sizeof(skill_head))]+"��"+HIG+arg+NOR"��"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_tianlong",m_actions);
   me->add("tianlong/times",1);
}
