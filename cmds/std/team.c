// team.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object *t;
    string msg;

    if( !arg ) {
	if( !pointerp(t = me->query_team()) )
	    return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
	write("�����ڶ����еĳ�Ա�У�\n  " + implode(t->name(1), "\n  ") + "��\n");
	return 1;
    }
    if( arg=="dismiss" ) {
	if( !pointerp(t = me->query_team()) )
	    return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
	if( me->is_team_leader() ) {
	    message("team", me->name(1) + "�������ɢ�ˡ�\n", t, me);
	    write("�㽫�����ɢ�ˡ�\n");
	} else {
	    message("team", me->name(1) + "����������顣\n", t, me);
	    write("����������Ķ��顣\n");
	}
	me->dismiss_team();
	return 1;
    }
    if( sscanf(arg, "with %s", arg)==1 ) {
    	object ob;

	if( !(ob = present(arg, environment(me)))
	  ||	!living(ob)
	  ||	!ob->is_character()
	  ||	ob==me )
	    return notify_fail("�����˭��Ϊ��飿\n");

	if( !pointerp(me->query_team()) || me->is_team_leader() ) {
	    if( me==(object)ob->query_temp("pending/team") ) {
		if( !pointerp(me->query_team()) ) {
		    ob->add_team_member(me);
		    message_vision("$N��������$n�Ķ��顣\n", me, ob);
		} else {
		    me->add_team_member(ob);
		    message_vision("$N������$n������顣\n", me, ob);
		}
		ob->delete_temp("pending/team");
		return 1;
	    } else {
		message_vision("$N����$n����$P�Ķ��顣\n", me, ob);
		tell_object(ob, YEL "�����Ը����룬���� team with " + me->query("id") + "��\n" NOR);
		me->set_temp("pending/team", ob);
		return 1;
	    }
	} else
	    return notify_fail("ֻ����ӿ���������˼��롣\n");
    }
    if( sscanf(arg, "talk* %s", arg)==1 ) {
        string vb, emote_arg;
	if( !pointerp(t=me->query_team()) )
	    return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 )
	{
            vb = arg;
            emote_arg = "";
        }
	if (!(msg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0, 0)))
	    return 0;
	message("team", HIW "�����顿" + msg + NOR, t);
	return 1;
    }
    else if( sscanf(arg, "talk %s", arg)==1 ) {
	if( !pointerp(t=me->query_team()) )
	    return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
	message("team", HIW "�����顿" + me->name(1) + "��" + arg + "\n" NOR, t);
	return 1;
    }
    if( sscanf(arg, "form %s", arg)==1 ) {
	if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
	    return notify_fail("�������һ���������Ӳ�����֯���Ρ�\n");
	if( !me->query_skill(arg, 1) )
	    return notify_fail("����������ûѧ����\n");
	return SKILL_D(arg)->form_array(me);
    }
}

int help(object me)
{
    write(@HELP
����ָ��ʹ�÷���:

team with <ĳ��> - ��ĳ����ɶ���. ����Ҫ˫����ͬ�����Ż���Ч��
team dismiss     - �뿪����. ���´�ָ��������, ������������ɢ��
team talk <ѶϢ> - ����������������̸��, ������ tt <ѶϢ> �����
team form <��> - �����������ѧ���󷨵Ļ������Խ������еĳ�Ա��֯��
                   ĳ�����Σ�������ε�״ֻ̬Ҫ���һ�ƶ��ͻ�����

ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������

ע: team �� follow �Ƕ����ģ��㲻һ��Ҫ follow �������ӡ�
HELP
    );
    return 1;
}