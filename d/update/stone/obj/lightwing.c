// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"��֮��" NOR, ({"light wing", "guang zhiyi","surcoat","wing"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", HIW"һ���������ǹ����������ǹ�������\n"NOR);
    set("material", "leather");
    set("unit", "��");
    set("value", 0);
    set("wear_msg", "ϼ�����ɣ�$N�ı����ֳ�һ����Ƕ�������ǳ���â�Ĺ�֮����$N�����գ���ӯ�÷������\n");
    set("unequip_msg", "$N΢΢һЦ�����ϵ�$n��â����������$n��ʧ�ˡ�\n");
//    һ���ݷ���Ƕ�������ǳ���â�Ĺ�֮����
    set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    set("no_put", "���֮��װ����������ȥ��\n");
    set("no_drop", "��ôϡ������ı���ʥ�£����˶��ϧѽ��\n");
//    set("no_give", "����Ǳ���ʥ�°������������ˣ�\n");
    set("no_get", HIR"���������֮��$n����ҫ�۶�Ŀ����ʯ�ǳ���â��\n"NOR);
    set("armor_prop/armor", 100);//�ο���������60
    set("armor_prop/dodge", 200);
  }
  set("is_monitored",1);
  setup();
}


