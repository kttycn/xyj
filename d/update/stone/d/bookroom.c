//u/stone/d/bookroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","ʯͷ�Ĳ��鷿");
	set ("long", @LONG
	
������ʦʯͷ�Ĳ��鷿��ֻ�����ܶ���һ���ż��ض���ĵĴ���ܣ�
����Ҳ��һ�Ѷѵ���δ���������ܵ��鼮���ǵ䡢��������־��
��ǽ���ϻ�����һ��С���ӣ���ǽ����һ����齣��������ǳ�����
ʯͷ�������ⲩ��Ⱥ�顣ǽ�Ϲ���һ�Զ�����duilian)��

������ʯͷ�ĸ߼������ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"northeast" : __DIR__"chufang",
//		"up": "__DIR__guestroom",
		"west": "/d/update/stone/d/stoneroom",
		
	]));
	 set("item_desc",([
                          "duilian" : HIR "
              ��                ��   
              ��                ��
              ��                ��
              Ϊ		��
              ��		�� \n\n\n "NOR,
              
        ]));
         set("objects", ([ 
		"/d/update/stone/obj/desk" : 1,  
	 ]));

	setup();
}

void init()


{
        add_action("do_push","knock");
 }

int do_push(string arg)
{
        object me = this_player();

        if( !arg || arg != "wall" )
                return notify_fail("��Ҫ��ʲô��\n");

//        if( me->query("obstacle/hf") == "done" )
//                return notify_fail("�����˰����ǽ��Ҳû�з���ʲô��\n");

        set("exits/south", "/d/update/stone/d/mishi");
        message_vision(HIC"$N������ǽ��һ�ã���Ȼǽ��һ���ƶ������ﾹȻ����һ�����䡣\n"NOR,me);
        remove_call_out("close");
        call_out("close", 3, me);
        return 1;
}
void close()
{
        object room = load_object("/d/update/stone/d/bookroom");
        message("vision","��Ȼǽ�Զ��ĺ�£�ˡ�\n", room);
        room->delete("exits/south");
}
