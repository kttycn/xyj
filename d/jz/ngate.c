//Cracked by Roath
inherit ROOM;
void create ()
{
        set ("short", "���ݳǱ���");
        set ("long", @LONG

    ����ǽ��ݳǵı����ˣ�����ط����𳤰��ǿ����ǲ�Զ�ˡ�
 һ�����������Կ���·���������ʵļ������ˣ�������ſ�����
Ҳ�ܾ��ˡ�������һ�������С·�����飺

                [1;32m������������������������
                ��                    ��
                ��    [2;37;0m[35m��        ��[2;37;0m[1;32m    ��
                ��                    ��
                ������������������������[2;37;0m
LONG);

        set("exits",
        ([ //sizeof() == 4
                "north" : __DIR__"road",
                "south" : __DIR__"xiaowu-2",
      ]));
        set("objects",
([ //sizeof() == 1
           "/d/city/npc/wujiang" : 1,
        ]));
        set("outdoors", "jiangzhou");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
