//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","��ʦ��");
	set ("long", @LONG

˵����ʦ����ʵ�����ⲻ��һ��ʯ����ֻ������ȡ�����ֶ���
��˵��ʦ������һ����ɽ�Ľ��񣬲�֪����ô���ܼ�������
ǽ��(wall)���������ر�,��֪����(da)�����ô����
LONG);
	set("exits", ([      
		"northup" : __DIR__"fangning",
		"south" : __DIR__"sanhuang",
		"east" : __DIR__"eastway1",
		"west" : __DIR__"westway1",
	]));
	set("objects", ([ 
		__DIR__"npc/zhangmen" : 1,
	]));
	"obj/board/shibi_b"->foo();
	set("valid_startroom", 1);

	setup();
}
void init()
{
	add_action("do_da", "da");
}

int do_da (string arg)
{
	object me = this_player();
	if(me->query("shushan/jianshen_cast")) 
		return notify_fail("���ǽ�ڸ���\n");
	if ((arg != "ǽ" && arg != "wall") || !arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy()) return notify_fail("��æ���أ�\n");
	if((int)me->query_skill("taoism", 1) > 99) {
		message_vision(HIG"$N�ʹ�ǽ�ڣ�$NͻȻ�䲻���ˡ�\n"NOR, me);
		me->move(__DIR__"xianjing");
	}
	else 
		tell_object (me,"�㲻����������\n");
	return 1;
}
