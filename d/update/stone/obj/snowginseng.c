//snowqinseng.c
//stone
//20020221

#include <ansi.h>
#include <dbase.h>
//#include "message.h"
inherit ITEM;

int do_eat(string);
int do_smell(string);
int do_water(string);
int do_fix(string);
void destroy();
void init();

int init ()
{
  if(this_player()==environment())
  add_action ("do_eat", "eat");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  add_action ("do_water", "water");
  add_action ("do_fix", "fix");
  call_out("need_water", 10+random(10), environment(this_object()));
  return 1;
}

void create()
{
	set_name(HIW"ǧ��ѩ��"NOR, ({HIW"xue shen"NOR,"xueshen","snowshen"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIW"����һ��ͨ��ѩ�ף���Ө��͸��ǧ��ѩ�Ρ�һ����֪����Ѱ��֮����ױ��档\n"NOR);
		set("value", 900000);
		set("drug_type", "��Ʒ");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	string type;
	object me = this_player();
	if(me->is_fighting())
		return notify_fail("�������ٳ԰ɣ�\n");
	if(me->is_busy())
		return notify_fail("����æ����!\n");
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if ((string)environment(me)->query("short")=="������" )
		return notify_fail("������ôΣ�ջ���ʲô��������\n");

	me->set("food", (int)me->max_food_capacity());
	me->add_maximum_mana(100);
	me->add_maximum_force(100);
	message_vision("$NС������ذ�ǧ��ѩ��������У������׽���
"HIG"����һ�ɼ���֮���ӵ����𣬶ٸ�ȫ����׹���ߣ��뷢�������Ľ���һ�㱡����˪��\n" NOR, me,);
	me->unconcious();
	destruct(this_object());
	return 1;
}

int do_smell (string arg)
{
  object me = this_player();
  object xueshen = this_object();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xue shen")
    return 0;

  switch (random(3))
  {
    case 0:
      { msg = "$N������"+name+"��һ�����������ķΣ���ʱ������ˬ��\n"NOR; break; }
    case 1:
      { msg = "$N��ͷ����һ��"+name+"��һ��Ũ���Ĳ������������\n"NOR; break; }
    case 2:
      { msg = "$N����"+name+"һ�ᣬ��������һ��\n"NOR; break; }
    }
  message_vision (msg,me);
  return 1;
}

int do_fix (string arg)
{
  object me = this_player();
  object xueshen = this_object();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xue shen")
    return 0;

  msg = "$N��"+name+"С�ĵ���ʪ���˿����á�\n";
  xueshen->set("fixed",1);
  message_vision (msg,me);
  return 1;
}

void need_water (object where)
{
  object xueshen = this_object();
  object who = environment(xueshen);
  string name = xueshen->query("name");
  string msg;
  object xueshengan;

  if (!who || !living(who))
    return;

  if (xueshen->query("fixed"))
    return;

  switch (xueshen->query("water"))
  {
    case 0:
      { msg = "΢�紵����"+name+"�Ĳ�����$N����ǰ����ζ������˵Ļ�����ع�Чһ������ۿ۵İɣ�\n"; break; }
    case 1:
      { msg = name+"�е���ˣ�Ŷ������һ��ˮ�ˡ����˵Ļ�����ع�Чһ������ۿ۵İɣ�\n"; break; }
    case 2:
      { msg = name+"����ɫ���������Щ���ơ����˵Ļ�����ع�Чһ������ۿ۵İɣ�\n"; break; }
    case 3:
      { msg = name+"ԭ���ǰװ����ֵģ����ں��������ȥ�����˵Ļ�����ع�Чһ������ۿ۵İɣ�\n"; break; }
    case 4:
      { msg = name+"���ڸɿ��ˡ�\n"; xueshen->set("name","��"+name); break; }
    default:   //added by mon 8/31/97
      {  
        if(xueshen->query("water")>10 && random(10)==0) {
          message_vision(name+
	  "�ĸ�����Կ�ή����Ҷ�����𣬻�����ƬƬ��Ҷ������\n"+
	  "�ٿ�ʱ��ֻ��һ�����Ƶ�ѩ�θɻ�����$N���ϡ�\n"
	  ,who);
	  xueshengan = new (__DIR__"xueshengan");
          xueshengan->move(who);
          destruct(xueshen);
	  return;
	}
      }
  }
  if(msg)message_vision (msg,who);
  xueshen->set("water",xueshen->query("water")+1);
  call_out ("need_water",random(50)+50,where);
}

int do_water (string arg)
{
  object xueshen = this_object();
  object who = this_player();
  string name = xueshen->query("name");
  string msg;

  if (arg != "xueshen")
    return 0;

  if (xueshen->query("water") >= 5)
  {
    message_vision ("$N����ˮһ�ε�����"+name+"�ϡ�\n",who);
    return 1;
  }

  switch (random(5))
  {
    case 0:
      { msg = "$N�ں���ˮ������"+name+"�Ĳ����ϡ�\n"; break; }
    case 1:
      { msg = "$N��һ����ˮ����"+name+"�ϡ�\n"; break; }
    case 2:
      { msg = "$NС�ĵ�����һ���¶ˮ������"+name+"�Ĳ�Ҷ�ϡ�\n"; break; }
    case 3:
      { msg = "$N�����Ұ������ĳ�¶������"+name+"�ĸ����ϡ�\n";break; }
    case 4:
      { msg = "$N����ָպ����ˮ��һ������"+name+"�ϡ�\n";break; }
  }
  message_vision (msg,who);
  message_vision (name+"������չ¶���˲��룬�ֱ��ѩ�ױ����ˡ�\n",who);
  xueshen->set("water",0);
  return 1;
}
