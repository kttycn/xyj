//kickout.c

#include <command.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	object ob, *all, link_ob;
	all = users();

	if(!arg || arg =="")
		return notify_fail("��Ҫ��˭�߳�ȥ��\n");

	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");

	for(i=0; i<sizeof(all); i++)
	{
		if( arg == all[i]->query("id"))
			ob = all[i];
	}

	if (!ob)
        return notify_fail("û�������ҡ�\n");

	if (ob == me)
		return notify_fail("�� quit ����ָ���Щ :) \n");

	if( (wiz_level(me) < wiz_level(ob)) || (wiz_level(me) == wiz_level(ob)) )
		return notify_fail("�㲻�ܸϼ������ߵ���ʦ�����ߣ�\n");

	link_ob = ob->query_temp("link_ob");

	if( link_ob ) {
		link_ob->set("last_on", time());
		ob->set("kickout_time",time());
		link_ob->set("last_from", query_ip_name(ob));
		link_ob->save();
		ob->save();
		if( environment(ob)->query("valid_startroom") )
		{
			ob->set("startroom", base_name(environment(ob)));
			tell_object(ob,"�㱻ϵͳ�߳���"+MUD_NAME+"�������ǻ�ӭ��������ֻ��Ҫע���Լ������С�\n");
			tell_object(ob,"�˳���...\n");
		}
		destruct(link_ob);
	}

	tell_object(ob,"��ӭ�´�������\n");
	message("system", ob->name() + "�뿪��Ϸ��\n", environment(ob), ob);

	CHANNEL_D->do_channel(this_object(), "rumor", ob->name() + "��ϵͳ�߳���"+MUD_NAME+"��");

	ob->save();
	destruct(ob);

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : kickout <id>

��������߳�������Եʱ�������ô�һָ�
HELP
    );
    return 1;
}

