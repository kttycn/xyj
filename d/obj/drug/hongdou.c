// hongdou.c �춹
// create by cnd
#include <ansi.h>

inherit ITEM;

void destroy();
int do_kiss(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
		set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
		set("no_give","��ô���Ķ��ӣ����������ˣ�\n");
		set("no_drop","��ô�İ��Ķ��������˶��ϧѽ��\n");
		set("no_sell","����֮������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
	}                                    
	add_action("do_kiss", "kiss");
	call_out("destroy", 180);
}

void create()
{
  set_name(HIR "�춹" NOR, ({"hong dou","hongdou","dou"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�������Ϲ�����˼���������������䰮������,�㲻��������һ�¡�\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_kiss(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ����ʲô��\n");
  
  me->add_maximum_force(10);
  me->add_maximum_mana(10);
  message_vision(HIR "$N����һ����˼�춹����˼�춹����ҫ�۹�â��$N�������������� \n" NOR, me);
  
  destruct(this_object());
  return 1;
}

void destroy()
{
	destruct(this_object());
}