// /d/guzhanchang/lukou0.c
//stone 

inherit ROOM;

void create ()
{
  set ("short", "谷底");
  set ("long", @LONG

此处是一块平坦的空地。两面陡壁，壁上寸草不生，你仰天而望，
危峰刺天，立壁如刃，即便是飞鸟，也难飞越。云雾弥漫着山谷，
绝峰危棱之间，白云飘渺。南边是一条小路。西边是一个深水潭。

LONG);

  set("exits", ([
             "west": __DIR__"pondside",
             "south": __DIR__"lukouside",
      ]));

//  set("objects", ([
//      ]));
  replace_program(ROOM);
  setup();
}


