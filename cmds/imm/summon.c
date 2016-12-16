// summon command..

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, env;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("�ף����� ���������\n");

	if(wizardp(ob) && wiz_level(me) < wiz_level(ob))
		return notify_fail("�㲻��ץ�ȼ�����ߵ���ʦ��\n");
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ��������Ȼ�󲻼��ˡ�\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������������ǰһ��ڣ�����\n");
	ob->move(environment(me));
	tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ��\n");
	tell_object(ob,"������ ����ʱ������"+(string)me->query("name")+
	"����Ū�����ġ�\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ��\n",({me,ob}));

	env = environment(ob);
	while (env && env->is_character())
		env = environment(env);

	if ( !wizardp(ob) && userp(ob) ){
		log_file("static/summon", sprintf("%s(%s) �� %s(%s) ץ��\n%s(%O) ʱ�� %s \n",
			me->name(1),geteuid(me),ob->name(1),geteuid(ob),env->query("short"),env,ctime(time())));
		message("channel:chat",HIR"����쾫�顿��������(Faguan)��"+"��˵"+me->query("name")+"����� "HIW+ob->query("name")+HIR" ץ���� "+env->query("short")+"��\n"NOR,users());
	}
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ������㽫ĳ��ץ������ǰ��
HELP
    );
    return 1;
}
