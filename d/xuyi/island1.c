// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "���Ĳ��޺���");
  set ("long", @LONG

����������Ĳ��޵ĺ�������ɫ��ɳ̲���������������⣬������ѩ����
�ź������кܶ����ι�״�Ľ�ʯ������һ��һ�����˹������ڽ�ʯ�ϻ���
���飬������������������������Х�Ŵ����������˵������������졣
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"island",
]));

  setup();
}

void init()
{
        add_action("do_dive", "dive"); 
}


int do_dive()
{
       object me;
        me=this_player();
            if((!present("bishui zhou", me)) &&
       (!((string)me->query("family/family_name")=="��������")))
                return
notify_fail("��һ����������ˮ�����\n\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");
                message_vision("$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n", me);
                me->move("/d/xuyi/sea");
     message_vision("$N���˹�����\n", me);
                return 1;
}


