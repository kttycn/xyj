// by lpg 19991105 for ĳЩ�����������ӵ���

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

string *names = ({
  "����ҩ",
  "���������",
  "�������ǵ�",
  "������",
  "��",
  "����ˬ��",
});

void create()
{
  set_name("����ҩƷ", ({"biyun yao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һС��ҩ��\n");
    set("unit", "��");
    set("value", 10000);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
  }
}

void init()
{
  add_action ("do_eat", "eat");
  if (query("name")=="����ҩƷ")
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
  message_vision(HIY "$N����һ��"+me->query("name")+"������У�ת˲�����ߺ�...\n" NOR, who);
  destruct(this_object());
  return 1;
  }
}
void become_bad (object me)
{
  set_name("���ʵĻ�ҩ", ({"huai yao"}));
  me->set_temp("is_ready",0);
  me->set("value", 0);
}
