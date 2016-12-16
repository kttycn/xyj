// salehut.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","珍宝斋");
        set("long", @LONG

这里宽敞明亮，古色古香。地上铺着厚厚的手工精细的毛毯。四
壁均挂有名人字画，花鸟人物栩栩如生。楠木桌案上摆放着文房
四宝，无一不是名产，一方古色斑斓的鼎内檀香袅袅环绕，细香
缕缕，沁人心脾，淡淡的香味令人浑身清爽。

LONG);

        set("exits", ([		
                "north" : "/d/wiz/entrance",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1); 

  set("objects", ([ /* sizeof() == 1 */
    "/d/wiz/npc/paimaishi" : 1,
]));
        setup();
}

