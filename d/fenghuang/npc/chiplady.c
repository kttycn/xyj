#include <ansi.h>
inherit NPC;
inherit __DIR__+"chiplib.c";
int to_say_chip();
void create()
{
	set_name("�۶�",({ "mill","chip lady","lady" }));
	set("level",9);
	set("title","����С��");
	set("race", "����");
	set("gender","Ů��");
	set("age", 19);
	set("long",@LONG
�ɰ�������С��, �������Ǯ����������. ( ask mill about chip )
LONG
);
	set("attitude", "friendly");
	set("inquiry",([
		"����": (: to_say_chip :),
		"chip": (: to_say_chip :),
	]));
	setup();
	seteuid(getuid());
}

void init()
{
	add_action("do_change","change");
}

int do_change(string schip)
{
	object me;
	int chip;
	me = this_player();
	if(!schip)
	{
		command("think");
		command("say "+me->query("name")+"����Ҫ��ö���밡��");
		return 1;
	}
	if(sscanf(schip,"%d",chip)!=1)
	{
		command("?");
		command("say "+me->query("name")+"����Ҫ���ﰡ��");
		return 1;
	}
	if(me->can_afford(chip*100)==0)
	{
		command("say "+me->query("name")+"�����ƺ�û�������Ǯ������룿");
		return 1;
	}
	me->receive_money(chip*(-100));
	Game_receive_chip(chip,me);
	message_vision("$N�ó�"+F_VENDOR->price_string(chip*100,me->money_type())+"��"+query("name")+"��\n",me);
	command("smile");
	command("say "+me->query("name")+"����Щ����Ҫ�ĳ��롣");
	return 1;
}


int to_say_chip()
{
	object me = this_player();
write(@HELP
	ָ  ��			 ˵    ��
=====================================================================
	change <������>	 �����ϵ�Ǯ���һ�����
=====================================================================
HELP);
	command("say Ŀǰ��"+F_VENDOR->price_string(10,me->money_type())+"��һö���롣");
	return 1;
}
