inherit ROOM;                                                        

void create ()
{
  set ("short", "б╬оице" );   

    set("exits", ([ 
               "northeast" : __DIR__"tianjue",
                  ]));
    set("objects", ([ 
                __DIR__"npc/huoshen" : 1,
                  ]));
    setup();
}
