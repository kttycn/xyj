inherit ROOM;
#include <ansi.h>
void create()
{
         set("short",HIR"雾灵谷"NOR);
         set("long",@LONG
这里就是凤凰星上最令人恐怖的地方--雾灵谷，这里的气候很适合怪兽
生存，所以在雾灵谷里面聚集了许许多多各种各样的怪兽，形态各异，
更令人恐怖的是由于雾灵谷的气候十分特殊，因此生存在这里的怪兽
个头都往往是野外怪兽的两倍甚至几倍，一般人是不敢来这儿的，就连
凤凰的大统领也要惧怕三分。
LONG);
        set("exits",([
                  "west" : __DIR__"pingyuan5",
                    ]));
      setup();
}
void init()
{
  add_action("do_climb","climb");
}
int do_climb(string arg)
{
     object room;
      object me;
     me = this_player();

   if (me->query("combat_exp") < 300000)
  return notify_fail("就你这点本事也想进雾灵谷？还是回去练几年吧，小命要紧哦！\n");
 if (!arg || arg != "down")
  return notify_fail("你要往哪儿爬？\n");
  if (!(me->query_temp("火龙肝")))
  return notify_fail("你没事来这儿玩？\n");

  me ->move("/d/fenghuang/fenghuang/shangu2");
  message_vision("$N顺着山崖的峭壁爬了下来，但是浓浓的雾气使$N的气息变得十分虚弱。\n",me,room);
  me ->set("neili",1);
  return 1;
}
