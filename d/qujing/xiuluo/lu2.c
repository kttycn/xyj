//sgzl

inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short", BLK"�ڰ�֮Ԩ"NOR);
	set ("long", @LONG
[1;31m�������ͨ�������޽�֮·,һ��ͨ������,[2;37;0m
[1;31mͨ��ʹ��,ͨ�����ĺڰ�֮·.[2;37;0m
[1;31m����ħ��ɭɭ,���˲�������![2;37;0m
LONG);

	set("exits", ([
	]));

	set("objects", ([
		__DIR__"npc/gui" : 2,
	]));

	setup();
}

void init ()
{
	add_action ("do_go", "go");
}

int do_go (string dir)
{
	object who = this_player();
	string *names = ({
		"west",
		"east",
		"south",
		"north",
	});

	if (! dir)
		return 0;

	if (who->query("kee")>50)  who->add("kee",-80); 
	else
	{
		who->unconcious();
		return 1;
	}

	if (random(5))
	{
		message_vision ("$NŬ����Ѱ���ų��ڡ�\n",who);
	}
	else
	{
		if (dir != names[random(sizeof(names))])
		{
			message_vision ("$N�����ҵ�һ˿��϶�����˳�ȥ��\n",who);
			who->move(__DIR__"lu4");
			return 1;
		}
		else
		{
			message_vision ("$N�����ҵ�һ˿��϶�����˳�ȥ��\n",who);
			who->move(__DIR__"lu5");
			return 1;
		}
	}

	return 0;
}


