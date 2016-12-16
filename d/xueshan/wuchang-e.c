//standroom.c used by weiqi...others may hate this format:D
//wuchang-e.c

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();

void create ()
{
	set ("short", "���䳡");
	set ("long", @LONG

���Ǳ���ǰ��һ��ƽ�أ�����ѩɽ��������֮�á����漫ƽ����
�����ˡ��������������С�ĵ㣬ѩɽ����Ҳ���ǽ�˶�������
���ȹ̹���
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"wuchang-se",
		"north" : __DIR__"wuchang-ne",
		"west" : __DIR__"wuchang-c",
	]));
	
	set("objects", 
	([ //sizeof() == 1
                __DIR__"npc/tuying-zunzhe" : 1,
                __DIR__"npc/baixiang-zunzhe" : 1,
	]));


	set("outdoors", "xueshan");

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
	if(phase==24&&(!query("xueshan/start_jiangjing"))) jiang_jing(where);
	if(phase==27&&query("xueshan/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}
void jiang_jing(object where)
{
	message("channel:es",HIW+"����ѩɽ����������(Baixiang zunzhe):ѩɽ���ӣ����ڿ�ʼ���ڱ�����Ѫ��. \n"+NOR,users());
	tell_object(where,"������Ѫ����ν������������������ص��ڹ�.\n");
	set("xueshan/start_jiangjing",1);
	set ("long", @LONG
        �ͼ���СС�ĵط����ж�ʮ�������һ�������
  С���������������߽��ɷ�.
LONG);
}
void finish_jing(object where)
{
	set("xueshan/start_jiangjing",0);
}
int do_hear()
{
	object me=this_player();
	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("xueshan/start_jiangjing"))
		return notify_fail("�������߻�û��ʼ�ڷ���.\n");              
	if((string)me->query("family/family_name")!="��ѩɽ")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("������Լ������������ˡ�\n");
	tell_object(me,"�������������������򣬲���ü����Ц��\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("ningxue-force",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"�������ı�����Ѫ�������ˣ�\n");
	return 1;
}                                                                    
