// /d/guzhanchang/lukouside.c
//stone 

inherit ROOM;

void create ()
{
  set ("short", "谷底小径");
  set ("long", @LONG

一条荒凉的小路，地上满是厚厚的黄土，路旁没有一颗草花树木。
一阵阵风吹过，卷起一道道的尘土。两边是天然形成的岩壁，壁
上光秃秃的，像是被刀削斧砍过似的，看来即便是猿猴，也难攀
而上。北面是一条小道。东南边是古战场的遗址。

LONG);

  set("exits", ([
             "north": __DIR__"lukou0",
             "southeast": __DIR__"lukou-1",
      ]));

//  set("objects", ([
//      ]));
  replace_program(ROOM);

  setup();
}


