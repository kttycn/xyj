// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
//By tianlin@Mhxy for 2002.1.27.���������

// lingzhi.c ��֥
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(MAG "��֥��" NOR, ({"lingzhi","ling zhi"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "ǳ��ɫ��һ����֥�ݣ�ɢ�������˵���Ϣ��\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  if (me->query("tianlin-lingzhi") >=1 )
    return notify_fail("�ٺٺٱ������ˣ�\n");

  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N����һ��"+MAG"��֥��"+HIG"���е�ȫ������˻����� \n" NOR, me);
  me->add("tianlin-lingzhi",1);
  destruct(this_object());
  return 1;
}


