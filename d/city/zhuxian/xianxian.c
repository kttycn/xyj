inherit ROOM;                                                        

void create ()
{
  set ("short", "������" );   

    set("exits", ([ 
               "northwest" : __DIR__"hongshui",
                  ]));
    set("objects", ([ 
               __DIR__"npc/fengshen" : 1,
                  ]));
    setup();
}
