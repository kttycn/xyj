#include <ansi.h> 
inherit ROOM;
int do_jump(string arg);
int do_volunteer();

void create ()
{
	set ("short", "�κ���");
	set ("long", @LONG

����һ��������֮������֮����ʯ�š����к������������
Ѫ�����ϡ����������޷��֣��վ�֮·��ͬƥ�����������
֮ˮ�������ˣ��ȷ��˱ǡ�
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bidouya",
		"north" : __DIR__"huangwai",
	]));
	set("hell", 1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/shizhe" : 2,
	]));
	set("no_spells",1);

	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_volunteer", "volunteer");
}

int do_jump(string arg)
{       
	object me;
	me=this_player();

	if ( !arg || ((arg != "bridge") ))
		return notify_fail("��Ҫ����������������׼��������\n");
	message_vision("$N����һ�е���������ȥ������\n",me);
	me->move("/d/death/room10");
//	me->die();
	return 1;
}

int do_volunteer()
{
	object me=this_player();
	object* ob;
	int i;

	if((string)me->query("family/family_name")!="���޵ظ�")
		return notify_fail("�����Ǳ������ˡ�\n");
	if(me->query("faith")>500)
		return notify_fail("���Ǳ��Ŵ�������֮�ˣ����������������������������أ�\n");
	if(me->query("combat_exp")<50000 || me->query("daoxing")<50000)
		return notify_fail("�����ǱȽ�Σ�յ���,�㻹�Ƕ����������а�!\n");
	if (me->query_temp("in_guard"))
		return notify_fail("����ʹ�߶���˵:��ר���غ���ͷ����������ݹ���\n");
	if(time()-me->query("last_guard")<300)
		return notify_fail("����ʹ�߶���˵������ô��ô����Ҫ�����ˣ�ЪЪ��!\n");
	ob = users();
	for (i=sizeof(ob); i>0; i--)
	{
		if (ob[i-1]->query_temp("in_guard"))
		return notify_fail("����ʹ�߶���˵���Ѿ��������κ����ˣ���һ�������ɣ�\n");
	}
	tell_object(me,"�Ǻã���������һ����κ��Űɡ�\n");
	tell_room(environment(me),me->query("name")+"��ʼ���κ���ֵ�ء�\n");
	me->set("last_guard",time());
	me->set_temp("in_guard","1");
	me->save();
	remove_call_out("end_guard");
	call_out("end_guard",70,me);
	call_out("clone_meng",20,me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("in_guard"))
		return notify_fail("��������ֵ�������뿪!\n");
	return ::valid_leave(me,dir);
}

void clone_meng(object me)
{
	object ob;
	tell_room(environment(me),"ͻȻ������һ�����������������䡣\n");
	ob=new("/d/obj/npc/mengmian");
	ob->set("combat_exp",me->query("combat_exp"));
	ob->move("/d/death/naiheqiao");
	call_out("clone_meng", 20, me);
}

void end_guard(object me)
{
	object ob;
	int reward=me->query("combat_exp")/5000;
	me->delete("guard");
	me->add("faith",2+random(4));
	me->add("combat_exp",100+random(reward));
	me->add("potential",30+random(reward/4));
	me->delete_temp("in_guard");
	me->save();
	remove_call_out("clone_meng");
	tell_room(environment(me),me->query("name")+"��ɽ��ֵ����������\n");

	tell_object(me,"����ɽ��ֵ����������\n");
	while(ob = present("dahan",environment(me)))
	destruct(ob);
}
