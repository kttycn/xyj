// leitai.c ��̨
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������̨");
	set("long",@long
�����ǿ�������һ����̨�������˵�����кܶ��������ʿ�������
�䣬���ס���̨������������У���̨֮����һ����(gu)�������������
���˱���Ҫ�Ȼ��ģ����ܱ��ޡ�����̨���������һ�������(paizi)������
̨��һ�Ƿ���һ�������֪(sign)��
long);
	set("exits",([
		"down" : __DIR__"leitai",
	]));

	set("item_desc", ([
		"gu" : "����һ���ģ����޵��˷�Ϊ����һ�����д����(dagu qiecuo player name)" +
				"����һ����������ս(dagu juezhan player name),�����������̨���˽��Թ" +
				"�Ƿǣ���ô����������ս���ٺò�����ѡ���ˡ�\n",
		"paizi" : "��  ��  ��  ��\n",
		"sign" : "�ڱ���֮ǰ������ģ��취�����(gu),Ȼ��Ϳ��ԱȻ���(fight player name)��\n",
	]));
//	set("no_death", 1);;
	set("objects",([
		__DIR__"npc/killer" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_dagu", "dagu");
}

int do_dagu(string arg)
{
	object ob, me = this_player();
	string opp, opp1, str, event;

	if ( !arg ) return notify_fail("��Ҫ����ʲô��\n");

	if ( sscanf(arg, "%s %s %s", event, opp, opp1) == 3 ) return notify_fail("�͹�ƽ�ӽ�ʲô��ѽ��\n");

	if ( sscanf(arg, "%s %s", event, opp) != 2 ) return notify_fail("��Ҫ����ʲô��\n");

	if ( me->query("id") == opp ) return notify_fail("����ë������\n");

	if ( !present(opp, environment(me)) ) return notify_fail("���ﲢ�޴��ˣ�����Լ�������ɡ�\n");

	if ( !find_living(opp) ) return notify_fail("��������������ǲ��ǻ��\n");

	if ( event == "marryfight" || event == "zhaoqin" ) {
		if ( me->query("gender") == "����" )
			return notify_fail("���Ⱳ�ӱ�ָ���ˣ�\n");
		else if ( me->query("class") == "bonze" )
			return notify_fail("�㷲��δ��������������\n");
		else if ( me->query("gender") == "����" )
			return notify_fail("Ψ��Ů�����ܾ��б������ף�\n");
		else str = "��������";
	}
	else if ( event == "fight" || event == "qiecuo" ) {
		str = "�д����";
	}
	else if ( event == "kill" || event == "juezhan" ) {
		str = "������ս";
	}
	else return notify_fail("����ֻ����������(marryfight,zhaoqin)���д����(fight,qiecuo)��������ս(kill,juezhan)���á�\n"); 

	ob = find_player(opp);

	message_vision("$N�����鳣����˴��һ�£���ķ������̡���һ�����죬������Զ��\n", me);

	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s�����鳣����˴��һ�£���ķ������̡���һ�����죬������Զ��", me->name()));
	me->delete_temp("last_channel_msg");
	CHANNEL_D->do_channel(me,"chat",sprintf("��������%s����̨����%s�����λ����ͬ��������֤��", ob->name(), str));
	me->set_temp("dagu", 1);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->is_fighting()) return notify_fail("����ܲ����뿪��\n");
	me->remove_all_killer();
	me->delete_temp("dagu");
	return ::valid_leave(me, dir);
}
