#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY"��ɫ����"NOR, ({"gloden fish", "fish","yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "β");
		set("long", "����һβ��Ϊ�����Ľ�ɫ���㡣\n");
		set("value", 2500);
	}
	setup();
}

int do_eat(string arg)
{      
	int force_limit, neili_limit ;
	object me = this_player();

	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_force");
        
	if (!id(arg)||(arg!="fish"&&arg!="golden fish"))
		return notify_fail("��Ҫ��ʲô��\n");

	if ((string)me->query("family/family_name") == "�����")
	{
		if ( neili_limit <= force_limit )         
		{
			me->add("force",random(200));
			message_vision(HIY "$N����һβ��ɫ���㣬�е���������.\n" NOR, this_player());
		}
		else
			message_vision(HIY "$N����һβ��ɫ���㣬���Ǻ���ûʲô��.\n" NOR,  this_player());
	}
	else {
		me->receive_damage("sen", 200);
		me->receive_damage("kee", 200);
		write(HIR "���ж��ˣ�"HIB"�е��������������........��\n"+
		HIW "һ������Ц��..������..������..������\n" NOR);
		return 1;
	}        
	destruct(this_object());
	return 1;
}
