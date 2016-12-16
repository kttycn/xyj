// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <weapon.h>

inherit STICK;

void create()
{
	set_name("��ɨ��", ({"sao ba"}));
	set_weight(1000);
	set("no_drop",1);
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
	add_action("do_shao", "sao");
}

int do_shao(string arg)
{
	object me=this_player(), weapon;
	string env;

	if(me->query("class")!="taoist"||me->query("lingtai_quest/quest_type")!="��ɨ"
	||me->query("lingtai_quest/done"))
		return notify_fail("����ɨ�أ�����ô�ҵ��أ�\n");
	if(!arg && arg != "di" )
		return notify_fail("��Ҫɨʲô��\n");
	if(me->is_busy())return notify_fail("����æ���أ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "sao ba")
		return notify_fail("�㲻������ɨ����ô��ɨ��\n");

	env=environment(me)->query("short");
	if(env!=me->query("lingtai_quest/quest"))
		return notify_fail("��û����Ҫ������ɨ�����\n");

	if((int)me->query("kee") <80)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�����Ŵ�ɨ��ɨ�������\n", me);
	write("ֻ��ƬƬ��Ҷ����ɨ��һ�ߡ�\n");
	me->start_busy(5);
	call_out("finish_shao",5,me);

	return 1;
}

void finish_shao(object me)
{
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц��ͥ�ӱ����ɨ�øɸɾ�����\n", me);
	me->receive_damage("kee", 60);
	me->set("lingtai_quest/done",1);
	destruct(this_object());
}
