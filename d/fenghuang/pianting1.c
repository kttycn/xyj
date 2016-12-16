#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","Æ«Ìü");
        set("long",@LONG
ÕâÕâÀïÊÇ×ÚÖ÷¸®µÄÆ«Ìü£¬µØÉÏÆÌ×ÅºìÉ«µÄµØÌº£¬Á½±ßÕ¾×Å
¼¸¸öÃÀÀöµÄÅ®º¢×Ó£¬ÕıĞ¦Ó¯Ó¯µÄ¿´×ÅÄã¡££
LONG);
        set("objects", ([
           __DIR__"npc/shinv": 4,
        ]));
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang5",
            "west"  : __DIR__"zhengting",
        ]));
        setup();
        replace_program(ROOM);
}

