// tian3.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "�������졤�ն���");
  set ("long", @LONG

                         s________________s         
                        /LLLLLLLLLLLLLLLLLL\        
    []__[]             ^^||======||======||^^             []__[]
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_��[1;36m������[0m��__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|����������_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|__/       \__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__||        | |_|__||__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__��������_|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|��������|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
                    ����Ⱦ���岻��  �նɻ�ͷ�Ĳ���
������ǵ������졤�ն��졤
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"midong3",
  "south" : __DIR__"road3",

])); 
 set("objects", ([
             __DIR__"npc/tianjiang" : 2,
        ]));
        set("no_clean_up", 0);

        setup();

}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me=this_player();
        
        if( !arg || (arg!="sky" && arg!="��") )
                return notify_fail("��Ҫ��ʲô��\n");
        if(me->is_busy())
                return notify_fail("���æ����ʲôѽ��\n");

        message_vision("$N���˴��֣�˳����·������... \n", me);
        me->start_busy(3);

        if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=100 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 3, me);
        return 1;
}
int success(object me)
{
        message_vision("$NԽ��Խ�ߣ��������������� ... \n", me);
        me->move("/d/guzhanchang/road4");
        me->receive_damage("kee", 400);
        me->receive_damage("sen", 400);
        message_vision("$N����������������\n", me);
        return 1;
}
int faila(object me)
{

        tell_object(me, "������һ�����ȣ������е������� ... \n");
        tell_room(environment(me), me->name()+"�����ƵĴ����е���������\n", ({me, me}));
        
me->unconcious();
        return 1;
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("tianjiang", environment(me))) && living(a) )
                return notify_fail("�콫����Ը�����ȥ��\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

