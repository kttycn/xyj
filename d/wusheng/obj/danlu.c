// danlu.c �Žŵ�¯

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIW"�Žŵ�¯"NOR, ({ "jiujiao danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ����ʥ������ʢ�ɵ���ҩ�ľŽŵ�¯��\n");
    set("value", 2000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  remove_call_out ("smoking");
  if(userp(this_player())) {
  call_out ("smoking",3+random(3),this_object());
  add_action ("do_enter", "penetrate");
  add_action ("do_enter", "enter");
  add_action ("do_enter", "fly");
  add_action ("do_enter", "dive");
  add_action ("do_enter", "teleport");
  add_action ("do_enter", "jump");
  add_action ("do_enter", "plunge");
  }
}

int do_enter (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$NǱ������¯��һԾ������������$N����һ�������ˡ�\n",who);
  who->move("/d/wusheng/indanlu");
  who->start_busy(1);
  message_vision ("$N������һ���ӵ�¯��Ʈ�˹�����\n",who);
  if (who->query("combat_exp") < 5000)
      who->unconcious();
  return 1;
}

void smoking (object me)
{
  object where = environment (me);
  tell_room (where,"ͭ��¯ð�����������̡�\n");
}
