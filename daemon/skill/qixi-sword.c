//by night

#include <ansi.h>
 
inherit SKILL;

string* skill_head =({
        "$Nʹһ��",
        "$N���е�$wһ��",
        "$N�趯$w��һ��",
        "$Nһ������$w��ʹ��",
        "$N����$w������ɢ��һ��",
        "$N΢΢���ף���˼���У�һ��",
        "$N����$wббָ��������",
        "$N��̾һ����Ʈ��󳷣�ü���۽���������$n��Ҫ׷����$N��Ȼʹ��һ\n��",  
        "$N��$wһ����ʹ��һ��",
        "$N���н�Ʈ��������һ��",
        "$N���һ�������潣�ƣ��ڿ���������һ��",                               
});
string* skill_tail =({
        "������$w����㴺������$n��$l�������㣬����\n�������$n����������һ�е�����",
        "������ɻ������������·��޾��������޿�\n����ش���$n��$l",
        "��������ǣ��������磬�˽���һ����Ϊһ��\n�������ٰ�����⣬����$n��$l",
        "������Ԧ�������Ʋ������������ָ��\n$n��$l��$n��������$w�����ƣ����任��������λ��ȴ���㲻��$N��������",
        "���������ƣ�����һ�������·��廨\n��������޶�����$n��$l��Χ���ش���$n�ۻ����ң���֪����εֵ�",
        "��$w�ó�������⣬�೤���Σ���\n�����档$nһʱ�䲻֪���Լ��������л�������ʵ���������˹�ȥ",
        "����ʱ��������˸��$w������㷱\n�ǣ�ҫĿ���ԡ�$nֻ���Լ�����һƬ�����Ĺ���У����۽������⽻���ݺ�",
        "������$w��������⻪����ָ$n��$l",
        "��������������$nȫ��������ס",
        "�����н����������ش���$n���ȵ�$n���ò������Ի�",
        "�����н���â������������Զ������������$n�ı���",
});
 
mapping *action = ({
        ([      "name":                 "����է��",
                "action":               "$Nʹһ�С�����է�𡹣�����$w����㴺������$n��$l�������㣬����\n"
"�������$n����������һ�е�����", 
    "dodge":     -10,
     "parry":      0,
     "damage":     30,
     "damage_type":     "����"
   ]),
        ([      "name":                 "ϸ������",
                "action":               "$N���е�$wһ�С�ϸ�����ࡹ������ɻ������������·��޾��������޿�\n"
"����ش���$n��$l", 
     "dodge":     -5,
     "parry":      0,
     "damage":     25,
     "damage_type":     "����"
   ]),
        ([      "name":                 "���Ǵ���",
                "action":               "$N�趯$w��һ�С����Ǵ��ޡ���������ǣ��������磬�˽���һ����Ϊһ��\n"
"�������ٰ�����⣬����$n��$l", 
     "dodge":     -10,
     "parry":     -5,
     "damage":     35,
     "damage_type":     "����"
   ]),
        ([      "name":                 "������ˮ",
                "action":               "$Nһ������$w��ʹ����������ˮ��������Ԧ�������Ʋ������������ָ��\n"
"$n��$l��$n��������$w�����ƣ����任��������λ��ȴ���㲻��$N��������", 
     "dodge":     10,
     "parry":     -20,
     "damage":     35,
     "damage_type":     "����"
        ]),
        ([      "name":                 "����Ū��",
                "action":               "$N����$w������ɢ��һ�С�����Ū�ɡ����������ƣ�����һ�������·��廨\n"
"��������޶�����$n��$l��Χ���ش���$n�ۻ����ң���֪����εֵ�", 
     "dodge":     -15,
     "parry":     -20,
     "damage":     30,
     "damage_type":     "����"
        ]),
        ([      "name":                 "��������",
                "action":               "$N΢΢���ף���˼���У�һ�С��������Ρ���$w�ó�������⣬�೤���Σ���\n"
"�����档$nһʱ�䲻֪���Լ��������л�������ʵ���������˹�ȥ", 
     "dodge":     -10,
     "parry":      0,
     "damage":     35,
     "damage_type":     "����"
        ]), 
        ([      "name":                 "��������",
                "action":               "$N����$wббָ�������ݡ���������������ʱ��������˸��$w������㷱\n"
"�ǣ�ҫĿ���ԡ�$nֻ���Լ�����һƬ�����Ĺ���У����۽������⽻���ݺ�",
     "dodge":     0,
     "parry":     -10,
     "damage":     40,
     "damage_type":     "����"
        ]), 
        ([      "name":                 "ȵ�Ź�·",
                "action":               "$N��̾һ����Ʈ��󳷣�ü���۽���������$n��Ҫ׷����$N��Ȼʹ��һ\n"
"�С�"+HIG"ȵ�Ź�·"NOR+"��������$w��������⻪����ָ$n��$l",
     "dodge":     0,
     "parry":     5,
     "damage":     this_player()->query("sword")/8+10,
     "damage_type":     "����"
        ]),
});
int valid_learn(object me)
{
   object ob;

   if( (string)me->query("gender") != "Ů��" )
     return notify_fail("��Ϧ������ֻ��Ů�Ӳ��������书��\n");
      if (me->query("family/master_name") !="ˮĸ����")
      return notify_fail("�㲻��ˮĸ����ĵ��ӣ��޷�����Ϧ������ :)\n");
   if( (int)me->query("max_force") < 50 )
     return notify_fail("���������Ϊ�������Ϧ����ѧ��Ҳû�á�\n");
   if (!(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ����������ϰ������\n");
   return 1;
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("qixi-sword");

   if (dod<swo/2)
     return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
   if ((int)me->query("kee") < 30)
     return notify_fail("���������㣬ǿ����Ϧ�����к����档\n");
   if ((int)me->query("force") < 5)
     return notify_fail("���������㣬��������Ϧ������\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$N��ü��򭣬����΢��������һ����Ϧ������\n", me);
   return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취������Ϧ������\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ������Ϧ������\n");
	return 1;
}

string *parry_msg = ({
        "$n���ƹ��У��ҽ�����һ�С��麣���ġ������н��ݺݿĿ���$N��$w��\n",
        "$n������������ס$N��$w��һ�С�����ĺĺ����ʹ$N���԰ѳ����е�$w��\n",
        "$nʹ��һ�С���ѩ�����������н���������ѩӰ���գ�������$N��$w��\n",
        "$nʹ��һ�С������¶���������๥����ʹ$N��֪�ǹ����ء�\n",
        "$nһ�С�ĺѩ��̾�������н����������ش���$N���ȵ�$N���ò������Ի���\n",
        "$n���н�Ʈ��������һ�С��ɷ���𽡹�������벻���ĽǶȼ�ס��$N���е�$w��\n",
        "$n�����н�����$N�Ų����ģ�һ�С�������Ե����ס��$N�Ĺ��ơ�\n",
        "$nʹ��һ�С����鲻ʶ�������н���â������������Զ������������$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$nʹ��һ�С������¶���������๥����ʹ$N��֪�ǹ����ء�\n",
        "$n����һ����ʹ��һ�С��������á���������������$Nȫ��������ס��\n",   
        "$n�����н����������������ȵ�$N�������ˡ�\n",
        "$n���һ�������潣�ƣ��ڿ���������һ�С�ȵ����᡹����ʧ����Ӱ���١�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
   mapping* m_actions;

   if(me->query("skill_qixi")==0) return action[random(sizeof(action))];
   if(random(6)>1) return action[random(sizeof(action))];
   
   m_actions=me->query("skill_qixi");
   return m_actions[random(sizeof(m_actions))];
}

string perform_action_file(string func)
{
return CLASS_D("xuyi") + "/qixi-sword/" + func;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qixi-sword",1);

   if(m_skill>200&&m_skill%20==0){
     tell_object(me,HIY"�����Ϧ��������������ˣ������Ϧ����������һ���µľ��磡\n"NOR);
     if(me->query("qixi/times")>2){
        tell_object(me,HIW"Ȼ�������Ϧ�����Ѿ��������壬�����ٴ��������ˡ�\n"NOR);
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
     tell_object(me,HIW"��ͻȻ�������飬���������Ϧ�����µ��÷���\n"NOR);
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

   m_actions=me->query("skill_qixi");
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
   me->set("skill_qixi",m_actions);
   me->add("qixi/times",1);
}

