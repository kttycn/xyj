inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set("short","����");
	set("long",@LONG
�����������������������������ź�ɫ�ĵ�̺�������м����Ϸ�������
һ����ң����⣺����ǧ���������վ�ż���������Ů���ӣ�����æ
µ�ţ�������������ϸ�������һ��������
LONG);
	set("objects", ([
		__DIR__"npc/shinv": 2,
		__DIR__"npc/menghuoming": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"pianting1",
		"west"  : __DIR__"pianting2",
		"north"  : __DIR__"houting",
		"south"  : __DIR__"shufang",
	]));
	setup();
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

	int phase=((int)(t%120));
	if(phase==10&&(!query("phoenix/start_jiangjing"))) jiang_jing(where);
	if(phase==13&&query("phoenix/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"����˳ǡ�"HIC"��"HIR"��"HIY"(Chen xin)�����ڿ�ʼ���䣬������ע���ˡ�\n"+NOR,users());
	tell_object(where,"��������˵����������������ӡ���С������Ī�ܳ�������������֮�����ｫ�Ա���\n");
	tell_object(where,"��������˵������������ϣ��Խ���¶����Ī֮����Ծ���\n");
	tell_object(where,"��������˵�������ʼ��������������У����ཫֹ֪��ֹ֪���Բ�����\n");
	tell_object(where,"��������˵�������Ʃ��֮�����£��̴���֮�ڽ�����\n");
	tell_object(where,"........................................\n");
	set("phoenix/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"���˵���������Ϣ�ɡ�\n");
	set("phoenix/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("phoenix/start_jiangjing"))
		return notify_fail(HIC"��"HIR"��"HIY"��û�н��������\n");

	if((string)me->query("family/family_name")!="�����")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail(HIC"��"HIR"��"NOR"����˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻����"HIC"��"HIR"��"NOR"�������Ϊ���������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("tenglong-finger",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"����������������ָ�����ˣ�\n");
	return 1;
}
