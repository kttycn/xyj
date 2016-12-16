// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	if( rm(resolve_path(me->query("cwd"), file)) ) {
		write("Ok.\n");
		log_file("cmds/rm",
		sprintf("%s(%s) �� %s Ŀ¼�� ɾ�� %s on %s\n",
		me->name(1),   //��¼ʹ�����������
		geteuid(me),   //��¼ʹ�������ID
		me->query("cwd"),//��¼�ļ�����Ŀ¼
		file,          //��¼ɾ�����ļ�
		ctime(time()) ) ); //��¼ʹ�������ʱ��
	}
	else
		write("��û��ɾ�����������Ȩ����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : rm <����>

��ָ�������ɾ����Ȩ�޸ĵĵ�����
HELP
    );
    return 1;
}
