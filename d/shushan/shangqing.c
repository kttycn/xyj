//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
  set ("short","���幬");
  set ("long", @LONG

������ɽ��ʥ�����ĵط���������һ����¯������������
�������䡣
LONG);
   set("exits", ([      
       "south" : __DIR__"zushi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jiansheng" : 1,
      __DIR__"npc/jiantong" : 2,
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
	if(phase==38&&(!query("shushan/start_jiangjing"))) jiang_jing(where);
	if(phase==41&&query("shushan/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"����ɽ���ɡ���������(Shushan jiansheng)�����ڿ�ʼ��������������ע���ˡ�\n"+NOR,users());
	tell_object(where,"������������������������½�ν�ҵ����Ʋ�Ф����Ψ�󣬹��Ʋ�Ф����Ф��������ϸҲ��\n");
	tell_object(where,"��������������������������������ֶ���֮��һԻ�ȣ���Ի����Ի����Ϊ�����ȡ�\n");
	tell_object(where,"����������������������ȹ����£�����ܹ㣻����Ϊ�����ȣ����ܳ�������\n");
	tell_object(where,"�����������������������������£�����ҹ㣻������ȣ����ӣ�\n");
	tell_object(where,"��������������������������ս��ʤ��������̡��콫��֮���Դ���֮��\n");
	tell_object(where,"........................................\n");
	set("shushan/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"��������˵���������Ϣ�ɡ�\n");
	set("shushan/start_jiangjing",0);
}

int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("shushan/start_jiangjing"))
		return notify_fail("�������滹û��˵����\n");

	if((string)me->query("family/family_name")!="��ɽ����")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("�����������˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻������������Ľ������������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("taoism",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"����������ʦ�ɷ������ˣ�\n");
	return 1;
}
