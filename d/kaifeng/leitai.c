// leitai.c ��̨ǰ�㳡
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��̨ǰ�㳡");
	set("long",@long
������������̨ǰ���һ�����͹㳡���������������̨�ϱ��䣬����
����ɽ�˺��������Ҳ���������֣���ô����������̨(jump leitai)���Ա��԰ɡ�
long);
	set("exits",([
		"south" : __DIR__"chen2",
	]));
	set("outdoors", "kaifeng");
	setup();
}
 
void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object *ob;
	object me;
	int i;
	me = this_player();

	if( !arg || arg=="" || arg !="leitai" ) 
		return notify_fail("��Ҫ����������\n");

	if (!living(me)) return 0;
	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 90) {
		message_vision("$Nһ������Խ����̨�������Ϊ���ϸ��ع��࣬ˤ��������\n", me);
		me->unconcious();
		return 1;
	}
	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if (userp(ob[i]))
	{
		message_vision(HIR"ֻ��һ����ӰͻȻ����,��ո���$Nһ�ơ�\n"NOR, me);
		me->unconcious();
		return notify_fail("");
	}
	if (arg == "leitai")
	{
		if (mapp(this_player()->query_conditions_by_type("poison")) || mapp(this_player()->query_conditions_by_type("hurt")))
			return notify_fail("�����о޶����ϲ�ȥ��̨��\n");

		if( (int)me->query_skill("dodge") < 21 )
		{
			message_vision(HIR"$N��Ҫ������̨����ϧ��׾�������һ��أ������ڿ�����б��һ������ʺˤ��������\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 20 && (int)me->query_skill("dodge") < 51 )
		{
			message_vision(GRN"$Nһ���������ڿ��л�����һ�£������������ĵ���������̨��\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(HIR"$Nһ���������ڿ��л�����һ�£������������ĵ���������̨��\n" NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 50 && (int)me->query_skill("dodge") < 101 )
		{
			message_vision(HIW"$N˫��һ�����������ڿ���һ�����Ӵ�����ӯ���䵽����̨֮�ϣ�\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(HIW"$N˫��һ�����������ڿ���һ�����Ӵ�����ӯ���䵽����̨֮�ϣ�\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 100 && (int)me->query_skill("dodge") < 151 )
		{
			message_vision(YEL"$Nһ��أ�������Ȼ�εض����ڿ���һ��������һ��ת�壬��Ȼ��������̨֮�ϣ�\n"NOR, me); 
			me->move(__DIR__"leitai1");
			message_vision(YEL"$Nһ��أ�������Ȼ�εض����ڿ���һ��������һ��ת�壬��Ȼ��������̨֮�ϣ�\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 150 && (int)me->query_skill("dodge") < 200 )
		{
			message_vision(BLU"$N��ԭ��δ����ֻ��������Ȼ�εض��𣬹��Ȱ�س�������̨֮�ϣ�\n"NOR, me);
			me->move(__DIR__"leitai1");
			return 1;
		}
		if( (int)me->query_skill("dodge") > 200 )
		{
			message_vision(MAG"$N���Ϻ�����֣���������ķ����ڿ��н����߳����ţ�������Ϣ��������̨֮�ϣ�\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(MAG"$N���Ϻ�����֣���������ķ����ڿ��н����߳����ţ�������Ϣ��������̨֮�ϣ�\n"NOR, me);
			return 1;
		}
		return 1;
	}
	return 1;
}
