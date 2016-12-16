// quit.c

#include <ansi.h>
#include <command.h>

inherit F_DBASE;

void do_quit(object, object);

void create() 
{
	seteuid(getuid());
	set("channel_id", "����ָ��");
}

int main(object me, string arg)
{
	object link_ob;
	int flag = 0;

	if( !me->query_temp("netdead")) 
		return notify_fail("���ָ��ֻ����ϵͳִ�С�\n");

	if (me->query_temp("quit"))
		return notify_fail("�����˳������У����Ժ�\n");
	link_ob = me->query_temp("link_ob");

	if( link_ob ) {
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
	}

	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");
	if (me->query_temp("sleeped")) me->set("marks/insleeping",1);

	if (interactive(me) && query_idle(me) < 10) {
	} else flag = 1;

	me->set_temp("quit", 1);
        me->set_temp("no_kill", 1);
        me->set_temp("disable_inputs",1);
	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short() + HIR " ׼���뿪��Ϸ�ˡ�");
	if (!flag && !wizardp(me)) {
		write("�������������˳���Ϸ ,����������......\n");
		call_out("do_quit", 10, me, link_ob);

	} else do_quit(me, link_ob);

	return 1;
}

void do_quit(object me, object link_ob)
{
	int i;
	object *inv;

	if (!me) return;
	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}
	write("��ӭ�´�������\n");
	message("system", me->name() + "�������������뿪��Ϸ��\n", environment(me), me);

	CHANNEL_D->do_channel(this_object(), "sys", NOR + me->short(1) + HIR " �뿪��Ϸ�ˡ�");

	if (link_ob) {
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		destruct(link_ob);
	}

	if (me->query("mud_age") == me->query_temp("mud_age"))
		me->add("mud_age", 1);

	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ�\n");

	me->set_temp("quit", 0);
        me->set_temp("no_kill", 0);
        me->set_temp("disable_inputs",0);
	destruct(me);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : quit

��������ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
