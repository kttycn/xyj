//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill,howlong, damage, force,time;
	mapping action; 
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("����Ҫ����˭������\n");

	if( target == me ) return notify_fail("����Ҳֻ���Լ������Լ������ˣ�\n");

	if (me->query_skill("idle-force",1)<200)
		return notify_fail("��ķ����󷨻�������\n");
	message_vision(HIC "\n$Nʹ��������,�ճյĳ�$n��ȥ��\n"NOR,me,target);
	message_vision(HIC "\n$Nһ�¾����ˣ���������.\n"NOR,target);
	command("rumor "+"��˵"+target->name()+"��"+me->name()+"�÷�����Ϯ���ɹ���");
	howlong=1000-me->query_skill("idle-skill",1)*2;
	me->set("actions",action);
	me->reset_action();
	target->unconcious();
	me->start_busy(10);
	return 1;
}

