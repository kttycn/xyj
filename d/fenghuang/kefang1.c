inherit ROOM;

void create()
{
        set("short", "�ͷ�");
        set("long", @LONG
����һ������ͷ�����·���ӣ����ӵ绰���Ƚ��豸һӦ��ȫ��
LONG );
        set_light(0);
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);
        set("no_clean_up", 0);
        set("exits", ([
                "out" : __DIR__"kedian2",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "out" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}