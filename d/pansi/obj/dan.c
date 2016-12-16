#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "��ʦ��" NOR, ({"panshi dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", HIC"�����͵�һ�ŵ�ҩ��\n"NOR);
    set("value", 50000000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
        add_action("do_eat", "eat");
        call_out("announce",random(10),this_player());
}


void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "sys",
            who->query("name")+"�õ���"+name()+"��\n");
}

int do_eat(string arg)
{
  object me = this_player();
  string msg; 
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIC"$N����һ����ʦ������ɫ���һƬ�Ұס���ȥ������·�һƬ�հס�����\n"NOR, me);  
  
        me->add("bellicosity", -random( (int)me->query_kar() * 10));
        if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);

        me->delete("family");
        me->delete("class");
        me->set("title", "��ͨ����");
        me->delete("betray");
		me->delete("faith");
		me->delete("family_wp");
        me->save();
        msg="���˿���"+ me->query("name")+ "͵����һ����ʦ����\n";
      CHANNEL_D->do_channel(this_object(),"sys",msg);
  destruct(this_object());
  return 1;
}
