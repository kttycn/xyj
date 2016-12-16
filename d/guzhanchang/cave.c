//stone 20020613
// /d/guzhanchang/cave.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

这儿是一个黑洞洞的泥穴，地上很干燥，覆盖着干硬的泥土，随处
可见一堆堆的白骨。在洞的角落盘居着一堆暗红色的阴影，不知道
是什么东西。中间的空地上长着一株碧绿翡翠的嫩草(longcao)。
LONG);
  set("item_desc", ([GRN"longcao" : "一株碧绿发亮的嫩草，经蛟龙唾涎灌溉而生，具有固本培元之疗效。\n"NOR ]));
  set("exits", ([
        "out": __DIR__"dongkou",
        "up": __DIR__"shuitan",
        ]));
  set("objects", ([
        __DIR__"npc/dragon":1,
        __DIR__"obj/skull" : 1,
        ]));
  set("no_lingzhi", 0);
  
  setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{

   object ob, me;
   
   me=this_player();

   if( (!arg) || (arg != "long cao" && arg != "longcao" && arg !="龙涎草") )
     return notify_fail("你要挖什么？\n");

        if (objectp(present("chi jiao", environment(me))))
        return notify_fail(RED"千年赤蛟向你怒目而视，张牙舞爪。\n"NOR);

   if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword"  && (string)ob->query("skill_type")!="halberd" &&
     (string)ob->query("skill_type")!="halberd") ) 

     return notify_fail("得找个好工具吧。\n");

   if (query("no_lingzhi"))
     return notify_fail("你来迟一步，龙涎草已被人采走了！\n");


   ob=new("/d/guzhanchang/obj/longcao");
           ob->move(me);
   message_vision("$N挖出一颗"+HIG"龙涎草"NOR+"，小心翼翼地纳入怀里。\n", me);
   set("no_longcao", 1);
   call_out("regenerate", 6000);
   return 1;
}

int regenerate()
{
   set("no_longcao", 0);
   return 1;
}