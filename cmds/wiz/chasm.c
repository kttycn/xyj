//Cracked by Roath
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	if(!arg)
		return notify_fail("ָ��Ϊchasm id\n");
	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
		if (!ob) return notify_fail("û����˰�����������ҧ����,:D\n");
	tell_object(me,ob->query("name")+"��������"+HIR+chinese_number((int)ob->query("life/life_time"))+NOR"��\n");
	tell_object(me,ob->query("name")+"�Ѿ�����"+HIR+chinese_number((int)ob->query("rsg_eaten"))+NOR"���˲ι�\n");
	return 1;
}

int  help(object  me)
{
    write(  @LONG

ָ���ʽ: chasm <player id>

ָ��˵��:
	������������Կ�����ҵ������Լ������˲ι��ĸ�����

LONG);
  
    return  1;
}
