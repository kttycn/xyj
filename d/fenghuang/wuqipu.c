inherit ROOM;
void create()
{
        set("short", "凤凰武器店");
        set("long", @LONG
这是一家小小店面的兵器店，可是卖的武器可不寻常。种类固
然是星系中难得一见的，能用的人更是稀少。老板的眼瞟得你直发毛。
你转脸就看到墙上的招牌(zhaopai)。
LONG );
        set("item_desc", ([
                "zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向老板购物。\n",
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

