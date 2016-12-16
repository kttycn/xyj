// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "/d/obj/misc/message.h"

void create()
{
  seteuid(getuid());

  switch (random(14))
  {
    case 0:
      { set_name(HIB "��õ��" NOR, ({ "flower"})); break; }
    case 1:
      { set_name(HIB "��������" NOR, ({ "flower"})); break; }
    case 2:
      { set_name(HIB "��ѩ��" NOR, ({ "flower"})); break; }
    case 3:
      { set_name(HIB "Ұ������" NOR, ({ "flower"})); break; }
    case 4:
      { set_name(HIB "���¶" NOR, ({ "flower"})); break; }
    case 5:
      { set_name(HIB "˯ܽ��" NOR, ({ "flower"})); break; }
    case 6:
      { set_name(HIB "��Ǿޱ" NOR, ({ "flower"})); break; }
    case 7:
      { set_name(HIB "������" NOR, ({ "flower"})); break; }
    case 8:
      { set_name(HIB "������" NOR, ({ "flower"})); break; }
    case 9:
      { set_name(HIB "��õ��" NOR, ({ "flower"})); break; }
    case 10:
      { set_name(HIB "�����" NOR, ({ "flower"})); break; }
    case 11:
      { set_name(HIB "ѩ��÷" NOR, ({ "flower"})); break; }
    case 12:
      { set_name(HIB "������" NOR, ({ "flower"})); break; }
    case 13:
      { set_name(HIB "˯��" NOR, ({ "flower"})); break; }
  }
  set_weight(100);
  set("long","һ��ɫ��������"+query("name")+"��\n");
  set("unit", "��");
  set("value", 50000);
  set("not_flower", 1);
  set("no_sell", 1);
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_wear", "dai");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  call_out("del_flower", 100+random(20), environment(this_object()));
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N����һ��"+name+"��������������ʱ�����������ˡ�\n"; break; }
    case 1:
      { msg = "$N����"+name+"����Ĭ�����������������̡�\n"; break; }
    case 2:
      { msg = "$N����"+name+"���ڷ��ʣ����һЦ��\n"; break; }
    case 3:
      { msg = "$N��һ��"+name+"������ǰ������ס�������¡�\n"; break; }
    case 4:
      { msg = "$N��"+name+"������ǰ���Ǹ���Ϥ�������ѿڶ�����\n"; break; }
    case 5:
      { msg = "$N��"+name+"������ǰ�����ﲻ��һ�ȡ�\n"; break; }
    case 6:
      { msg = "$N��"+name+"�������������һ�ǣ�Ȼ�������ǰ��\n"; break; }
    case 7:
      { msg = "$NС�ĵذ�"+name+"���ڷ����ϡ�\n"; break; }
    case 8:
      { msg = "$N����������һ˦����"+name+"�������档\n"; break; }
  }
  //message_vision (msg,me);
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  msg = "$N��"+name+"�����ժ��������\n"; 
  //message_vision (msg,me);
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower")
    return 0;

  switch (random(9))
  {
    case 0:
      { msg = "$N������"+name+"���������Ǻ���Ϥ������ζ��\n"; break; }
    case 1:
      { msg = "$N��ͷ����һ��"+name+"��Ť��ͷȥ����һ�������硣\n"; break; }
    case 2:
      { msg = "$N����"+name+"һ�ᣬ��ˮ���ڻ����ϡ�\n"; break; }
    case 3:
      { msg = "$N��һ��"+name+"���ڱ����£��밡�밡����\n"; break; }
    case 4:
      { msg = "$N����"+name+"����һ�£�������Ϧ�Ǻ�Ϧ��\n"; break; }
    case 5:
      { msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; break; }
    case 6:
      { msg = "$N������"+name+"����һ�ţ�˼�������細���ϸ�ꡣ\n"; break; }
    case 7:
      { msg = "$N������"+name+"���ճյ����Ŵ���Ʈ����С�ꡣ\n"; break; }
    case 8:
      { msg = "$N��"+name+"����һ�ᣬ����������������ĺδ�����\n"; break; }
  }
  message_vision (msg,me);
  return 1;
}

void del_flower(object who)
{
    object seed = new("/d/obj/misc/seed");
    message_vision("$Nӭ�ŷ磬���ڿ�ή�ˡ�\n", this_object());
    destruct(this_object());
    seed->move(who);
}

