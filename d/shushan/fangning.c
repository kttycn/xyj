//shushan2 by yushu@SHXY 2001.2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","������");
	set ("long", @LONG

����ʯ���ɵ�С��,���������ϡ��ŹֵĻ���,��ϸ�������ǻ��ƣ�
����������������֣�������һЩʫ,����Ƕ�(read)һ����������һ��
�������������������������ȥ��
LONG);
   
	set("outdoors", "shushan");
	set("exits", ([      
		"northdown" : __DIR__"zushi",
		"southdown" : __DIR__"tianshi",
	]));
	setup();
}

void init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object me=this_player();
	string *poem = ({
		"��˿�Ѷ����Ѹ���ŭ�����б���;��",
		"��Եδ�������ɣ�ֻ������������",
		"�����ԹŶౡ��������һ����ʱ�ѡ�",
		"�������վ������������Ѵ������š�",
		"�������³����������ĺδ������ƣ�",
		"�������Թ�ȣ�����ȴ�ѷ���ȡ�",
		"���ƴ�������ɢ��ƬƬ�ɻ���ˮ����",
		"����˫�����ȥ���᳦��ϸ�����",
		"���һ�����ɢ�����ݼ�ʱ���λ���",
		"Ը��Ī���ɲ��࣬��������ǰ��Ե��",
		"ϸ����·�����������䵱ʱ�������� ",
	});

	if(me->is_busy() )
		return notify_fail("������æ���أ����й�������ϵ�ʫ...\n");

	if((int)me->query_skill("literate",1)<100 )
		return notify_fail("�㻹�����������ʫ��\n");

	if(me->query("family/family_name") != "��ɽ����")
	{
		tell_object(me,"�㲻����ɽ�������½���ʲô��\n"); 
		return 1;
	}
	if(me->query("sen") < 100)
	{
		tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
		return 1;
	}
	message_vision("$N��ϸ�Ķ������ϵ�ʫ��" + poem[random(sizeof(poem))] + "\n", me);
	me->add("sen",-50);
	me->start_busy(2);
	if(me->query("shushan/jinsheng_perform")) 
	{
		tell_object(me,"���ƺ�������������ʲô�ˡ�\n");       
		return 1;
	}
	if((int)me->query_skill("canxin-jian", 1) > 149){
		tell_object(me,HIW"��о�����ʲô�ǡ��项��\n"NOR);
		me->improve_skill("literate", 50+random(10));
		me->add("shushan/dushi",1);
		me->start_busy(2);
	}
	if(me->query("shushan/dushi",1) > 500)
	{
		me->set("shushan/jinsheng_perform",1);
		tell_object(me,HIG"������˳������һ�䣺"HIY"�̽���������Զ������Ψ�С���������"HIG" ��ʱ���������"HIR"��������������\n"NOR);
		me->delete("shushan/dushi");
	}
	return 1;
}
