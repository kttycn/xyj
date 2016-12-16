inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
	set ("short","�ϳǿ�ջ");
	set ("long", @LONG

��ҿ�ջ�������������ģ���������ǳ���¡����֮��Ǯ����������
��������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵��ڴ�
�������������ﲻ�����������õ�С�������ػ��д����ķ����͡���
¥���������������ǿͷ���
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"sleep",
		"west" : __DIR__"zhuque-s1",
		"north" : "/d/city/misc/idleroom",
		"southeast" : __DIR__"tingtang",
		"northeast" : __DIR__"chufang",
		"up": "/d/wiz/entrance",
		"south": "/d/city/chatroom",
	]));
	set("chat_room",1);
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/xiaoer" : 1,
		"/d/ourhome/npc/bigeye" : 1,
		"/d/ourhome/npc/tangseng" : 1,
//                __DIR__"npc/new_fei" : 1,
        ]));

	set("no_time", 1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("freeze",1);
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/nancheng_b", "???");
}
/*
void init()
{
	add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
	string verb;
	verb = query_verb();

// if (verb == "bian") return 1; // by mon 7/15
	if (verb == "xiudao") return 1;
	if (verb == "exert") return 1;
	return 0;
}
*/
int valid_leave(object me, string dir)
{
	object mbox,*inv;
	inv = all_inventory(me);
	if ( sizeof(inv)&& dir == "north" ) return notify_fail("��С����������Ķ���˵����λ�͹٣���������ǰ�뽫���ϵ������ա�\n");

	if ( dir == "east" )
		if (!me->query_temp("rent_paid") )
			return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬺����ǿ��˵��Է������Ǳ���Ŀ��ˣ�������š�\n");
		else if ( me->query("PKS") >= 3)
			return notify_fail("��ɱ��̫�����ң��������ӭ�㣡\n");
	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻�ظ��ʲ\n");
		destruct(mbox);
	}
	return ::valid_leave(me, dir);
}
