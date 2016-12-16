inherit ROOM;

#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_xianmei();

void create()
{
	set("short","���");
	set("long",@LONG

	��Ȼ�����ڵ��£������㲻����������������Ź����
��Ϣ����槼���������̫ʦ���ϣ����������ʱ��������
�������һ�ۣ��㲻������ͷ�������ٶ࿴��һ�ۣ�������
����������ӵ�����������ס����

LONG);
	set("exits", ([
		"north" : __DIR__"nei2",
		"south":__DIR__"mishi",
	]));
	set("objects", ([
		__DIR__"npc/daji" : 1,
	]) );

	set("valid_startroom", 1);
	setup();
	"/obj/board/xy_b"->foo();
}

void init()
{
	object where=this_object();
	remove_call_out("check_time");
	check_time(where);
	add_action("do_xianmei","xianmei");
}
void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if((phase==100)&&(!query("xuanyuan/start_hungry"))) feel_hungry(where);
	if((phase==103)&&query("xuanyuan/start_hungry")) feel_full(where);
	call_out("check_time",40,where);
}

void feel_hungry(object where)
{
	message("channel:es",HIM+"����ԯ��Ĺ��槼�(Da ji)��������鲻�ã���֪��λ��ͽ�ܺ��������찡��\n"+NOR,users());
	set("xuanyuan/start_hungry",1);
}
void feel_full(object where)
{
	tell_object(where,"槼�Ц������������ö��ˡ�\n");
	set("xuanyuan/start_hungry",0);
}
int do_xianmei()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("xuanyuan/start_hungry"))
		return notify_fail("槼�ŭ����������õĺܣ���Ҫ���ҡ�\n");
	if((string)me->query("family/family_name")!="��ԯ��Ĺ")
		return notify_fail("槼�˵����������ò��ã�����ʲô�£�\n");
 	if(me->query("faith")>800)
		return notify_fail("��Щ�����������С���������ɡ�\n");
	tell_object(me,"�����槼���ͣ�����ģ�ֱ��槼��ֵ�ƨ��ƨ�ߵġ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("xuanhu-shentong",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"��������������ͨ�����ˣ�\n");
	return 1;
}
