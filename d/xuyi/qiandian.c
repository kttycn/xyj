// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "前殿");
  set ("long", @LONG

这里是蠙城皇宫的前殿，红砖绿瓦建得十分精巧，蠙城国主勤政爱民，万
几宸函，都在此殿。往北就到了御花园，往南是皇宫大门。
LONG);

  set("exits", ([
        "north"   : __DIR__"yuhuayuan",
        "south"  : __DIR__"gongmen",
      ]));
  set("objects", ([
        __DIR__"npc/taijian" : 2,
        __DIR__"npc/king" : 1,  
      ]));

  setup();
}

