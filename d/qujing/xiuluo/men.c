// by yxm@hxxt.hz
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "����֮��");
	set ("long", @LONG
  
            [1;31mʮ[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m֮[2;37;0m
            [1;31m��[2;37;0m
      
LONG);
	set("exits", ([
		"out"      : __DIR__"lu6",
	]));
	set("item_desc",([
		"men" : "\n����֮��\n\n"
	]));

	setup();
}

void init ()
{
	add_action("do_break","break");
}

int do_break (string arg)
{
	object me = this_player();

	if (arg != "men")
		return 0;

	message_vision ("$N���һ����ʹ��ȫ�������������֮�ţ�\n\n",me);
	if (me->query("force")<1000 ||
	me->query("mana")<1000)
	{
		me->unconcious();
		me->set("force",0);
		me->set("mana",0);
	}
	else
	{
		me->add("force",-1000);
		me->add("mana",-1000);
		message_vision ("ɲ�Ǽ�������ѣ����Ѿ�ײ���˵���֮�ţ�\n",me);
		message("channel:rumor", HIY+"����硿�������� (rulai fo): ��"+me->query("name")+"����Ȼ˽�Դ��˺ڰ�֮�ţ�\n"+NOR,users());
		message("channel:rumor", HIR+"�������޽硿ħ�����죨wu tian): �ٺ٣����ֽ����������ˣ�\n"+NOR,users());
		this_object()->recreate();
		message_vision ("\n������\n",me);
		message_vision (this_object()->query("long"),me);
		remove_call_out ("precreate");
		call_out ("precreate",10,this_object());
	}
	return 1;
}

void precreate (object me)
{
	tell_room (me,"��¡һ�����죬һ�ж���ԭ�ˣ�\n\n");
	me->create();
}

void recreate ()
{
	set ("short", "����֮��");
	set ("long", @LONG
            [1;31mʮ[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m��[2;37;0m
            [1;31m֮[2;37;0m
            [1;31m��[2;37;0m


LONG);
	set("exits", ([
//        "out"      : __DIR__"lu6",
		"enter"  : __DIR__"diyu1",
	]));

	setup();
}

