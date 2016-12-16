// lumber_axe.c

#include <weapon.h>

inherit AXE;

void create()
{
	set_name("����", ({ "lumber axe", "axe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص���������������\n");
		set("value", 200);
		set("wield_msg","$N�ó�һ�ѿ����õ�$n���������е���������\n");
		set("unwield_msg", "$N�������е�$n��\n");
	}
	init_axe(5, TWO_HANDED);
	setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	object me=this_player(), weapon;
	string env;
	if(me->is_busy())
		return notify_fail ("����æ���أ�\n");
	if(!me->query("lingtai/kancai"))
		return notify_fail("�������ģ�����ô�ҵ��أ�\n");
	if(!arg && arg != "cai" )
		return notify_fail("��Ҫ��ʲô��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "lumber axe")
		return notify_fail("�㲻���Ÿ�����ô����\n");
	env=environment(me)->query("short");
	if(env!="����ƺ"&&env!="������")
		return notify_fail("����Ц,��������ʲô�ĸ��㿳.\n");
	if(environment(me)->query("clean"))
		return notify_fail("����Ĳı���������\n");
	if((int)me->query("kee") <80)
		return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");
	message_vision("$N����ͷ,�����Ŀ���.\n", me);
	write("ֻ��һ�Ѷ�����ĸɲķ��ڵ���.\n");
	call_out("finish_kan",5,me);
	me->start_busy(5);
	return 1;
}
void finish_kan(object ob)
{
	object me=ob;
	object where=environment(me);
	message_vision("$NĨ��һ�Ѻ��������Ц��Ц�����Ѿ�����һƬ�ĲĶ�������.\n",me);
	me->receive_damage("kee", 60);
	where->set("clean",1);
	me->delete("lingtai/kancai");
	tell_object(me,"�����������֮��Ҳ�����ջ�\n");
	tell_object(me,"��ľ���Ͳ���ж��֮������ˡ�\n");
	me->improve_skill("parry",random(me->query("int")),1);
	me->add("faith",1);
	me->add("combat_exp",8);
	me->add("potential",3);
	this_object()->move(find_living("kancai taoist"));
}
