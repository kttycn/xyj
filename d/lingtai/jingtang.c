// Room: some place in ��ţ����
// inside2.c

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();
inherit ROOM;

void create ()
{
	set ("short", "������");
	set ("long", @LONG

���������Ƕ��Ľ����ã�ƽʱ��ʿ�Ǳ������ｲ��˵��������
��ʲô���£�Ҳ�����Ｏ�����顣������������ط�������ʮ
����棬Ҳ����һ��ʮ����ʿ��
LONG);

	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"houlang1.c",
		"southdown" : __DIR__"inside1.c",
		"up" : __DIR__"wuchang.c",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/xiao" : 1,
		__DIR__"npc/yunyang" : 1,
	]));
	set("valid_startroom", 1);

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" ) {
		if ( wizardp(me)) return ::valid_leave(me, dir);
		if (objectp(present("master yunyang", environment(me)))) {
			if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
				if(me->query("sixiang_winner"))
					return ::valid_leave(me,dir);
			}
			return notify_fail("��������˵������ʦ���ޣ��ټ����ˣ�ֻ�б���ͨ��������ĵ��Ӳ����ʸ�μ���ʦ��\n��������ذɣ�\n");
		}
	}
	return ::valid_leave(me, dir);
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
	if(phase==52&&(!query("hell/start_jiangjing"))) jiang_jing(where);
	if(phase==55&&query("hell/start_jiangjing")) finish_jing(where);
	call_out("check_time",40,where);
}

void jiang_jing(object where)
{
	message("channel:es",HIY+"������ɽ����������[master puti]�����ڿ��������ķ�����λ���ӵ�������������\n"+NOR,users());
	tell_object(where,"���������������������֪���ۣ�����ƣ�Ϊ����Ϫ��Ϊ����Ϫ�����²��룬������Ӥ����\n");
	tell_object(where,"���������������������֪��ף������裬Ϊ���¹ȡ�Ϊ���¹ȣ��������㣬�������ӡ�\n");
	tell_object(where,"���������������������֪��ף�����ڣ�Ϊ����ʽ��Ϊ����ʽ�����²�߯���������޼���\n");
	tell_object(where,"�����������������������ɢ��Ϊ����ʥ����֮����Ϊ�ٳ����ʴ��ǲ��\n");
	tell_object(where,"........................................\n");
	set("hell/start_jiangjing",1);
}
void finish_jing(object where)
{
	tell_object(where,"��������˵���������Ϣ�ɡ�\n");
	set("hell/start_jiangjing",0);
}
int do_hear()
{
	object yao;
	object me=this_player();

	if(me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(!query("hell/start_jiangjing"))
		return notify_fail("�������滹û�п�ʼ���ڵ����ɷ���\n");

	if((string)me->query("family/family_name")!="����ɽ���Ƕ�")
		return notify_fail("���ɵ��Ӳ�����������\n");
	if(me->query("faith")>800)
		return notify_fail("�����������˵���������ȥ��Щ�������������ˡ�\n");
	tell_object(me,"�㲻������������Ľ������������ˡ�\n");
	me->start_busy(5);
	me->add("faith",1);
	me->improve_skill("dao",random((int)(me->query("spi")+me->query("int"))/2),1);
	me->add("combat_exp",30);
	me->add("daoxing",30);
	me->add("potential",10);
	me->receive_damage("kee",20);
	me->receive_damage("sen",20);
	tell_object(me,"�������ĵ����ɷ������ˣ�\n");
	return 1;
}
