// by lpg 19991105 for 某些结婚后不想生孩子的人

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

string *names = ({
  "避孕药",
  "郎情妾意丸",
  "共枕无忧丹",
  "赛仙丸",
  "快活丹",
  "滋身爽神丹",
});

void create()
{
  set_name("避孕药品", ({"biyun yao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一小包药。\n");
    set("unit", "包");
    set("value", 10000);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
}

void init()
{
  add_action ("do_eat", "eat");
  if (query("name")=="避孕药品")
  {
    set_name(names[random(sizeof(names))], ({"biyun yao"}));
    call_out ("become_bad",600,this_object());
  }
  ::init();
}

int do_eat (string arg)
{
  object me = this_object();
  object who = this_player();
  if (arg=="biyun yao"){
  who->set_temp("safe_baby",1);
  message_vision(HIY "$N掰开一粒"+me->query("name")+"含入口中，转瞬满面羞红...\n" NOR, who);
  destruct(this_object());
  return 1;
  }
}
void become_bad (object me)
{
  set_name("变质的坏药", ({"huai yao"}));
  me->set_temp("is_ready",0);
  me->set("value", 0);
}
