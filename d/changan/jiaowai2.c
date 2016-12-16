// Room: /d/city/jiaowai8.c
//����lywin4/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "С����");
    set("long", @LONG
�������ݽ����һƬС���֣���Ӣ�ͷף������裬��¶Ϧ�⣬����
��Ƣ�������ѿ�����������ʱ����ΧС���ſŽ���������������С��С
ȸ�������ϻ��裬һ��Ҳ�����ˡ������Ǹ�����da���ĺû��ᡣ
LONG );
    set("exits", ([
        "east" : __DIR__"nanchengkou",
    ]));
    set("no_clean_up", 0);
    set_temp("wayao1",1);
    setup();
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
	object me;
	int i, kar, cps, bb,mm;
	me = this_player();

	if (me->query("combat_exp")>=1000)
		return notify_fail("���Ѿ������ô����������ˡ�\n");
	if(me->is_busy())
		return notify_fail("�㻹�ǵȹ�װ���˼��ٴ���ɣ�\n");

	if(me->query("kee")<10)
		return notify_fail(HIR"�㻹������Ϣһ�°ɣ����ҲҪ������Ӵ����\n"NOR);

	me->start_busy(3);
	message_vision("$N�����ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n", me);

	message_vision("$Nֻ������һ�����������\n",me);
	kar = me->query("kar");
        
	if (random(kar)>15) {
		message_vision("$N��һֻ"HIW"������\n"NOR, me);
		me->add("combat_exp",10);
		me->add("daoxing",12);
		tell_object(me,"��õ���10����ѧ����\n");
		tell_object(me,"��õ����������\n");
		me->receive_damage("kee", 10);
		me->add("potential",4);
		tell_object(me,"��õ���4��Ǳ��\n");
		return 1;
	}
        
	if (random(kar)>10) {
		message_vision("$N��һֻ"HIY"��˿ȸ��\n"NOR, me);
		me->add("combat_exp",8);
		me->add("daoxing",8);
		tell_object(me,"��õ���8����ѧ����\n");
		tell_object(me,"��õ��˶������\n");
		me->receive_damage("kee", 10);
		me->add("potential",3);
		tell_object(me,"��õ���3��Ǳ��\n");
		return 1;
	}
        
	if (random(kar)>8) 
	{
		message_vision("$N��һֻ"HIG"���ġ�\n"NOR, me);
		me->add("combat_exp",5);
		me->add("daoxing",4);
		tell_object(me,"��õ���5����ѧ����\n");
		tell_object(me,"��õ���һ�����\n");
		me->receive_damage("kee", 10);  
		me->add("potential",2);
		tell_object(me,"��õ���2��Ǳ��\n");
		return 1;
	}

	if (random(kar)>5) 
	{
		message_vision("$N��һֻ"YEL"��ȸ��\n"NOR, me);
		me->add("combat_exp",2);
		me->add("daoxing",2);
		tell_object(me,"��õ���2����ѧ����\n");
		tell_object(me,"��õ�����ʱ������\n");
		me->receive_damage("kee", 10);  
		me->add("potential",1);
		tell_object(me,"��õ���1��Ǳ��\n");
		return 1;
	}
	else 
	{
		me->receive_damage("kee", 10);  
		message_vision("$NʲôҲû�򵽡�\n",me );
	}
	return 1;
}
