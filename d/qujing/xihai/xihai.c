#include <ansi.h>
inherit ROOM;
int do_dive();

void create ()
{
        set ("short", "����֮��");
        set ("long", @LONG

������һ���޼ʵ�ѩԭ��Ρ����ΰ�ı�ɽ��ͻȻ��̲����꣬��
�׳����ˮ��չ������ǰ�����ʱ����һ����������ӿ����ͷ��
ɽ�������ݣ��񣬷·��ǵ�����һ�����磬һƬƬ���˲�ͣ��
���Ϻ�̲�������������Ǹ�����(dive)�ĺ�ȥ����
LONG);

       set("exits", 
        ([ //sizeof() == 4
                "east" : "/d/xueshan/xueshan5", 
                "north" : __DIR__"haitan4",
                "east" : "/d/lingtai/lantao2",
        ]));

        set("outdoors", "xihai");
        setup();
}

void init()
{
    add_action("do_dive", "dive");
}

int do_dive()
{       object me, zhou;
        me=this_player();



            if(( !(zhou=present("bishui zhou", me))
                ||(string)zhou->query("unit")!="��")
                && (string)me->query("family/family_name")!="����"
                && (string)me->query("family/family_name")!="��������")

                return notify_fail("��һ����������ˮ�����\n"+
                  "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");


                message_vision(HIG "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, me);
                me->move("/d/qujing/xihai/haidi1");
                message_vision("$N�������ݣ�Ǳ�˹�����\n",me);
                return 1;
}


