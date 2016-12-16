// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname, myfamily;
	mapping skills;
	int i;
	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

	if( !ob->is_character() )
		return notify_fail("��Ҫ���˭����\n");

	if( !userp(ob) )
		return notify_fail("��ֻ�ܿ�����������ݵ����\n");

	if( me->query("family/privs")==-1
	&&	(string)me->query("family/family_name")==(string)ob->query("family/family_name") ) {
		message_vision("$N����$n˵�����ӽ���������Ҳ������"
			+ me->query("family/family_name") + "�ĵ����ˣ����߰ɣ�\n\n",
			me, ob);
		tell_object(ob, "\n�㱻" + me->query("family/title") + "�����ʦ���ˣ�\n\n");
	} else if( ob->is_apprentice_of(me) ) {
		message_vision("$N����$n˵�����ӽ���������ʦͽ������������߰ɣ�\n", me, ob);
		message_vision("$N����$n˵���������粨���ƶ����Σ�����Ϊ֮������\n\n", me, ob);
		tell_object(ob, "\n�㱻ʦ�������ʦ���ˣ�\n\n");
	} else
		return notify_fail("����˲�����ĵ��ӡ�\n");
	myfamily=ob->query("family/family_name");
	ob->delete("family/master_name");
	ob->delete("family/master_id");
	if( (int)ob->query("score") < 50 )
		ob->set("score", 0);
	else
		ob->add("score", -50 );
	if( ob->query("guild/child") ){
		ob->delete("guild");
		ob->delete("family");
		ob->add("betray/count", 1);
		ob->add("betray/"+me->query("class"), 1);
	}

	ob->set("title",myfamily+"��ͽ");
	ob->save();

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : expell <ĳ��>
 
���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������뿪������£�����
����������ɣ�������㴫Ͷ��������ʦ����
 
HELP
	);
	return 1;
}
