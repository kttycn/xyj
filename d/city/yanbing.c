#include <ansi.h>
inherit ROOM;
inherit F_SAVE;
string SAVE_NAME;

void create()
{
	set ("short", "�ݱ���");
	set ("long", @LONG

����ǰһ����ֻ�������ݺ������ɣ����Ӷ������룬�������졣ս��
�������죡����СУ�Ҵ�ææ������һ�²�С�ģ��Դ���ء�Զ����
̨��վ��һλ���Ž������쳣����Ľ������Ӷ���С�죬���ڲ�����
���ӡ�

LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"center",
	]));

	setup();
}   

void init()
{
	add_action("do_caoyan", "caoyan");
	add_action("do_status", "status");
	set("no_clean_up", 1);
}

int do_caoyan(string arg)
{
	object me=this_player();
	if(me->query("soilder")<=0)
		return notify_fail("����һ��ʿ��Ҳû�У���ôѵ�����ӡ�\n");

	if( me->query("train_level") >= 200 )
		return notify_fail("��ľ��ӵ�ѵ�����Ѿ�����������ˣ�\n");

	if(me->query("balance") < (me->query("soilder")+1)*1000)
		return notify_fail("����ʽ��㣬�����ȶ�׬��Ǯ�ɡ�\n");
	tell_object(me,"��ľ��ӵ�ѵ���������ˡ�\n");
	me->add("train_level",1);
	me->add("balance",-(me->query("soilder")*1000));
	save();
	return 1;
}
int do_status(string arg)
{
	object me=this_player();
	object ob;
	string one;
	printf("                   "+this_object()->query("short")+"\n"+
	"��������:"+me->query("soilder")+"     ����ѵ����:"+me->query("train_level")+"\n");
	return 1;
}
