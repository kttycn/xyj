//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

一路上，远远都是大小山峦，低洼处是一片湿湿的沼泽地带，看
不见人间烟火。走在山路上静悄悄，雾气浓郁。
LONG);

  set("exits", ([
        "east"  : __DIR__"road4",
        "westup"  : __DIR__"shanlu1",
      ]));
  set("outdoors","huangfeng");
  setup();
}
