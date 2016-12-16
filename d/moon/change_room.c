//Cracked by Roath
#include <ansi.h>
inherit ROOM;
void init();
void dance(object where);
void finish_dance(object where);
void check_time(object where);
int do_enjoy();

void create ()
{
	set ("short", "��˼��");
	set ("long", @LONG

���������ʹ�������¯�е���һ�����㣬�������ơ����ط���һ�Ż����
��ʯ�󰸣����϶����������˷�������ʮ�������⣬��ɫ��Ͳ����һ����
�������һ����Ҥ���ң�����������ˮ����İ׾ջ����鰸�������ż���
��ֽ���ּ����㣬�����϶�ٰ�����֮����Ϳ��
LONG);

	set("item_desc", ([ /* sizeof() == 1 */
		"paper" : "ֽ�Ϸ���������д��һ�仰���첻�ϣ����Ѿ�������˫˿��������ǧǧ�ᡣ",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/change.c" : 1,
		"/d/obj/flower/juhua.c" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"huilang.c",
	]));

	setup();
}

void init()
{
	object where=this_object();
	remove_call_out("check_time");        
	check_time(where);
	add_action("do_enjoy","enjoy");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t%120));
	if(phase==3&&(!query("moon/start_dance"))) dance(where);
	if(phase==6&&query("moon/start_dance")) finish_dance(where);
	call_out("check_time",40,where);
}
void dance(object where)
{
	message("channel:es",HIM+"���¹����϶�(Chang e)��îʱ��,�������ˡ�\n"+NOR,users());
	tell_object(where,"�϶�����ɴȹ�������������,����ǣ�\n");
	tell_object(where,"���Ϊ֮��ɫ�����Ϊ֮���ݣ�\n");
	tell_object(where,"����ֻΪ�����У��˼����м��ؼ�?\n");
	set("moon/start_dance",1);
	set ("long", @LONG
�������϶�ľ�����Ҳ����������ĵط���������Χϡϡ�������ż�λ����,
���϶���������۷���������(enjoy)���������.
LONG);
}

void finish_dance(object where)
{
	tell_object(where,"�϶��߳���أ����Ե������칦�ε��˽�����\n");
	set("moon/start_dance",0);
	set ("long", @LONG
���������ʹ�������¯�е���һ�����㣬�������ơ����ط���һ�Ż����
��ʯ�󰸣����϶����������˷�������ʮ�������⣬��ɫ��Ͳ����һ����
�������һ����Ҥ���ң�����������ˮ����İ׾ջ����鰸�������ż���
��ֽ(paper)���ּ����㣬�����϶�ٰ�����֮����Ϳ��
LONG);
}

int do_enjoy()
{
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("moon/start_dance"))
		return notify_fail("�϶�û�����أ���������ʲô?\n");
	if((string)me->query("family/family_name")!="�¹�")
		return notify_fail("���ɵ��Ӳ���������!\n");
	if(me->query("faith")>800)
		return notify_fail("�����Ϊ�Ѿ��㹻�ߣ������������ˡ�\n");      
	tell_object(me,"�������������������򣬲���ü����Ц��\n");
	me->add("faith",1);
	me->start_busy(4+random(1));
	me->improve_skill("moondance",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"����������������������ˣ�\n");
	return 1;       
}

