// jiangli.c
// ��������bug�����
// xuer

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,present;
	object player,gold;
	int i;
	
	if( !arg || arg=="" || sscanf(arg, "%s for %s", id, reason)!=2)
		return notify_fail("ָ���ʽ��jiangli <���id> for <��Ҫ����bug>\n");

	player = find_player(id);
	if (!player) return notify_fail("û�������\n");
	if (wizardp(player)) return notify_fail("���ܽ�����ʦ\n");
	i=random(4);
	switch (i)
	{
		case 0:
			player->add("combat_exp", 5000);
			present="��ѧ���� 5000 ��";
			break;
		case 1:
			player->add("daoxing", 5000);
			present="���� ����";
			break;
		case 2:
			player->add("potential",500);
			present="Ǳ�� 500 ��";
			break;
		case 3:
			gold = new("/obj/money/gold");
			gold->set_amount(10);
			gold->move(player);
			present="10 gold";
			break;
	}
	tell_object(player,HBRED""+me->query("name")+"��������"+present+"��\n"NOR);
	write(HBRED"�㽱��"+player->query("name")+present+"��\n"NOR);
	message("channel:chat",HIR"����쾫�顿��������(Faguan)��"+"��˵���ڡ�"+reason+
		"����"+me->query("name")+"��������� "HIW+player->query("name")+
		HIR+present+"\n"NOR,users());
	
	log_file("static/jiangli",
		sprintf("%s(%s) ���� %s(%s) %s ��Ϊ %s  on %s\n",
		me->name(1),
		geteuid(me),
		player->name(1),
		geteuid(player),
		present,
		reason,
		ctime(time()) ));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : jiangli <���id> for <��Ҫ����bug>

��������뷢��Сbug(�������--����ʧ��,��û��ɾ޴���ʧ��)
��player�Խ���.ע�������ñ�����,���bug���ⲻ��ȷ,����ʾ��
���پ���
����	jiangli tryid for ����tree����
HELP	);
	return 1;
}
