// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
  set_name(HIR"��ȸ����" NOR, ({"xuanwu pifeng", "pifeng","surcoat"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", HIR"һ�����Ϸ�ʥ����ȸ֮�������Ƶ����磬���������\n"NOR);
    set("material", "leather");
    set("unit", "��");
    set("value", 0);
    set("no_sell", "��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
    set("no_put", "����ȸ����װ����������ȥ��\n");
    set("no_drop", "��ôϡ������ı���ʥ�£����˶��ϧѽ��\n");
    set("no_give", "����Ǳ���ʥ�°������������ˣ�\n");
    set("no_get", HIR"���������ȸ���磬ͻȻ�������ֳ���ɫ���Ϸ�ʥ����ȸ��������צ���㲻�ɵ�ս�ľ���\n"NOR);
    set("armor_prop/armor", 100);//�ο���������60
  }
  set("is_monitored",1);
  setup();
}


