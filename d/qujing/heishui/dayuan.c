//EDIT BY LUCAS
inherit ROOM;
int do_open(string arg);

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG 
�����Ǻ�ˮ�����񸮵Ĵ�Ժ������С��������ĥ�����������
��Ϸ���֡�����һ��Ƭ��֫���ȣ���֪�ж��������������
ǰ����һ��Сͤ�����ǲ��õ����ű��¡�
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"buyun",
  "west" : __DIR__"damen", 
  "east" : __DIR__"zoulang6",
  "south" : __DIR__"zoulang1",
]));

        set("objects", ([
                __DIR__"npc/guai" : 4,
        ])); 

        setup();
} 

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me=this_player();

        if( !arg || arg != "gate" ) {
                return notify_fail("��Ҫ��ʲô?\n");
        }

        message_vision("$N�Ѵ��Ŵ򿪡�\n",this_player());
        set("exits/west", __DIR__"damen");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision","С�����ִ��ű����ˣ����һ��������ײײ�ܹ����Ѵ��Ź����ˡ�\n", room);
        room->delete("exits/west");
}

