inherit ROOM;                                                        

void create ()
{
  set ("short", "ощоице" );   

    set("exits", ([ 
               "northwest" : __DIR__"hongshui",
                  ]));
    set("objects", ([ 
               __DIR__"npc/fengshen" : 1,
                  ]));
    setup();
}
