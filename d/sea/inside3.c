//modified by sgzl for dntg/donghai quest

inherit ROOM;
#include <ansi.h>
void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_serve();

void create ()
{
	set ("short", "��������");
	set ("long", @LONG

����֮����һ���飬��ŵ��һ���յ�ͨ��������������ʯ������ɣ�����
���л�Ƕ�������鱦������ǽ�Ϲ������������������൱�ĳ¾ɡ�������
�ϱ�������ƫ�����������ˣ��㻹���Ը�������һ�¡�(serve)

LONG);

	set("exits", ([ /* sizeof() == 2 */
		"westdown" : __DIR__"inside2.c",
		"east" : __DIR__"inside4",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/longwang" : 1,
	]));
	set("water", 1);

	setup();
}

int valid_leave()
{
	if(present("dao kan dao", this_player())
	|| present("jiu gu cha", this_player())
	|| present("mei hua chui", this_player())
	|| present("hua gan ji", this_player()))
		return notify_fail("�����������������ߣ�\n");
	return ::valid_leave();
}

void init()
{
	object where=this_object();

	remove_call_out("check_time");
	check_time(where);
	add_action("do_serve","serve");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if((phase==66)&&(!query("dragon/start_hungry"))) feel_hungry(where);
	if((phase==69)&&query("dragon/start_hungry")) feel_full(where);
	call_out("check_time",40,where);
}

void feel_hungry(object where)
{
	message("channel:es",HIY+"����������������(Ao guang)�������ˣ�������������\n"+NOR,users());
	set("dragon/start_hungry",1);
}
void feel_full(object where)
{
	tell_object(where,"��������Ц�����ܺã��ܺá�\n");
	set("dragon/start_hungry",0);
}
int do_serve()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("dragon/start_hungry"))
		return notify_fail("�����������������ڲ��ۣ�\n");
	if((string)me->query("family/family_name")!="��������")
		return notify_fail("����������������������ݣ�\n");
	if(me->query("faith")>800 )
		return notify_fail("����������������ݵ��ˣ��������¾���С�������ɡ�\n");
	tell_object(me,"����������Ǵ����������ģ������������ֱ��ʹ�죡\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("seashentong",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"�������ı̺���ͨ�����ˣ�\n");
	return 1;
}
