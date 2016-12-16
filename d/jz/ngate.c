//Cracked by Roath
inherit ROOM;
void create ()
{
        set ("short", "½­Öİ³Ç±±ÃÅ");
        set ("long", @LONG

    Õâ±ãÊÇ½­Öİ³ÇµÄ±±ÃÅÁË£¬Õâ¸öµØ·½±ÈÆğ³¤°²³Ç¿ÉÕæÊÇ²îÔ¶ÁË¡£
 Ò»ÑÛÄÏÍû£¬¿ÉÒÔ¿´µ½Â·ÉÏÊèÊèÀÊÀÊµÄ¼¸¸öĞĞÈË£¬Õâ¸ö³ÇÃÅ¿´ÆğÀ´
Ò²ºÜ¾ÉÁË¡£Ïò±±×ßÊÇÒ»Ìõ²»¿íµÄĞ¡Â·¡£ÉÏÊé£º

                [1;32m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
                ¡ù                    ¡ù
                ¡ù    [2;37;0m[35m½­        Öİ[2;37;0m[1;32m    ¡ù
                ¡ù                    ¡ù
                ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m
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
