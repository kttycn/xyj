//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
//by yushu �޸� 2001.2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","����");
	set("long",@LONG

������ǰ�Ƿ���ֱ����ǧ�ߵ��ٲ���������ô�����ٲ���
�㲻����ȥ���Իӽ�(huijian)��ˮ��
LONG
	);

	set("exits", ([
		"east" : __DIR__"jby",
	]));

	setup();
}

void init()
{
	add_action("do_huijian", "huijian");
}

int do_huijian(string arg)
{
	object room, ob;
	object me = this_player();
	int sk = me->query_skill("yujianshu",1);
	if(me->is_busy() )
		return notify_fail("������æ���أ����й���ӽ���ˮ...\n");
	if(me->query("family/family_name") != "��ɽ����")
	{
		tell_object(me,"��о����������ġ�\n"); 
		return 1;
	}
	if(me->query("combat_exp") < 1000000)
	{
		tell_object(me,"�����ѧ�������������ӽ���ˮ�����塣\n");
		return 1;
	}
	if(me->query("daoxing") < 800000)
	{
		tell_object(me,"��ĵ��в��������������ӽ���ˮ���⾳��\n");
		return 1;
	}
	if(me->query("kee") < 100)
	{
		tell_object(me,"�㻹������Ϣһ����ɡ�\n");     
		return 1;
	}
	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ����ܻӽ���ˮ��\n");

	message_vision("$N�ӽ�ȥ��ˮ�����Ū�ø����ӽ���ˮˮ������ȫ��ʪ͸��Ҳ������\n",me);
	me->add("kee",-100);
	if(me->query("shushan/duanshui_perform")) 
	{
		tell_object(me,"���ƺ�������������ʲô�ˡ�\n");       
		return 1;
	}
	if((int)me->query_skill("yujianshu", 1) > 149){
		tell_object(me,HIW"���ƺ��Իӽ���ˮ��������\n��о��������ɽ�����ڲ��Ͻ�����\n"NOR);
		me->improve_skill("yujianshu", 50+random(100));
		me->add("shushan/duanshui",1);
		me->start_busy(2);
	}
	if(me->query("shushan/duanshui",1) > 500)
	{
		me->set("shushan/duanshui_perform",1);
		tell_object(me,HIY"���ڲ�֪�������������������衸��ˮ�޺ۡ���\n"NOR);
		me->delete("shushan/duanshui");
	}
	return 1;
}             
