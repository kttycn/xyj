 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�Ҳ���������\n");
	message_vision(HIB + "\n�����һ�����ٿȻ������ס��$n��$nӦ��ˤ���ڵ��ϣ���\n" + NOR,me,ob);
	ob -> unconcious();
	if ( !wizardp(ob) && userp(ob) ){
		log_file("static/hunmi", sprintf("%s(%s) �� %s(%s) ���˹�ȥ��ʱ�� %s \n",
			me->name(1),geteuid(me),ob->name(1),geteuid(ob),ctime(time())));
		message("channel:chat",HIR"����쾫�顿��������(Faguan)��"+"��˵"+me->query("name")+"����� "HIW+ob->query("name")+HIR" ���˹�ȥ��\n"NOR,users());
	}
	return 1;
}
 
int help(object me)
{
   write(@HELP

ָ���ʽ: hunmi <id>
 
ʹĳ�����̻��Բ���

HELP
   );
   return 1;
}
