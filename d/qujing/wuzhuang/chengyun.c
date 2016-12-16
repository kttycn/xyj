//Cracked by Roath
inherit ROOM;

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create ()
{
	set ("short", "���Ƹ�");
	set ("long", @LONG

���Ƹ�ӹ��е���ߴ������ϻ�����������麿������������˺�
��Ĺ�����Χ����������ƾ��������Զ�����¾�����ǰ��ɽ��
�巿¥�ᣬɽ����ʯ����������Ŀ��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));

	set("outdoors", "wuzhuang");

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
	if(phase==87&&(!query("wuzhuang/start_jiangjing"))) jiang_jing(where);
	if(phase==90&&query("wuzhuang/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"����ׯ�ۡ���Ԫ����[zhenyuan daxian]�����ڿ�ʼ˵����������ע���ˡ�\n"+NOR,users());
	tell_object(where,"�쳤�ؾá���������ܳ��Ҿ��ߣ����䲻���������ܳ�����\n");
	tell_object(where,"�������ã�Ī֮���أ�\n");
	tell_object(where,"�ʹ�����Ϊ���£����ɼ����£�������Ϊ���£����������¡�\n");
	tell_object(where,"��ʥ���ǣ������ٱ����������壬��Т�ȣ������������������С�\n");
	tell_object(where,"........................................\n");
	set("wuzhuang/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"��Ԫ����˵���������Ϣ�ɡ�\n");
	set("wuzhuang/start_jiangjing",0);
}

int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("wuzhuang/start_jiangjing"))
		return notify_fail("��Ԫ���ɻ�û��˵����\n");

	if((string)me->query("family/family_name")!="��ׯ��")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("��Ԫ���ɶ���˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻������Ԫ���ɵĽ������������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("taiyi",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"��������̫���ɷ������ˣ�\n");
	return 1;
}
