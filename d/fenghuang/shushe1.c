inherit ROOM;
void create()
{        
set("short", "学生宿舍");        
set("long",@LONG
这是本校学生休息的地方，室中光线柔和，使人更增睡意。
LONG );
       set("exits", ([                 
           "down" : __DIR__"shushe",
         ]));
       set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
       set("no_clean_up", 0);
       setup();       
       replace_program(ROOM);
}

