// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <ansi.h>
void create ()
{
	if (random(4))
		set_name("ľ��", ({ "mu ren ", "mu" }) );
	else
		set_name("ľͷ��", ({ "mu ren", "mu" }) );
	set_weight(900000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "һ������������ľͷ�ˡ�\n");
		set("unit","��");
	}
	setup();
}

int init ()
{
	add_action ("do_act","act");
	return 1;
}

int do_act (string arg)
{
	string *msgs = ({
		HIR "$N���ű���ٸ����������ȫ���ȥ��\n"NOR,
		HIR "$Nһ�߿��ű���ٸ��һ�߷���һ�����ǡ�\n"NOR,
	});
	string *actions = ({
		HIY "��о����Լ��Ļ����������˽�����\n"NOR,
		HIY "��Ļ����뷨����ˡ�\n"NOR,
	});
	object me = this_player();
	object ren = this_object();

	if (arg != "ren" && arg != "mu ren")
	{
		tell_object(me,"���������Ȼ��أ�\n");
		return 1;
	}
	if (me->query("kee")<10 || me->query("sen")<10)
	{
		tell_object (me,"���Ѿ�̫ƣ���ˣ�\n");
		me->unconcious();
		return 1;
	}
	if (me->is_busy())
	{
		tell_object (me,"������æ���أ�\n");
		return 1;
	}
	ren->add("times",1);
	message_vision (msgs[random(sizeof(msgs))],me);
	me->add("kee",-10);
	me->add("sen",-10);
	me->improve_skill("needle",5+random(3),1);
	tell_object (me,actions[random(sizeof(actions))]);
	me->start_busy(1,1);
	if (ren->query("times")>100)
	{
		message_vision ("ֻ��$Nҡҡ�λΣ����һ�µ��ڵ������ˡ�\n",ren);
		destruct (ren);
	}
	return 1;
}

