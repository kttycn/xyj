inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"����һ���Ҷ�"NOR);
	set("long", @LONG
������Ƿ���ǵĵ���һ���Ҷ������ﾭ����
�ܶ���޳�û���������Ź������Ͽ��кö��
������(dig yandong)
LONG
	);
	set("exits", ([
		"down"  : __DIR__"yandong2",
		"up"     : __DIR__"rukou",
	]));
	setup();
}

void init()
{
	add_action("do_dig", "dig");
}

int do_dig(string arg)
{
	object me,obj;
	int exp;
	me = this_player();
	obj=new("/d/fenghuang/npc/guaishou");
	if (!arg || arg!="yandong") return notify_fail("��Ҫ��ʲô��\n");
	if (me->query_temp("digdong1")!=1) return notify_fail("�㻹����ȥ������ɣ�\n");
	if ( me->query("kee") < 10 ) return notify_fail("�����Ѫ���㣬��Ϣһ�������ɣ�\n");
	if ( me->query("combat_exp") > 500000)
		return notify_fail("���Ѿ�����Ҫͨ��ɱ����������Լ�����ѧ�ˣ�\n");
	if ( me->is_busy()) return notify_fail("����æ���أ�\n");
	me->add("kee", -10);
	if ( random(2)==1 )
	{
		message_vision(HIR"$N�Ĳ����ɵ����ţ�����ڵ��Լ�����ȥ�ˣ�\n"NOR, me);
		me->start_busy(1);
	}
	else
	{
		message_vision(HIW"$N�ڿ��ô�һ������\n"NOR, me);
		me->add_temp("dig",1);
		if (me->query_temp("dig")>8)
		{
			me->set_temp("digdong1",0);
			me->set_temp("dig",0);
			write("���ڿ�һ���󶴣�ͻȻ���������һͷ��������\n");  
			obj->move(environment(me));
			remove_call_out("destrory");
			call_out("destrory",300,obj);
			return 1;
		}
		me->start_busy(1);
	}
	return 1;
}

void destrory(object ob)
{
	object me=this_player();
	me->set_temp("digdong1",0);
	me->set_temp("dig",0);       
	destruct(ob);
	return;
}


