inherit ROOM;                                                        

void create ()
{
  set ("short", "¾����" );   

    set("exits", ([ 
               "northeast" : __DIR__"tianjue",
                  ]));
    set("objects", ([ 
                __DIR__"npc/huoshen" : 1,
                  ]));
    setup();
}
