//Cracked by Roath

#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	int gin_cost;	
	int my_skill;
	int pot;
	int amount;
        if( me->is_fighting() )
                return notify_fail("��ս���и��о���\n");
	if(!arg) return notify_fail("ָ���ʽ: research <����>\n");
	if( !(int)my_skill=me->query_skill(arg,1) )
                return notify_fail("��Դ����һ����֪����θ��о���\n");
                                                                                
        if( !SKILL_D(arg)->valid_learn(me) ) return 0;
//	if( !SKILL_D(arg)->valid_research(me) ) return 0;

	pot = (int)me->query("potential") - (int) me->query("learned_points");
        gin_cost = 10000 * 3 / ((int)me->query_int()*(int)me->query_kar());
	if((int)me->query("gin") < gin_cost)
	{
	me->set("gin",0);
	return notify_fail("������̫���ˣ����ʲôҲû���о�������\n");
	}
	amount = (my_skill - 75) * SKILL_D(arg)->black_white_ness()/100;
	amount += SKILL_D(arg)->learn_bonus() +
		  (int)me->query_int() * (int)me->query_int() +
		  to_int(pow(to_float((int)me->query("combat_exp")),0.3));
	amount = pot/10*(amount/100 + random(amount/100));
	me->add("learned_points",pot);
        me->receive_damage("gin", gin_cost );
	me->research_skill(arg,amount);
	write("���"+to_chinese(arg)+"����һ�����׵��о���\n");
        return 1;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: research <����>

��һָ�����������е�Ǳ�ܶ�ĳ�����������о���
HELP
   );
   return 1;
}

