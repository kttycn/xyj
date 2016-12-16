inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"�ȼ��̻�"NOR);
	set("long", @LONG
���ߵ������������һ���ȼ��̻ᣬ��Ȼ�ط���ª��������ȴ��ò����ˡ�
�����ڵ����ۿ�ʱ��������洫��һ�����������������꣡��������˿���
ȴʲô��û���֣�ֻ�ǿ�����һ��ľ��(paizi)�����Ƕ���
LONG
	);
	set("no_fight",1);

	set("exits", ([
		"up"  : __DIR__"shangjie2",
	]));

	set("item_desc",(["paizi": "�����˵��(hou)��������\n",]));
	setup();
}

void init()
{
	add_action("do_hou", "hou");
}
int do_hou()
{
	object me;
	int exp;
	me = this_player();

	if ( me->query("combat_exp")>10000)
		return notify_fail("����ս����̫�ߣ���������»��˺����ˣ�\n");
	if ( me->query("sen") < 20 )
		return notify_fail("����;�����������Ϣһ�������ɣ�\n");
	if(me->is_busy() )
		return notify_fail("������æ���أ����й����Һ�...\n");

	me->add("sen", -10);
	if ( random((int)me->query("kar")) < 5 )
	{
		message_vision("$N�������������꣡����ȴû�����㡣\n", me);
		me->start_busy(random(5));
	}

	else
	{
		message_vision("$N����������˷糭��������ȫ��ɤ��������������ꡣ\n", me);
		write("���˸�����һЩMONEY�����а��е�����ok����\n");
		me->add("balance",random(300));
		me->add("combat_exp",random(10));
		me->add("potential",random(5));
		me->start_busy(2+random(3));
	}
	return 1;
}

