inherit ITEM;
inherit F_LIQUID;
void create()
{
	set_name("ˮͰ", ({"shuitong"}));
	set_weight(2000);
	set("long", "һ����ˮ�õĴ�ˮͰ��\n");
	set("unit", "��");
	set("max_liquid", 10);
// set("no_drop",1);
	set("no_sell",1);
	set("no_get",1);
	set("no_give",1);
	set("no_steal",1);
}
void init()
{
	add_action ("do_fill", "fill");
	add_action ("do_carry","carry");
	add_action ("do_pour", "pour");
}
int do_fill(string arg)
{
	if(!arg||arg!="shuitong")
		return notify_fail("����װʲô��\n");
	if(environment(this_player())->query("resource/water")!=1)
		return notify_fail("���û��ˮ��\n");
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 10,
	]));
	tell_object(this_player(),"����ˮͰ��װ��ˮ\n");
	return 1;
}
int do_pour (string arg)
{
	int i;
	object me = this_object();
	object who = this_player();
	object where = environment(who);
	object wan = present ("wan feng",where);
	if(!arg||arg!="gang"||!wan)
		return notify_fail ("�����ˮ�����ﵹ��\n");
	if (! query("liquid/remaining"))
		return notify_fail ("ˮͰ��û��ˮ��\n");
	message_vision ("$N��$n���"+query("liquid/name")+"����ˮ�ס�\n",who,me);
		set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 0,
	]));
	who->add_temp("lingtai/tiaoshui",1);
	i = 4;
	i -= who->query_temp("lingtai/tiaoshui");
	tell_object(who,"������е�����\n");
	who->receive_damage("kee",20);
	who->receive_damage("sen",20);
	if (i > 0)
		message_vision ("$N����$n���ٵ�"+chinese_number(i)+"�α�ɡ�\n",wan,who);
	else
	{
		message_vision ("$N����$n���������ˣ������ˮ�����ˡ�\n",wan,who);
		who->set("lingtai_quest/done",1);
		this_object()->move(where);
		where->set("full",1);
		who->delete_temp("lingtai/tiaoshui");
	}
	return 1;
}
int do_carry(string arg)
{
	object who=this_player();
	if(!arg||arg!="shuitong")
		return notify_fail("��Ҫ��ʲô?\n");
	if(who->query("lingtai_quest/quest_type")!="��ˮ")
		return notify_fail("�����ס�㣺�������ͣ�\n");
	if(environment(who)->query("full"))
		return notify_fail("�����ס�㣺ˮ���������������ɣ�\n");
	if((who->query("kee")<80)||(who->query("sen")<80))
		return notify_fail("�����ס�㣺��λ����̫���ˣ�������ȥ��Ϣ�ɡ�\n");
	this_object()->move(this_player());
	tell_object(this_player(),"������ЦЦ����������λ���ֽ�ˮ�������ˡ�\n");
	this_player()->delete("lingtai/tiaoshui");
	return 1;
}
