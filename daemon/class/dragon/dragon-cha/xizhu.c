#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//yudian
inherit SSERVER;
//inherit F_SSERVER

//int valid_enable(string usage) { return usage=="array"; }

//int form_array(object me)
int perform(object me, object target)
{
	object *member,ob, weapon;
	int i,j,n;
	int max,min,skill;

	member = me->query_team();
	if(me->query("family/family_name") != "��������"
	&& !me->query("guild") )
		return notify_fail("�������һ���ϵ��û�У���ôϷ�飡\n");
	if( sizeof(member) != 2 )
	return notify_fail("һ������ôϷ��\n");

	j=sizeof (member);
	for (i=0;i<j;i++)
	{
		ob=member[i];
		if (!ob||!living(ob)||!ob->is_character())
	{
		return notify_fail("�����˭һ��ʹ��˫��Ϸ�飿\n");
	}
	if (ob->query_temp("array/name"))
	{
		return notify_fail("˫�������ˡ�\n");
	}
	if (environment(me)!=environment(ob))
	{
		return notify_fail("�����������ˡ�\n");
	}
	if (!ob->query_skill("dragon-cha",1))
	{
		return notify_fail(ob->name()+"������粨���أ�\n");
	}
	if (ob->is_ghost())
	{
		return notify_fail("ֻ��������˲�������˫�����塣\n");
	}

	if( (int)ob->query("max_force") < 50 )
		return notify_fail(ob->query("name")+"������������\n");

	if( (string)ob->query_skill_mapped("force")!= "dragonforce")
		return notify_fail(ob->query("name")+"û��ʹ�������ķ���\n");

	if( !(weapon = ob->query_temp("weapon"))
	||      (string)weapon->query("skill_type") != "fork" )
		return notify_fail(ob->query("name")+"�����ðѲ���������\n");

	if( (int)ob->query_skill("dragon-cha",1)<30)
		return notify_fail(ob->query("name")+"�ķ粨�滹����������\n");

	if( (string)ob->query_skill_mapped("fork")!="dragon-cha")
		return notify_fail(ob->query("name")+"����ʹ�÷粨�档\n");
	}

//get the average array skill of the team
	n=0;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		n+=(int)ob->query_skill("dragon-cha",1);
	}
	n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
	max=member[0]->query_skill("dragon-cha",1);
	min=max;
	for (i=0;i<j;i++)
	{
		skill=member[i]->query_skill("dragon-cha",1);
		if(skill>max)
			max=skill;
		else if(skill<min)
			min=skill;
	}

//and the me is important
	n += me->query_skill("dragon-cha", 1) * 5;
	n /= max - min + 1;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->set_temp("no_quit",1);
		ob->set_temp("array/name","dragon-cha");
		ob->set_temp("array/level",n);
		ob->add_temp("apply/attack",n);
		ob->add_temp("apply/defense", n);
		ob->add_temp("apply/damage",n);
		ob->add_temp("apply/armor", n);
	}
	message_vision( HIG "$N��$N��������ң�ɾ��죬˫�������ˣ�\n" NOR, me);
	return 1;
}

int dismiss_array(object person)
{
	int i,j,n;
	object *member,ob;

	member=person->query_team();
	j=sizeof(member);
	n=person->query_temp("array/level");
	for (i=0;i<j;i++)

	{
		ob=member[i];
		ob->delete_temp("array");
		ob->add_temp("apply/attack",-n);
		ob->add_temp("apply/damage",-n);
		ob->add_temp("apply/defense",-n);
		ob->add_temp("apply/armor", -n);
		tell_object(ob,"˫����λ��\n");
	}
}

//if the me kills enemy, then all members in the array kill enemy
int array_kill(object me, object enemy)
{
	object *member, ob;
	int i,j;
	member=me->query_team();
	j=sizeof(member);

	for(i=0;i<j;i++) {
		ob=member[i];
		ob->kill_ob(enemy);
	}


	return 1;
}



int effective_level() { return 10;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

