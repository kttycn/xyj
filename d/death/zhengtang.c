// zhting.c

inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
	set ("short", "���ޱ���");
	set ("long", @LONG

��������������£����������ľ����������޵ظ��������󶼻�
�������ܵ�Ӧ�еĴ��á���ǰһ�Ŵ����������������������Ա�
���Ŵ��й١�
LONG);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"new-walk5",
		"north": __DIR__"walk1",
	]));
	set("hell", 1);
	set("out_doors", 1);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/yanluowang" : 1,
//  __DIR__"npc/panguan" : 1,
	]));
	setup();
	call_other("/obj/board/shengsi_b", "???");
}

void init()
{
	object where=this_object();
	remove_call_out("check_time");
	check_time(where);
	add_action("do_hear","hear");
}

void check_time(object where)
{
	mixed *local = localtime(time()-900000000);
	int t = local[2] * 60 + local[1];
	int phase=((int)(t/120));
	if(phase==17&&(!query("hell/start_jiangjing"))) jiang_jing(where);
	if(phase==20&&query("hell/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIW+"�����޵ظ���������(Yanluo wang)�����ڸ�������˵˵���ǵĹ���ļ��£�\n"+NOR,users());
	tell_object(where,"������(Yanluo wang)����ȥһЩ�з�ʳ��Ϣ�ĵط��Խ⼢����\n");
	tell_object(where,"������(Yanluo wang)������ǿ���������ڻ��У������ܿ��ˣ����ⱻ���˺���\n");
	tell_object(where,"������(Yanluo wang)���������Ҳ�нײ�֮�֡�\n");
	tell_object(where,"������(Yanluo wang)�����ǹ���Ӧ�Ժ�ƽΪ�󣬲�Ҫ�˺��޹���\n");
	tell_object(where,"........................................\n");
   	set("hell/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"������˵���������Ϣ�ɡ�\n");
	set("hell/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("hell/start_jiangjing"))
		return notify_fail("�㻹�ǵȻ������ɡ�\n");
	if((string)me->query("family/family_name")!="���޵ظ�")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("������̾������������֪���Ļ��డ��\n");
	tell_object(me,"�㲻����ͷ����\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("tonsillit",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"�������������������ˣ�\n");
	return 1;
}
