// /d/guzhanchang/lukou-1.c
// created 9-15-97 pickle

/************************************************************/
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);

/************************************************************/
void create ()
{
        set("short", "·��");
        set("long", @LONG
        
������ǹ�ս����ַ������ˣ���˵����й����û��û��һ��
�����Ǳ�ȥ�ĺá�
LONG );

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lukouside1",
  "southeast" : __DIR__"lukou",
]));

  setup();
}

/************************************************************/
int valid_leave(object me, string dir)
{
    object guard, here=this_object();

    if (dir == "northwest")
	me->delete_temp("guzhanchang/gave_guard_corpse");
    if (dir != "southeast")
	return ::valid_leave(me, dir);
    if (dir == "southeast"
     && objectp(guard=present("shi gui", here)))
    {
//	if (me->query("guzhanchang/last_entered_lukou") + 3600 > time())
//	{
		message_vision(CYN"ʳʬ���ܺܵ��������������ʣ���������������û�ꣿ\n������Ǹ������Ҫ��֪���ˣ�����Բ��˶����ߣ�\n"NOR, me);
		return ::valid_leave(me, dir);
//		return notify_fail("");
//	}

    }

    if (objectp(guard=present("shi gui", here)))
    {
	if (me->query_temp("guzhanchang/gave_guard_corpse"));
	{
	    message_vision(CYN"ʳʬ��������˵������������Ҫ�Ǹ��Ƕ���������˾������ˣ�\n"NOR, me);
	    me->delete_temp("guzhanchang/gave_guard_corpse");
//	    me->set("guzhanchang/last_entered_lukou", time());
	    return ::valid_leave(me, dir);
	}
	message_vision(CYN "ʳʬ���Ц����ʲ����ܣ�û�ţ�\n"NOR, me);
	return notify_fail("û�кö���Т���ң��������\n\n");
    }

    message_vision("�������ֳ�һ����Ӱ�����������˳�������ס������ĳ��ڡ�\n", me);
    guard = new(__DIR__"npc/shigui");
    guard->move(here);
    return notify_fail("�㲻��ͣ���˽Ų�......\n\n", me);

}
