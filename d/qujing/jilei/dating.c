//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����繬��Ĵ����������м������ʯ��ʯ�Σ�����ʯ����
��������ͭ�ơ����������洫���������ζ��������һͨ����
���ͨ����������������һʯ�ȡ�����ط�Ҳ�Ǵ���ɱ��Խ��
�ĵط�����ֻҪ��(hear)���Ϳ����ˡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"canting",
        "northeast"   : __DIR__"shilang",
        "southeast"   : __DIR__"woshi",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
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
	if(phase==94&&(!query("kusong/start_jiangjing"))) jiang_jing(where);
	if(phase==97&&query("kusong/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIW+"�����ɽ����ƶ���ţħ��(Niumo wang)�����ڿ�ʼ�������ǻ��ƶ����ķ���\n"+NOR,users());
	tell_object(where,"ţħ��˵������ɱ�˰���һ��Ҫ�ĺ��ֶ����������顣\n");
	tell_object(where,"Ҫ���ײ��ϣ������������ˮ��\n");
	tell_object(where,"ȡ���˵��⣬��˵��һ����ܳ�������������Ҫ������Ū��������\n");

	tell_object(where,"Ҫ���ǣ�ĬĬǱ����ͻȻ���������������ض���졣\n");
	set("kusong/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"ţħ��˵������ȥ���Ա����ķ�����Ρ�\n");
	set("kusong/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("kusong/start_jiangjing"))
		return notify_fail("ţħ����û��ʼ�����ķ��ء�\n");

	if((string)me->query("family/family_name")!="���ƶ�")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("ɱ��Խ������С�£����Ѿ���ţħ����ʦ���ˡ�\n");
	tell_object(me,"�����Ա����ţ����š�����������ɱ�˵Ŀ�С�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("pingtian-dafa",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"��������ƽ��󷨽����ˣ�\n");
	return 1;
}


