inherit ROOM;                                                        

void create ()
{
  set ("short", "╬Ьоице" );   

    set("exits", ([ 
               "southeast" : __DIR__"jinguang",
                  ]));
    set("objects", ([ 
               __DIR__"npc/shuishen" : 1,
                  ]));
    setup();
}
