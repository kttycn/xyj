inherit ROOM;
void create()
{
        set("short", "ÔÓ»õÆÌ");
        set("long", @LONG
ÕâÊÇÒ»¼äÔÓ»õÆÌ£¬ÂôÒ»Ğ©ÈÕ³£ÓÃÆ·¡£
ÊÇĞÇÏµÖĞ³£¼ûµÄµêÆÌ¡£ÀÏ°åÊÇÒ»¸öºÜºÍÉÆµÄÈË¡££
×ó±ßÇ½ÉÏÓĞÒ»¸öÕĞÅÆ(zhaopai)¡£
LONG );
        set("item_desc", ([
                "zhaopai": "ÇëÓÃ \"list\" ÁĞ³ö»õÎï±í£¬\"buy\" ÏòÀÏ°å¹ºÎï¡£\n",
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


