// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("��ͷ", ({"hoe"}));
	set("no_drop",1);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N��$n�������У�\n");
	}
	init_stick(10);
	setup();
}

void init()
{
	add_action("do_dig", "dig");
}

int do_dig(string arg)
{
	object me=this_player();
	string env;

	if(me->query("class")!="taoist"||me->query("lingtai_quest/quest_type")!="�ֵ�"
	||me->query("lingtai_quest/done"))
		return notify_fail("�����ֵأ�����ô�ҵ��أ�\n");
	if(!arg && arg != "di" )
		return notify_fail("��Ҫ��ʲô��\n");

	if(me->is_busy())return notify_fail("����æ���أ�\n");
	env=environment(me)->query("short");
	if(env!="��԰")
		return notify_fail("�����������ʲô��\n");

	if((int)me->query("kee") <80)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�ߵ�һ��ĵ��ϣ������ͷ����ʼ�ֵء�\n", me);
	me->start_busy(8);
	call_out("dig1",2,me);
	call_out("dig2",4,me);
	call_out("dig3",6,me);
	call_out("finish_dig",8,me);

	return 1;
}

void dig1(object me)
{
	message_vision("$N���˲�ͷ�ϵĺ�ˮ����������������\n", me); 	
}
void dig2(object me)
{
	message_vision("$NЪ��һ��������ų�ͷ���������õĲ˵أ�΢΢һЦ��\n", me); 	
}
void dig3(object me)
{
	message_vision("��Ҫ�����ˣ�$N�˲��ò�ͷ�ϵĺ�ˮ��Ѹ�ٻӶ��ų�ͷ��\n", me); 	
}

void finish_dig(object me)
{
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц���������������һƬ�ѿ��õĲ˵ء�\n", me);
	me->set("lingtai_quest/done",1);
	destruct(this_object());
}
