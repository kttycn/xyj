

#include <ansi.h>


inherit ITEM;

void create()
{
	set_name(HIG "�����ڵ�" NOR, ({"nei dan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "һö����ʮ�깦���������ڵ���\n");
		set("value", 20000);
	}
	set("is_monitored",1);

	setup();
}

void init()
{
	if (!wizardp(this_player())) {
		set("no_get"," �ٺ٣����ΰ�! \n");
		set("no_drop","��ô����Ķ�������������! \n");
		set("no_give","��̫�����˰ɣ�\n");
	}
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int force_limit, neili_limit,improve;

	object me = this_player();
	if( !living(me) )
		return notify_fail("���뵱����\n");

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_force");
	
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( neili_limit <= force_limit  )
	{
		improve=20+random(me->query_skill("force")/2);
		me->add_maximum_force(improve);
		message_vision(HIY "$N����һö�����ڵ�����Ȼ�䵤��֮����������...\n" NOR, this_player());
	}
	else 
	message_vision(HIY "$N����һö�����ڵ�����������ûʲô�о�...\n" NOR, this_player());
	
	destruct(this_object());
	return 1;
}
