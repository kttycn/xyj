#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({"kan dao"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50);
		set("material", "steel");
		set("wield_msg", "$N��$n�������У�\n");
	}
	init_blade(10);
	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	object me=this_player(), weapon;

	if(!me->query("nanhai/zhulan"))
		return notify_fail("������ʲô��\n");
	if(!arg || arg != "bamboo" )
		return notify_fail("��Ҫ��ʲô��\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "kan dao")
		return notify_fail("�㲻���ſ�����ô�����ӣ�\n");

	if(environment(me)->query("short")!="������")
		return notify_fail("��������ҿ�ʲô��\n");

	if((int)me->query("kee") <80)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	message_vision("$N�ߵ�һ�������ǰ�����𿳵�����ʼ�����ӡ�\n", me);
	me->start_busy(8);
	call_out("kan1",2,me);
	call_out("kan2",4,me);
	call_out("kan3",6,me);
	call_out("finish_kan",8,me);

   return 1;
}

void kan1(object me)
{
	message_vision("���������ʵؼ�Ӳ,����Ҳֻ����һ��!\n");
	message_vision("$N���˲�ͷ�ϵĺ�ˮ����������������\n", me);
}

void kan2(object me)
{
	message_vision("$NЪ��һ�����������ǰ��ϵĴ���΢΢һЦ��\n", me);

}

void kan3(object me)
{
	message_vision("��Ҫ�����ˣ�$N�˲��ò�ͷ�ϵĺ�ˮ��Ѹ�ٻӶ��ſ�����\n", me);
}

void finish_kan(object me)
{
	object where=environment(me);

	message_vision("$NĨ��һ�Ѻ�������Ŀ��ſ��µĴ���Ц��Ц��\n", me);
	me->receive_damage("kee", 60);
	me->delete("nanhai/zhulan");
	tell_object(me,"�����������֮��Ҳ�����ջ�\n");
	tell_object(me,"��ľ�����˻���֮�������\n");
	me->improve_skill("unarmed",random(me->query("int")),1);
	me->add("faith",1);
	me->add("combat_exp",9);
	me->add("potential",3);
	this_object()->move(find_living("daza xiaoseng"));
}
