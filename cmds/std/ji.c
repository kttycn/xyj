// ji.c ������
// created 7-4-97 pickle

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string targetname, fabaoname;
    object obj, *inv, target, obj2,old_env, fabao;
    int i, amount;
    mixed no_get;

    if( !wizardp(me) && environment(me)->query("no_magic") )
	return notify_fail("�����ֹ��������\n");
    if( !arg ) return notify_fail("��Ҫ������������\n");

    // Check if correct format is followed
    if( sscanf(arg, "%s on %s", fabaoname, targetname)>2 )
	return notify_fail("ָ���ʽ : ji <��������> [on <Ŀ��>]\n");

    // Check if both a fabao and a target is specified.
    // if so, then check 1. whether the player own's the fabao,
    // and 2. check whether the target is in the same environment.
    if( sscanf(arg, "%s on %s", fabaoname, targetname)==2 )
    {
	fabao=present(fabaoname, me);
	if(!fabao) return notify_fail("��û�� "+fabaoname+" ����������\n");
	target = present(targetname, environment(me));
	if (me->is_busy() && !fabao->query("no_busy"))
	    return notify_fail("����һ��������û����ɣ���Ͼ�����������\n");
	if(!target) return notify_fail("����û�� " + targetname + "��\n");
	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");
	if((int)target->query("age") <= 15 && userp(target)&& userp(me))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
	if((int)me->query("friends/"+target->query("id")) )
		return notify_fail("������ĺ�����ѽ�������Ǳ�����壡\n");
	if(target==me)
	    return notify_fail("���Լ���������\n");
	
	if(me->query("combat_exp")<50000 && userp(target))
		return notify_fail("�Լ�����û���ã�����ɱ�ˣ�\n");
   
	if(me->query("daoxing")<50000 && userp(target))
  		return notify_fail("�Լ�����û���ã�����ɱ�ˣ�\n");

	return fabao->ji(targetname);
	
}
    fabao=present(arg, me);
    if(!fabao) return notify_fail("��û��" + arg +"����������\n");
    if (me->is_busy() && !fabao->query("no_busy"))
	return notify_fail("����һ��������û����ɣ���Ͼ�����������\n");

    return fabao->ji();
}
int help(object me)
{
    write(@HELP
ָ���ʽ : ji <��������> [on <Ŀ��>]

���ָ����������һ�����

HELP
			);
		     return 1;
		 }
