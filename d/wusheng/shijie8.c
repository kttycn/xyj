// changan wusheng
// shijie8.c

inherit ROOM;

void create()
{
  set ("short", "ʯ��");
  set ("long", @LONG

�����ߵ���ͷ�ˣ�վ���ͱڵ��¶������о������Ȼ���ͱ��»�
��һ�ô���(tree)��һ�����˾�������Ъ����
LONG);
set("item_desc", ([ /* sizeof() == 1 */
       "tree" : "һ������������������ƣ���֪����ʲôƷ�֣����ϻ������˹���\n",
]));
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"xuanya0",
"southdown": __DIR__"shijie7",
]));
        set("no_clean_up", 0);
        set("outdoors", "wusheng");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
	object me;
        me=this_player();

        if ( !arg || ((arg != "tree") ))
                return notify_fail("��Ҫҡʲô��\n");
        else
                message_vision("$N���˸�������ס�������ɣ�����Ӱ��������ȥ��\n",me);
                me->move("/d/wusheng/uptree");
		me->receive_damage("kee", 20);
		tell_room( environment(me), "��Ҷ���˼��£�һ��������������\n", ({me}));

                return 1;
}


