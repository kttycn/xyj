//EDIT BY LUCAS
inherit ROOM;
int do_yell(string arg);

void create ()
{
  set ("short", "�Ӱ�");
  set ("long", @LONG
վ�����Ͻ�ˮ�ߣ�Զ���ޱ���ˮ������ν��������˹�򣬲���
��ҹ�����������꣬Ҳ������Ͻ�ˮ������������������Զ��
���߲�Զ��ͣ��ͣ��һ��С������������Ž�(yell)һ�¡�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"hean2",
]));

        set("outdoors", "heishui");

  setup();
}

void init()
{
        add_action("do_yell","yell");
}

int do_yell(string arg)
{
        object me=this_player();

        if( !arg || arg != "boat" ) {
                return notify_fail("��Ҫ��ʲô����?\n");
        }

        message_vision("$N���˿��������һ�������ҡ���\n",this_player());
        message_vision("����С������Ʈ�˹��������һ���������ˡ�\n", this_player());
        set("exits/enter", __DIR__"boat");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision","��ˮ�Ĵ�С����С����������Ʈ���ˡ�\n", room);
        room->delete("exits/enter");
}


