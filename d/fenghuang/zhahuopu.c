inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
����һ���ӻ��̣���һЩ�ճ���Ʒ��
����ϵ�г����ĵ��̡��ϰ���һ���ܺ��Ƶ��ˡ��
���ǽ����һ������(zhaopai)��
LONG );
        set("item_desc", ([
                "zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
        ]));
        set("objects", ([
                __DIR__"npc/jiaxin" : 1,
        ]));
//      set("no_clean_up", 0);
        set("exits", ([
            "north" : __DIR__"shangjie1",
        ]));

        setup();
        replace_program(ROOM);
}


