//Cracked by Roath
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
	set ("short", "����");
	set ("long", @LONG

������һ�������İ��ң�ֻ��һ����������

LONG);
	set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
	]));
/*	set("objects",([
		"/d/jz/herb/lingzhi" : 2,
	]));
	set("outdoors", "penglai");*/
	setup();
}


void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="��" && arg!="����" && arg!="down") )
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy())
		return notify_fail("�����ں�æ����ʲôѽ��\n");
	
	message_vision("$N����ǰ����С�ĵ���ѽ��������\n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
		call_out("faila", 3, me);
		return 1;
	}

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}
 
	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$NԽ��Խ�ͣ���������ڰ�֮�С�����\n", me);
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N�����������������ڰ���$N����һ����Ŧ��$N�����»�Ŧ��\n", me);
	message_vision(YEL"ֻ����¡¡����! һ��ɽ�������߻�����$N���˳�����\n"NOR,me);
	message_vision(YEL"�������硱��һ����ɽ�ں����������ظ�ԭ״��\n"NOR,me);
	me->move(__DIR__"valley");
	return 1;
}
int faila(object me)
{
	tell_object(me, "��С���������������һ�㣬����ͷ���ۻ����͸Ͻ����˻���.\n");
	tell_room(environment(me), me->name()+"��ɫ�԰ף�������ش��������˻�������һ̤���أ�һͷ�Ե��ڵأ���ѽ��\n", ({me, me}));
	me->unconcious();
	
	return 1;
}
