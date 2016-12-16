// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

#include <ansi.h>

void create ()
{
  set ("short", "���Ĳ��޺���");
  set ("long", @LONG

����������Ĳ��޵ĺ�������ɫ��ɳ̲���������������⣬������ѩ����
Զ����һ����ʯ��·����ͨ��Զ������������Լ����һҶ���ۣ�Boat����
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"island1",
  "north" : __DIR__"path",
  "east" : __DIR__"island2",
]));

  setup();
}

/*
int valid_leave(object me, string dir)
{
   if( (string)me->query("family/family_name")=="����ɽ" ) return 1;
        if( wizardp(me)) return 1;

        if (dir == "west"
   || dir=="east" 
   || dir=="north") {
        if (objectp(present("zhao shenjiang", environment(me))))
        return notify_fail("�������ֵ�ס�����ȥ·������������������\n");
        if (objectp(present("wei shi", environment(me))))
        return notify_fail("������ʿ�������Ҽҽ������ڣ�С�˲��ҷ�����ȥ��\n");
        }   
        return ::valid_leave(me, dir);
}
*/

void init()
{
        add_action("do_yell", "yell"); 
}
 
void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object("/d/changan/duchuan")) )
            room = load_object("/d/changan/duchuan");
        if( room = find_object("/d/changan/duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", "/d/changan/duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����Ϻ�̲���Ա�˿�\n���¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���Ϻ�̲���γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬����������ʻȥ��\n",
        this_object() );

    if( room = find_object("/d/changan/duchuan") )
    {
        room->delete("exits/out");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n������ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object("/d/changan/duchuan") )
    {
        room->set("exits/out", "/d/changan/jiaoshi");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���Ϻ�̲��\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object("/d/changan/duchuan") ) {
        room->delete("exits/out");
        message("vision","������̤�Ű����������ѱ���ʻ�����С�\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return notify_fail("��Ҫߺ��ʲô��\n");

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object("/d/changan/duchuan") )
        room->delete("yell_trigger"); 
}

