// yuebing �±�

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����ڵ��±�", ({"yue bing", "bing"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������ڸ���ҵ�����.��\n");
		set("unit", "ֻ");
		set("no_get", 1);
		set("no_give", 1);
	}
		set("is_monitored",1);//ʯͷ��
		setup();//ʯͷ��
}

void init()
{
	add_action("do_eat","eat");
}
int do_eat()
{
	object me;
	me = this_player();
	if(!me->query("marks/yuebing"))
	{
		message_vision("$Nһ�ڰ��±������˶��\n",me);
		me -> add("combat_exp",5000);
		me -> add("daoxing",5000);
		me -> add("potential",3000);
		me->add_maximum_force(100);
		me->add_maximum_mana(100);
		tell_object(me,HIR"�㱻������������С���ǧ����ѧ����,��ǧ��Ǳ�ܺ�һ�ٵ������뷨����\n"NOR);
		me->set("marks/yuebing",1);
	}
	else tell_object(me,"���Ѿ��Թ�һ���±��ˣ�����ԣ�\n");
	destruct(this_object());
	return 1;
}
