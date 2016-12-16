// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);

mapping kill=([]);
mapping query_kill() {return kill;}
void remove_list(string me, string obj);

int main(object me, string arg)
{
	object obj, guard_ob;
	string callname;//*killer, 
	int just_issued=0;

	if (userp(me) && !query_heart_beat(me))
	{
		"/cmds/usr/quithy"->main(me);
		return notify_fail("������û�������������µ�½!!\n");
	}

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("���ﲻ׼ս����\n");

	if( !wizardp(me) && environment(me)->query("no_kill") )
		return notify_fail(HIR"���ﲻ׼ɱ��\n"NOR);

	if( me->is_ghost() )
		return notify_fail("���˹��ˣ�����ʵ��ɣ�\n");

	if( !arg )
		return notify_fail("����ɱ˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if(userp(obj) && (int)me->query("PKS",1)/2 > me->query("age") - 14 )
 		return notify_fail("��ɱ���˻���������\n");
	
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (userp(obj) && !query_heart_beat(obj))
	{
		write("�����һ�㣬�ǲ����ǻ��\n");
		return notify_fail("������������\n");
	}
	if((int)obj->query("age") <= 16 && userp(obj)&& userp(me))
		return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
	if((int)me->query("friends/"+obj->query("id")) )
		return notify_fail("����ĺ����Ѷ�ɱ�������ǡ�����\n");

	if((int)me->query_skill("force") <= 150 && userp(obj))
		return notify_fail(HIR"���������ô��Ҳ��ɱ����? \n"NOR);

	if((int)me->query_skill("spells") <= 150 && userp(obj))
		return notify_fail(HIR"��ķ�����ô��Ҳ��ɱ����? \n"NOR);

	if((int)me->query("combat_exp") <= 200000 && userp(obj))
		return notify_fail(HIR"�����ѧ��ô��Ҳ��ɱ����? \n"NOR);

	if((int)me->query("daoxing") <= 200000 && userp(obj))
		return notify_fail(HIR"��ĵ�����ô��Ҳ��ɱ����? \n"NOR);

	if(userp(obj)) {
		if( (int)obj->query("score") < 20 )
			obj->set("score", 0);
		else
			obj->add("score", -20 );
	}
	if(obj==me)
		return notify_fail(HIC"��"+HIR" zisha "+HIC"�� "+HIR"suicide -f"+HIC" ָ���ȽϿ�Щ��\n"NOR);

	if(!valid_kill(me,obj,0)) return 0;

	set_to_killer(me,obj);

	callname = RANK_D->query_rude(obj);

	//mon 5/29/99
	if(userp(me)) {
	  string myid=me->query("id");
	  string objid=obj->query("id");

	  if(undefinedp(kill[myid])) {
	    just_issued=0;
	    kill+=([myid:({objid})]);
	    call_out("remove_list",1,myid,objid);
	  } else {
	    string *targs=kill[myid];
	    if(targs && member_array(objid,targs)!=-1) {
		// just issued kill on this target recently.
		just_issued=1;
	    } else {
		// not issue kill recently.
		just_issued=0;
		if(!targs)
		    targs=({objid});
		else
		    targs+=({objid});
		kill[myid]=targs;
		call_out("remove_list",1,myid,objid);
	    }
	  }
	}

	if(just_issued==0) {
	    message_vision(HIR"\n$N����$n"+HIR"�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n"NOR, me, obj);	
	} else {
	    // avoid too much screen rolling to the target.
	    write("\n�����"+obj->name()+"�ȵ�����"
		    + callname + "�����ղ������������һ��\n\n");
		   
	    return 1;
	}

	if( obj->query_temp("protected")
	&& objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
	&& (string)guard_ob->query_temp("protect")==obj->query("id")
	&& guard_ob!=me ) {
		message_vision(HIC"$N����$n����˵�������ڴˣ����õ��ģ�\n"NOR,guard_ob,obj);
		message_vision(HIC"$N����ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, me);
		guard_ob->kill_ob(me);
		me->kill_ob(guard_ob);
	}

	do_kill(me, obj);

	return 1;
}
void do_kill(object me, object obj)
{

	me->kill_ob(obj);
	if( !userp(obj) ){
	
		if(!obj->accept_kill(me) )
		obj->kill_ob(me);

	} else if( !userp(me) ) {
		obj->kill_ob(me);
	} else {
		obj->kill_ob(me);
		tell_object(obj, HIC"�����Ҫ��" + me->name() 
			+ HIC"�����ಫ������Ҳ���������һ��"BLINK HIR" kill"+NOR HIC" ָ�\n"NOR);
	}
}

void remove_list(string me, string obj)
{
    string *targs;

    if(undefinedp(kill[me])) return;
    targs=kill[me];
    if(!targs || sizeof(targs)<2) {
	map_delete(kill, me);
    } else {
	targs-=({obj});
	kill[me]=targs;
    }
}

int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ����˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ����� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬����һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 

