//Cracked by Roath
// possess.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("����û��������\n");
/*
if(me->query("id")!="windows" && me->query("id")!="unix" && me->query("id")!="bro")
        return notify_fail("��û��Ȩ��ʹ�����ָ�\n");
*/
	if( ob->query_temp("body_ob") )
		return notify_fail( ob->name() + "�Ѿ����˸������ˡ�\n");
	message_vision("$N����һ����â���$n���ڡ�\n", me, ob);
	LOGIN_D->enter_world(me, ob, 1);

	return 1;
}

int help()
{
        write(@TEXT
ָ���ʽ��posssess <Ŀ������>

��������һ�������ϣ������������������ͬ�� EUID��
�������� quit ָ���ص�ԭ�������塣
TEXT
        );
        return 1;
}