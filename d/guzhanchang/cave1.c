// Room: /d/qujing/wudidong/book_cave1
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
//    object *inv, container;
//    int sizeinv;

    if (dir == "northwest")
	me->delete_temp("guzhanchang/gave_guard_corpse");
    if (dir != "southeast")
	return ::valid_leave(me, dir);
    if (dir == "southeast"
     && objectp(guard=present("shi gui", here)))
    {
	if (me->query("guzhanchang/last_entered_lukou") + 3600 > time())
	{
		message_vision(CYN"ʳʬ���ܺܵ��������������ʣ���������������û�ꣿ������Ǹ������Ҫ��֪���ˣ�����Բ��˶����ߣ�\n"NOR, me);
		return notify_fail("");
	}
/*	inv=all_inventory(me);
	sizeinv=sizeof(inv);
	while (sizeinv--)
	{
	    if (userp(inv[sizeinv]))
	    {
		container=inv[sizeinv];
		break;
	    }
	    if (inv[sizeinv]->is_container())
	    {
		container=inv[sizeinv];
		break;
	    }
	    continue;
	}
	if (container)
	{
	    message_vision(CYN"ʳʬ��������˵�����������"+container->name()+
			   CYN"��ȥ��ʲô����������ë���󿴼�����ô�죡��\n"NOR,me);
	    return notify_fail("");
	}*/
    }

    if (objectp(guard=present("shi gui", here)))
    {
	if (me->query_temp("guzhanchang/gave_guard_corpse"));
	{
	    message_vision(CYN"ʳʬ��������˵������������Ҫ�Ǹ��Ƕ���������˾������ˣ�\n"NOR, me);
	    me->set("guzhanchang/last_entered_lukou", time());
	    return ::valid_leave(me, dir);
	}
	message_vision(CYN "ʳʬ���Ц����ʲ����ܣ�û�ţ�\n"NOR, me);
	return notify_fail("");
    }

    message_vision("�������ֳ�һ����Ӱ�����������˳�������ס������ĳ��ڡ�\n", me);
    guard = new(__DIR__"npc/shigui");
    guard->move(here);
    return notify_fail("�㲻��ͣ���˽Ų�......");

}
