inherit ROOM;
void create()
{
        set("short", "���������");
        set("long", @LONG
����һ��СС����ı����꣬�������������ɲ�Ѱ���������
Ȼ����ϵ���ѵ�һ���ģ����õ��˸���ϡ�١��ϰ�������ֱ��ë��
��ת���Ϳ���ǽ�ϵ�����(zhaopai)��
LONG );
        set("item_desc", ([
                "zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
        ]));
        set("objects", ([
              __DIR__"npc/zujian" : 1,
        ]));
//      set("no_clean_up", 0);
        set("exits", ([
            "south" : __DIR__"shangjie1",
        ]));

        setup();
        replace_program(ROOM);
}

