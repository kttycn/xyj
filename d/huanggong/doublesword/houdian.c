// by snowcat
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG


�˵�ׯ�����£�ǽ�ϻ��н���Ϸ�飬��ϻ�����ɫ���ƣ��������ʡ�
��������̽����ͻȻ���ֶ�ǽ��(east wall)���ƺ���Щ���⡣


LONG);
  set("exits", ([ 
    "south" : "/d/huanggong/dadian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  set("item_desc", ([
                "east wall": "�����̽������ǽ�ϻ��н���Ϸ�飬����ȴ�ƺ���һ����Ŧ(button)��
�����в���һ����                \n",
                "button": "��ĥ���˰�Ŧ(button)�������ƺ�������ת(turn)��\n",
       	]));
  
  
  
  setup();
}

void init()


{
        add_action("do_turn","turn");
 }

int do_turn(string arg)
{
        object me = this_player();

        if( !arg || arg != "button" )
                return notify_fail("��Ҫ��תʲô��\n");

        if( !(me->query_temp("ask_ziying") == "laojun2"))
                return notify_fail("�����ŰѰ�Ŧת����ת������Ŧ��˿������\n");

//        set("exits/south", "/d/update/stone/d/mishi");
        message_vision(HIC"$N����ذѰ�Ŧת�˼�ת��ֻ������һ��! һ�����ŷ�����$N���һ����������ȥ��\n"NOR,me);
        me->move(__DIR__"anshi");
        message("vision", "һ����紵����������ͻȻ����һ���ˡ�\n", me);
//        remove_call_out("close");
//        call_out("close", 3, me);
        return 1;
}
/*void close()
{
	object room = load_object("/d/update/stone/d/mishi");
        message("vision","��Ȼǽ�Զ��ĺ�£�ˡ�\n", room);
        room->delete("exits/south");
}*/