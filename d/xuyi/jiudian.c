// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "酒馆");
  set ("long", @LONG
 
这是滨城唯一的一家酒店，位于市中心的旁边，四周来来往往的人都喜欢
到这里喝一杯。这里最出名的还是老板家酿的黄酒，常常可以看到些乡人
在这里畅饮。
LONG);
  set("no_clean_up", 1);

  set("exits", ([
        "north"   : __DIR__"jiedao1",
      ]));
  set("objects", ([
         __DIR__"npc/jiubao"   : 1,
      ]));

  set("resource", ([
   "water": 1
   ]) );


  setup();
   replace_program(ROOM);
}
 

