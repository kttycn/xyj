//Cracked by Roath
inherit ROOM;
void create ()
{
        set ("short", "江州城北门");
        set ("long", @LONG

    这便是江州城的北门了，这个地方比起长安城可真是差远了。
 一眼南望，可以看到路上疏疏朗朗的几个行人，这个城门看起来
也很旧了。向北走是一条不宽的小路。上书：

                [1;32m※※※※※※※※※※※※
                ※                    ※
                ※    [2;37;0m[35m江        州[2;37;0m[1;32m    ※
                ※                    ※
                ※※※※※※※※※※※※[2;37;0m
LONG);

        set("exits",
        ([ //sizeof() == 4
                "north" : __DIR__"road",
                "south" : __DIR__"xiaowu-2",
      ]));
        set("objects",
([ //sizeof() == 1
           "/d/city/npc/wujiang" : 1,
        ]));
        set("outdoors", "jiangzhou");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
