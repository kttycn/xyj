// zhentian-arrow.c �����

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("�����", ({ "zhentian jian", "arrow", "jian", "zhentian", "zhentian jian", }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","��������Ǻ��൱����������֮������\n");
    set("unit", "��");
	set("rigidity", 9);
    set("base_unit", "֦");
    set("base_weight", 400);
    set("base_value", 500);
  }
  set_amount(50);
  init_archery(80);
  setup();
}

